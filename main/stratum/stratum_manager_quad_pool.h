#pragma once

#include "stratum_manager.h"
#include "utils.h"

/**
 * @brief Quad-pool mode: four pools connected at the same time, jobs are
 * distributed according to per-pool weights using smooth weighted round-robin.
 *
 * Unlike dual-pool mode there is no fixed 50/50 split. Each pool has a relative
 * weight (0..100); a weight of 0 keeps the pool connected but never assigns
 * work to it. If all weights are zero the manager sends all work to the first
 * pool that currently has valid work (and to pool 0 if none has).
 */
class StratumManagerQuadPool : public StratumManager {
    friend StratumTaskBase; ///< Allows StratumTaskBase to access private members

  protected:
    int m_weights[MAX_POOLS] = {25, 25, 25, 25};
    int32_t m_currentWeight[MAX_POOLS] = {};
    int m_lastPool = 0;

    uint64_t m_accepted[MAX_POOLS] = {};
    uint64_t m_rejected[MAX_POOLS] = {};
    uint64_t m_bestSessionDiff[MAX_POOLS] = {};
    bool m_poolDiffErr[MAX_POOLS] = {};
    uint32_t m_poolDifficulty[MAX_POOLS] = {};
    double m_networkDifficulty[MAX_POOLS] = {};

    virtual int getNumPools() const override {
        return MAX_POOLS;
    }

    virtual void reconnectTimerCallback(int index);
    virtual void connectedCallback(int index);
    virtual void disconnectedCallback(int index);

    virtual bool acceptsNotifyFrom(int pool);

    virtual void setPoolDifficulty(int pool, uint32_t diff) {
        if (pool >= 0 && pool < MAX_POOLS) {
            m_poolDifficulty[pool] = diff;
        }
    }

    virtual void setNetworkDifficulty(int pool, uint32_t nbits) {
        if (pool >= 0 && pool < MAX_POOLS && nbits != 0) {
            m_networkDifficulty[pool] = calculateNetworkDifficulty(nbits);
        }
    }

    virtual void acceptedShare(int pool) {
        if (pool >= 0 && pool < MAX_POOLS) {
            m_accepted[pool]++;
        }
    }

    virtual void rejectedShare(int pool) {
        if (pool >= 0 && pool < MAX_POOLS) {
            m_rejected[pool]++;
        }
    }

    virtual int getPoolMode() override {
        return 2;
    }

    bool isPoolUsable(int pool) const;

  public:
    StratumManagerQuadPool();

    bool isQuadPool() const override { return true; }

    virtual const char *getPoolHost(int pool);
    virtual int getPoolPort(int pool);

    virtual uint32_t selectAsicDiff(int pool, uint32_t poolDiff);

    virtual int getNextActivePool();

    virtual void checkForBestDiff(int pool, double diff, uint32_t nbits);

    virtual void getManagerInfoJson(JsonObject &obj, bool verbose);

    virtual void loadSettings();
    virtual void saveSettings(const JsonDocument &doc);

    virtual uint64_t getSharesAccepted(int pool);
    virtual uint64_t getSharesRejected(int pool);

    float getActivePoolHashrate(int pool);
    int getActivePoolWeight(int pool);

    // aggregated
    virtual uint64_t getSharesAccepted() override {
        uint64_t total = 0;
        for (int i = 0; i < MAX_POOLS; i++) {
            total += m_accepted[i];
        }
        return total;
    }

    virtual uint64_t getSharesRejected() override {
        uint64_t total = 0;
        for (int i = 0; i < MAX_POOLS; i++) {
            total += m_rejected[i];
        }
        return total;
    }

    virtual uint32_t getPoolDifficulty() override {
        return m_poolDifficulty[m_lastPool];
    }

    virtual double getNetworkDifficulty() override {
        return m_networkDifficulty[m_lastPool];
    }

    virtual void resetPoolSessionStats(int pool) override {
        StratumManager::resetPoolSessionStats(pool);
        if (pool < 0 || pool >= MAX_POOLS) {
            return;
        }
        m_accepted[pool] = 0;
        m_rejected[pool] = 0;
        m_bestSessionDiff[pool] = 0;
        m_currentWeight[pool] = 0;
        if (m_stratumTasks[pool]) m_stratumTasks[pool]->m_poolErrors = 0;
        updateBestSessionDiffString();
    }

    virtual void resetSessionStats() override {
        PThreadGuard lock(m_mutex);
        for (int i = 0; i < MAX_POOLS; i++) {
            resetPoolSessionStats(i);
        }
        m_foundBlocks = 0;
    }

    virtual uint64_t getBestSessionDiff() override {
        uint64_t best = 0;
        for (int i = 0; i < MAX_POOLS; i++) {
            if (m_bestSessionDiff[i] > best) best = m_bestSessionDiff[i];
        }
        return best;
    }

    virtual int getPoolErrors() override {
        int errors = 0;
        for (int i = 0; i < MAX_POOLS; i++) {
            if (m_stratumTasks[i]) errors += m_stratumTasks[i]->m_poolErrors;
        }
        return errors;
    }

    virtual int getCompatPingPoolIndex() override {
        return m_lastPool;
    }

  private:
    void updateBestSessionDiffString() {
        uint64_t best = 0;
        for (int i = 0; i < MAX_POOLS; i++) {
            if (m_bestSessionDiff[i] > best) best = m_bestSessionDiff[i];
        }
        suffixString(best, m_bestSessionDiffString, DIFF_STRING_SIZE, 0);
    }
};
