#include <pthread.h>
#include <string.h>

#include "esp_log.h"
#include "global_state.h"
#include "create_jobs_task.h"
#include "macros.h"
#include "nvs_config.h"
#include "stratum_manager_quad_pool.h"
#include "utils.h"

// Last requested difficulty per pool. Kept at file scope so the connect /
// disconnect callbacks can drop stale values of pools that are no longer
// receiving work.
static uint32_t s_poolDiffs[StratumManager::MAX_POOLS] = {
    0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu};

StratumManagerQuadPool::StratumManagerQuadPool() : StratumManager(PoolMode::QUAD)
{
    for (int i = 0; i < MAX_POOLS; i++) {
        m_weights[i] = Config::getPoolWeight(i);
    }
}

bool StratumManagerQuadPool::isPoolUsable(int pool) const
{
    if (pool < 0 || pool >= MAX_POOLS) {
        return false;
    }
    return m_stratumTasks[pool] && m_stratumTasks[pool]->m_validNotify && !isVerifyBlocked(pool);
}

void StratumManagerQuadPool::reconnectTimerCallback(int index)
{
    PThreadGuard lock(m_mutex);

    // verify-blocked pool must not reconnect until the block is cleared
    if (isVerifyBlocked(index)) return;

    // quad pool: all pools always try to stay alive
    if (m_stratumTasks[index]) {
        m_stratumTasks[index]->connect();
    }
}

void StratumManagerQuadPool::connectedCallback(int index)
{
    PThreadGuard lock(m_mutex);

    // Blocked pool connected (e.g. after settings save) — kick it off immediately
    if (isVerifyBlocked(index)) {
        m_stratumTasks[index]->disconnect();
        return;
    }

    if (index >= 0 && index < MAX_POOLS) {
        m_poolDiffErr[index] = false;
        s_poolDiffs[index] = 0xffffffffu;
    }
}

void StratumManagerQuadPool::disconnectedCallback(int index)
{
    PThreadGuard lock(m_mutex);
    create_job_invalidate(index);
    if (m_stratumTasks[index]) {
        m_stratumTasks[index]->m_validNotify = false;
        m_stratumTasks[index]->startReconnectTimer();
    }
    if (index >= 0 && index < MAX_POOLS) {
        m_currentWeight[index] = 0;
        s_poolDiffs[index] = 0xffffffffu;
    }
}

int StratumManagerQuadPool::getNextActivePool()
{
    PThreadGuard lock(m_mutex);

    int total = 0;
    int selected = -1;

    // Smooth weighted round-robin: accumulate each pool's weight, pick the
    // highest accumulator, then subtract the total from the winner. This
    // produces an evenly interleaved distribution instead of bursts.
    for (int i = 0; i < MAX_POOLS; i++) {
        if (!isPoolUsable(i) || m_weights[i] <= 0) {
            m_currentWeight[i] = 0;
            continue;
        }

        m_currentWeight[i] += m_weights[i];
        total += m_weights[i];

        if (selected < 0 || m_currentWeight[i] > m_currentWeight[selected]) {
            selected = i;
        }
    }

    if (selected < 0) {
        // No pool has a positive weight: fall back to the first pool with work.
        for (int i = 0; i < MAX_POOLS; i++) {
            if (isPoolUsable(i)) {
                m_lastPool = i;
                return i;
            }
        }
        // Nobody has valid work; keep the ASIC loop running with pool 0.
        m_lastPool = 0;
        return 0;
    }

    m_currentWeight[selected] -= total;
    m_lastPool = selected;
    return selected;
}

const char *StratumManagerQuadPool::getPoolHost(int pool)
{
    if (pool < 0 || pool >= MAX_POOLS || !m_stratumConfig[pool]) {
        return "-";
    }
    return m_stratumConfig[pool]->getHost();
}

int StratumManagerQuadPool::getPoolPort(int pool)
{
    if (pool < 0 || pool >= MAX_POOLS || !m_stratumConfig[pool]) {
        return 0;
    }
    return m_stratumConfig[pool]->getPort();
}

uint64_t StratumManagerQuadPool::getSharesAccepted(int pool)
{
    if (pool < 0 || pool >= MAX_POOLS) {
        return 0;
    }
    return m_accepted[pool];
}

uint64_t StratumManagerQuadPool::getSharesRejected(int pool)
{
    if (pool < 0 || pool >= MAX_POOLS) {
        return 0;
    }
    return m_rejected[pool];
}

uint32_t StratumManagerQuadPool::selectAsicDiff(int pool, uint32_t poolDiff)
{
    Board *board = SYSTEM_MODULE.getBoard();
    uint32_t asicMax = board->getAsicMaxDifficulty();
    uint32_t asicMin = board->getAsicMinDifficultyDualPool();

    if (pool < 0 || pool >= MAX_POOLS) {
        return asicMax;
    }

    m_poolDiffErr[pool] = poolDiff < asicMin;
    s_poolDiffs[pool] = poolDiff;

    // ASIC difficulty is global, so the lowest requested pool difficulty wins.
    // Only pools that can actually receive work are considered: an idle
    // (weight 0) or disconnected pool must not lower the ASIC difficulty,
    // otherwise the mining pools would submit shares below their target.
    uint32_t minDiff = 0xffffffffu;
    for (int i = 0; i < MAX_POOLS; i++) {
        if (i != pool && (!isPoolUsable(i) || m_weights[i] <= 0)) {
            continue;
        }
        if (s_poolDiffs[i] < minDiff) minDiff = s_poolDiffs[i];
    }
    if (minDiff == 0xffffffffu) {
        minDiff = poolDiff;
    }

    // clamp to ASIC range
    if (minDiff < asicMin) {
        return asicMin;
    }
    if (minDiff > asicMax) {
        return asicMax;
    }
    return minDiff;
}

bool StratumManagerQuadPool::acceptsNotifyFrom(int pool)
{
    return pool >= 0 && pool < MAX_POOLS;
}

int StratumManagerQuadPool::getActivePoolWeight(int pool)
{
    if (pool < 0 || pool >= MAX_POOLS) {
        return 0;
    }
    return m_weights[pool];
}

float StratumManagerQuadPool::getActivePoolHashrate(int pool)
{
    if (pool < 0 || pool >= MAX_POOLS) {
        return 0.0f;
    }

    int totalWeight = 0;
    for (int i = 0; i < MAX_POOLS; i++) {
        if (isPoolUsable(i) && m_weights[i] > 0) {
            totalWeight += m_weights[i];
        }
    }

    if (totalWeight <= 0 || !isPoolUsable(pool)) {
        return 0.0f;
    }

    return SYSTEM_MODULE.getCurrentHashrate() * (float) m_weights[pool] / (float) totalWeight;
}

void StratumManagerQuadPool::loadSettings()
{
    PThreadGuard lock(m_mutex);

    bool weightsChanged = false;
    for (int i = 0; i < MAX_POOLS; i++) {
        int newWeight = Config::getPoolWeight(i);
        if (m_weights[i] != newWeight) {
            m_weights[i] = newWeight;
            weightsChanged = true;
        }
    }

    if (weightsChanged) {
        // restart the round-robin distribution so the new weights apply evenly
        for (int i = 0; i < MAX_POOLS; i++) {
            m_currentWeight[i] = 0;
        }
    }

    StratumManager::loadSettings(false);
}

void StratumManagerQuadPool::saveSettings(const JsonDocument &doc)
{
    PThreadGuard lock(m_mutex);

    if (doc["poolWeights"].is<JsonArrayConst>()) {
        JsonArrayConst weights = doc["poolWeights"].as<JsonArrayConst>();
        for (int i = 0; i < (int) weights.size() && i < MAX_POOLS; i++) {
            if (weights[i].is<uint16_t>()) {
                Config::setPoolWeight(i, weights[i].as<uint16_t>());
            }
        }
    }

    StratumManager::saveSettings(doc);
    Config::flush();
}

void StratumManagerQuadPool::checkForBestDiff(int pool, double diff, uint32_t nbits)
{
    PThreadGuard lock(m_mutex);

    if (pool < 0 || pool >= MAX_POOLS) {
        return;
    }

    if ((uint64_t) diff > m_bestSessionDiff[pool]) {
        m_bestSessionDiff[pool] = (uint64_t) diff;
        updateBestSessionDiffString();
    }

    StratumManager::checkForBestDiff(pool, diff, nbits);
}

void StratumManagerQuadPool::getManagerInfoJson(JsonObject &obj, bool verbose)
{
    PThreadGuard lock(m_mutex);

    StratumManager::getManagerInfoJson(obj, verbose);

    JsonArray arr = obj["pools"].to<JsonArray>();

    for (int i = 0; i < MAX_POOLS; i++) {
        JsonObject pool = arr.add<JsonObject>();

        const char *host = m_stratumConfig[i] ? m_stratumConfig[i]->getHost() : nullptr;
        bool configured = host && strlen(host) > 0;
        bool blocked = getVerifyBlockedReason(i) != nullptr;

        pool["connected"] = m_stratumTasks[i] ? m_stratumTasks[i]->m_isConnected : false;
        pool["poolDifficulty"] = m_poolDifficulty[i];
        pool["networkDifficulty"] = m_networkDifficulty[i];
        pool["poolDiffErr"] = m_poolDiffErr[i];
        pool["accepted"] = m_accepted[i];
        pool["rejected"] = m_rejected[i];
        pool["pingRtt"]  = m_pingTasks[i] ? m_pingTasks[i]->get_last_ping_rtt() : 0;
        pool["pingLoss"] = m_pingTasks[i] ? m_pingTasks[i]->get_recent_ping_loss() : 0;
        pool["bestDiff"] = m_bestSessionDiff[i];
        pool["weight"]   = m_weights[i];

        // dashboard-only fields — kept out of the legacy v1 /info so its
        // response stays small and shape-compatible with external clients
        if (verbose) {
            pool["active"] = configured && !blocked;
            pool["verifyBlocked"] = blocked ? getVerifyBlockedReason(i) : "";
            pool["activeProtocol"] = m_stratumConfig[i] ? (int)m_stratumConfig[i]->getProtocol() : 0;
            pool["encrypted"] = m_stratumConfig[i] ? (m_stratumConfig[i]->isSV2() || m_stratumConfig[i]->isTLS()) : false;
        }
    }
}
