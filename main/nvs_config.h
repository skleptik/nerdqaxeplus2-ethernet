#pragma once

// clang-format off

#include <stdint.h>

// Max length 15
#define NVS_CONFIG_WIFI_SSID "wifissid"
#define NVS_CONFIG_WIFI_PASS "wifipass"
#define NVS_CONFIG_HOSTNAME "hostname"
#define NVS_CONFIG_STRATUM_URL "stratumurl"
#define NVS_CONFIG_STRATUM_PORT "stratumport"
#define NVS_CONFIG_STRATUM_USER "stratumuser"
#define NVS_CONFIG_STRATUM_PASS "stratumpass"
#define NVS_CONFIG_STRATUM_ENONCE_SUB "stratumesub"
#define NVS_CONFIG_STRATUM_TLS "stratumtls"
#define NVS_CONFIG_STRATUM_FALLBACK_URL "fbstratumurl"
#define NVS_CONFIG_STRATUM_FALLBACK_PORT "fbstratumport"
#define NVS_CONFIG_STRATUM_FALLBACK_USER "fbstratumuser"
#define NVS_CONFIG_STRATUM_FALLBACK_PASS "fbstratumpass"
#define NVS_CONFIG_STRATUM_FALLBACK_ENONCE_SUB "fbstratumesub"
#define NVS_CONFIG_STRATUM_FALLBACK_TLS "fbstratumtls"
// Third and fourth pool (quad-pool mode). NVS keys are limited to 15 chars.
#define NVS_CONFIG_STRATUM_P2_URL "stratum_p2_url"
#define NVS_CONFIG_STRATUM_P2_PORT "stratum_p2_port"
#define NVS_CONFIG_STRATUM_P2_USER "stratum_p2_user"
#define NVS_CONFIG_STRATUM_P2_PASS "stratum_p2_pass"
#define NVS_CONFIG_STRATUM_P2_ENONCE_SUB "stratum_p2_esub"
#define NVS_CONFIG_STRATUM_P2_TLS "stratum_p2_tls"
#define NVS_CONFIG_STRATUM_P3_URL "stratum_p3_url"
#define NVS_CONFIG_STRATUM_P3_PORT "stratum_p3_port"
#define NVS_CONFIG_STRATUM_P3_USER "stratum_p3_user"
#define NVS_CONFIG_STRATUM_P3_PASS "stratum_p3_pass"
#define NVS_CONFIG_STRATUM_P3_ENONCE_SUB "stratum_p3_esub"
#define NVS_CONFIG_STRATUM_P3_TLS "stratum_p3_tls"
#define NVS_CONFIG_STRATUM_DIFFICULTY "stratumdiff"
#define NVS_CONFIG_STRATUM_KEEPALIVE "stratum_keep"

#define NVS_CONFIG_ASIC_FREQ "asicfrequency"
#define NVS_CONFIG_ASIC_VOLTAGE "asicvoltage"
#define NVS_CONFIG_ASIC_JOB_INTERVAL "asicjobinterval"
#define NVS_CONFIG_FLIP_SCREEN "flipscreen"
#define NVS_CONFIG_INVERT_SCREEN "invertscreen"
#define NVS_CONFIG_INVERT_FAN_POLARITY "invertfanpol"   // kept for downgrade compatibility
#define NVS_CONFIG_AUTO_FAN_POLARITY "autofanpol"       // kept for downgrade compatibility
#define NVS_CONFIG_FAN_PWM_POLARITY "pwmfanpol"         // new setting
#define NVS_CONFIG_AUTO_FAN_SPEED "autofanspeed"
#define NVS_CONFIG_FAN_SPEED "fanspeed"
#define NVS_CONFIG_SELF_TEST "selftest"
#define NVS_CONFIG_AUTO_SCREEN_OFF "autoscreenoff"
#define NVS_CONFIG_OVERHEAT_TEMP "overheat_temp"

#define NVS_CONFIG_INFLUX_ENABLE "influx_enable"
#define NVS_CONFIG_INFLUX_URL "influx_url"
#define NVS_CONFIG_INFLUX_TOKEN "influx_token"
#define NVS_CONFIG_INFLUX_PORT "influx_port"
#define NVS_CONFIG_INFLUX_BUCKET "influx_bucket"
#define NVS_CONFIG_INFLUX_ORG "influx_org"
#define NVS_CONFIG_INFLUX_PREFIX "influx_prefix"

#define NVS_CONFIG_PID_TARGET_TEMP "pid_temp"
#define NVS_CONFIG_PID_P "pid_p"
#define NVS_CONFIG_PID_I "pid_i"
#define NVS_CONFIG_PID_D "pid_d"

// Fan channel 1 (independent second fan, e.g. for VR temp)
#define NVS_CONFIG_FAN1_SPEED    "fan1speed"
#define NVS_CONFIG_FAN1_MODE     "fan1mode"
#define NVS_CONFIG_FAN1_PID_TEMP "fan1_pid_temp"
#define NVS_CONFIG_FAN1_PID_P    "fan1_pid_p"
#define NVS_CONFIG_FAN1_PID_I    "fan1_pid_i"
#define NVS_CONFIG_FAN1_PID_D    "fan1_pid_d"
#define NVS_CONFIG_FAN1_OVERHEAT "fan1_overheat"
#define NVS_CONFIG_FAN_PID_USE_MAX "fan_pid_max"

#define NVS_CONFIG_MEMPOOL_URL "mempool_url"
#define NVS_CONFIG_MEMPOOL_CUSTOM "mempool_cust"

#define CONFIG_DONATE_ADDR "bc1q7n70rumyv6lvu8avpml0c3uggvssfu52egum3q"

#define NVS_CONFIG_ALERT_DISCORD_WATCHDOG_ENABLE "alrt_disc_en"
#define NVS_CONFIG_ALERT_DISCORD_URL    "alrt_disc_url"
#define NVS_CONFIG_ALERT_DISCORD_BLOCK_FOUND_ENABLE "alrt_disc_bf_en"
#define NVS_CONFIG_ALERT_DISCORD_BEST_DIFF "alrt_disc_bd_en"
#define NVS_CONFIG_ALERT_DISCORD_COINBASE_VERIFY "alrt_disc_cb_en"

#define NVS_CONFIG_SHOW_BLOCK_FOUND_ENABLE "block_found_en"

#define NVS_CONFIG_SWARM "swarmconfig"

#define NVS_CONFIG_CAN_ENABLED "can_enabled"

#define NVS_CONFIG_VR_FREQUENCY "vr_frequency"

// device global stats
#define NVS_TOTAL_FOUND_BLOCKS "totalblocks"
#define NVS_CONFIG_BEST_DIFF "bestdiff"


// Coinbase verification (per pool)
#define NVS_CONFIG_COINBASE_VERIFY_MODE    "cb_verify_mode"
#define NVS_CONFIG_COINBASE_MAX_FEE        "cb_max_fee"
#define NVS_CONFIG_COINBASE_VERIFY_FORCE   "cb_vfy_force"
#define NVS_CONFIG_FB_COINBASE_VERIFY_MODE "fb_cb_vfy_mode"
#define NVS_CONFIG_FB_COINBASE_MAX_FEE     "fb_cb_max_fee"
#define NVS_CONFIG_FB_COINBASE_VERIFY_FORCE "fb_cb_vfy_frc"
#define NVS_CONFIG_P2_COINBASE_VERIFY_MODE "cb_p2_vfy_mode"
#define NVS_CONFIG_P2_COINBASE_MAX_FEE     "cb_p2_max_fee"
#define NVS_CONFIG_P2_COINBASE_VERIFY_FORCE "cb_p2_vfy_frc"
#define NVS_CONFIG_P3_COINBASE_VERIFY_MODE "cb_p3_vfy_mode"
#define NVS_CONFIG_P3_COINBASE_MAX_FEE     "cb_p3_max_fee"
#define NVS_CONFIG_P3_COINBASE_VERIFY_FORCE "cb_p3_vfy_frc"

// OTP
#define NVS_CONFIG_OTP_SECRET "otp_secret"
#define NVS_CONFIG_OTP_ENABLED "otp_enabled"
#define NVS_CONFIG_OTP_LAST_STEP "otp_last_step"
#define NVS_CONFIG_OTP_USED_MASK "otp_used_mask"
#define NVS_CONFIG_OTP_SESSION_KEY "otp_sess_key"
#define NVS_CONFIG_OTP_BOOT_ID "otp_boot_id"

#define NVS_CONFIG_POOL_MODE_BALANCE "pool_balance"
#define NVS_CONFIG_POOL_MODE "pool_mode"
// Per-pool weights for quad-pool mode (relative, normalized at runtime)
#define NVS_CONFIG_POOL_WEIGHT0 "pool_w0"
#define NVS_CONFIG_POOL_WEIGHT1 "pool_w1"
#define NVS_CONFIG_POOL_WEIGHT2 "pool_w2"
#define NVS_CONFIG_POOL_WEIGHT3 "pool_w3"

// Stratum V2
#define NVS_CONFIG_STRATUM_PROTOCOL "sv2_proto"
#define NVS_CONFIG_SV2_AUTHORITY_PUBKEY "sv2_auth_pk"
#define NVS_CONFIG_SV2_CHANNEL_TYPE "sv2_chan_type"
#define NVS_CONFIG_SV2_REQUIRE_AUTH "sv2_reqauth"
#define NVS_CONFIG_FB_STRATUM_PROTOCOL "fbsv2_proto"
#define NVS_CONFIG_FB_SV2_AUTHORITY_PUBKEY "fbsv2_authpk"
#define NVS_CONFIG_FB_SV2_CHANNEL_TYPE "fbsv2_chtype"
#define NVS_CONFIG_FB_SV2_REQUIRE_AUTH "fbsv2_reqauth"
#define NVS_CONFIG_P2_STRATUM_PROTOCOL "sv2p2_proto"
#define NVS_CONFIG_P2_SV2_AUTHORITY_PUBKEY "sv2p2_auth_pk"
#define NVS_CONFIG_P2_SV2_CHANNEL_TYPE "sv2p2_chtype"
#define NVS_CONFIG_P2_SV2_REQUIRE_AUTH "sv2p2_reqauth"
#define NVS_CONFIG_P3_STRATUM_PROTOCOL "sv2p3_proto"
#define NVS_CONFIG_P3_SV2_AUTHORITY_PUBKEY "sv2p3_auth_pk"
#define NVS_CONFIG_P3_SV2_CHANNEL_TYPE "sv2p3_chtype"
#define NVS_CONFIG_P3_SV2_REQUIRE_AUTH "sv2p3_reqauth"

#if defined(CONFIG_FAN_MODE_MANUAL)
#define CONFIG_AUTO_FAN_SPEED_VALUE 0
#elif defined(CONFIG_FAN_MODE_CLASSIC)
#define CONFIG_AUTO_FAN_SPEED_VALUE 1
#elif defined(CONFIG_FAN_MODE_PID)
#define CONFIG_AUTO_FAN_SPEED_VALUE 2
#endif

#include <stdint.h>

namespace Config {
    // ---- Lifecycle ----
    void init();     // Load flat JSON blob or migrate legacy keys. Call once at boot.
    void flush();    // Signal the non-PSRAM flush task to persist batched changes.

    // ---- Direct document access (for API handlers — include ArduinoJson.h first) ----
    // JsonDocument& getDoc();
    void cfgLock();
    void cfgUnlock();

    // ---- Generic typed accessors (backed by the in-memory flat JSON doc) ----
    char* cfgGetStrAlloc(const char* path, const char* def = "");  // caller must free
    void  cfgSetStr(const char* path, const char* value);
    uint16_t cfgGetU16(const char* path, uint16_t def = 0);
    void     cfgSetU16(const char* path, uint16_t value);
    bool     cfgGetBool(const char* path, bool def = false);
    void     cfgSetBool(const char* path, bool value);
    uint64_t cfgGetU64(const char* path, uint64_t def = 0);
    void     cfgSetU64(const char* path, uint64_t value);

    bool     cfgHasKey(const char* path);

    // ---- String Getters ----
    inline char* getWifiSSID() { return cfgGetStrAlloc(NVS_CONFIG_WIFI_SSID, CONFIG_ESP_WIFI_SSID); }
    inline char* getWifiPass() { return cfgGetStrAlloc(NVS_CONFIG_WIFI_PASS, CONFIG_ESP_WIFI_PASSWORD); }
    inline char* getHostname() { return cfgGetStrAlloc(NVS_CONFIG_HOSTNAME, CONFIG_LWIP_LOCAL_HOSTNAME); }
    inline char* getStratumURL() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_URL, CONFIG_STRATUM_URL); }
    inline char* getStratumUser() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_USER, CONFIG_STRATUM_USER); }
    inline char* getStratumPass() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_PASS, CONFIG_STRATUM_PW); }
    inline char* getStratumFallbackURL() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_FALLBACK_URL, CONFIG_STRATUM_FALLBACK_URL); }
    inline char* getStratumFallbackUser() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_FALLBACK_USER, CONFIG_STRATUM_FALLBACK_USER); }
    inline char* getStratumFallbackPass() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_FALLBACK_PASS, CONFIG_STRATUM_FALLBACK_PW); }
    inline char* getStratumP2URL() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_P2_URL, ""); }
    inline char* getStratumP2User() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_P2_USER, ""); }
    inline char* getStratumP2Pass() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_P2_PASS, ""); }
    inline char* getStratumP3URL() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_P3_URL, ""); }
    inline char* getStratumP3User() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_P3_USER, ""); }
    inline char* getStratumP3Pass() { return cfgGetStrAlloc(NVS_CONFIG_STRATUM_P3_PASS, ""); }
    inline char* getInfluxURL() { return cfgGetStrAlloc(NVS_CONFIG_INFLUX_URL, CONFIG_INFLUX_URL); }
    inline char* getInfluxToken() { return cfgGetStrAlloc(NVS_CONFIG_INFLUX_TOKEN, CONFIG_INFLUX_TOKEN); }
    inline char* getInfluxBucket() { return cfgGetStrAlloc(NVS_CONFIG_INFLUX_BUCKET, CONFIG_INFLUX_BUCKET); }
    inline char* getInfluxOrg() { return cfgGetStrAlloc(NVS_CONFIG_INFLUX_ORG, CONFIG_INFLUX_ORG); }
    inline char* getInfluxPrefix() { return cfgGetStrAlloc(NVS_CONFIG_INFLUX_PREFIX, CONFIG_INFLUX_PREFIX); }
    inline char* getSwarmConfig() { return cfgGetStrAlloc(NVS_CONFIG_SWARM, ""); }
    inline char* getDiscordWebhook() { return cfgGetStrAlloc(NVS_CONFIG_ALERT_DISCORD_URL, CONFIG_ALERT_DISCORD_URL); }
    inline char* getMempoolUrl() { return cfgGetStrAlloc(NVS_CONFIG_MEMPOOL_URL, CONFIG_MEMPOOL_URL); }
    inline void setMempoolUrl(const char* value) { cfgSetStr(NVS_CONFIG_MEMPOOL_URL, value); }
    inline bool isMempoolCustom() { return cfgGetU16(NVS_CONFIG_MEMPOOL_CUSTOM, 0) != 0; }
    inline void setMempoolCustom(bool v) { cfgSetU16(NVS_CONFIG_MEMPOOL_CUSTOM, v ? 1 : 0); }

    // ---- String Setters ----
    inline void setWifiSSID(const char* value) { cfgSetStr(NVS_CONFIG_WIFI_SSID, value); }
    inline void setWifiPass(const char* value) { cfgSetStr(NVS_CONFIG_WIFI_PASS, value); }
    inline void setHostname(const char* value) { cfgSetStr(NVS_CONFIG_HOSTNAME, value); }
    inline void setStratumURL(const char* value) { cfgSetStr(NVS_CONFIG_STRATUM_URL, value); }
    inline void setStratumUser(const char* value) { cfgSetStr(NVS_CONFIG_STRATUM_USER, value); }
    inline void setStratumPass(const char* value) { cfgSetStr(NVS_CONFIG_STRATUM_PASS, value); }
    inline void setStratumFallbackURL(const char* value) { cfgSetStr(NVS_CONFIG_STRATUM_FALLBACK_URL, value); }
    inline void setStratumFallbackUser(const char* value) { cfgSetStr(NVS_CONFIG_STRATUM_FALLBACK_USER, value); }
    inline void setStratumFallbackPass(const char* value) { cfgSetStr(NVS_CONFIG_STRATUM_FALLBACK_PASS, value); }
    inline void setInfluxURL(const char* value) { cfgSetStr(NVS_CONFIG_INFLUX_URL, value); }
    inline void setInfluxToken(const char* value) { cfgSetStr(NVS_CONFIG_INFLUX_TOKEN, value); }
    inline void setInfluxBucket(const char* value) { cfgSetStr(NVS_CONFIG_INFLUX_BUCKET, value); }
    inline void setInfluxOrg(const char* value) { cfgSetStr(NVS_CONFIG_INFLUX_ORG, value); }
    inline void setInfluxPrefix(const char* value) { cfgSetStr(NVS_CONFIG_INFLUX_PREFIX, value); }
    inline void setSwarmConfig(const char* value) { cfgSetStr(NVS_CONFIG_SWARM, value); }
    inline void setDiscordWebhook(const char* value) { cfgSetStr(NVS_CONFIG_ALERT_DISCORD_URL, value); }

    // ---- uint16_t Getters ----
    inline uint16_t getStratumPortNumber() { return cfgGetU16(NVS_CONFIG_STRATUM_PORT, CONFIG_STRATUM_PORT); }
    inline uint16_t getStratumFallbackPortNumber() { return cfgGetU16(NVS_CONFIG_STRATUM_FALLBACK_PORT, CONFIG_STRATUM_FALLBACK_PORT); }
    inline uint16_t getFanSpeed() { return cfgGetU16(NVS_CONFIG_FAN_SPEED, CONFIG_FAN_SPEED); }
    inline uint16_t getOverheatTemp() { return cfgGetU16(NVS_CONFIG_OVERHEAT_TEMP, CONFIG_OVERHEAT_TEMP); }
    inline uint16_t getInfluxPort() { return cfgGetU16(NVS_CONFIG_INFLUX_PORT, CONFIG_INFLUX_PORT); }
    inline uint16_t getPoolMode() { return cfgGetU16(NVS_CONFIG_POOL_MODE, 0); }
    inline uint16_t getPoolBalance() { return cfgGetU16(NVS_CONFIG_POOL_MODE_BALANCE, 50); }

    // ---- uint16_t Setters ----
    inline void setAsicFrequency(uint16_t value) { cfgSetU16(NVS_CONFIG_ASIC_FREQ, value); }
    inline void setAsicVoltage(uint16_t value) { cfgSetU16(NVS_CONFIG_ASIC_VOLTAGE, value); }
    inline void setAsicJobInterval(uint16_t value) { cfgSetU16(NVS_CONFIG_ASIC_JOB_INTERVAL, value); }
    inline void setStratumPortNumber(uint16_t value) { cfgSetU16(NVS_CONFIG_STRATUM_PORT, value); }
    inline void setStratumFallbackPortNumber(uint16_t value) { cfgSetU16(NVS_CONFIG_STRATUM_FALLBACK_PORT, value); }
    inline void setFanSpeed(uint16_t value) { cfgSetU16(NVS_CONFIG_FAN_SPEED, value); }
    inline void setOverheatTemp(uint16_t value) { cfgSetU16(NVS_CONFIG_OVERHEAT_TEMP, value); }
    inline void setInfluxPort(uint16_t value) { cfgSetU16(NVS_CONFIG_INFLUX_PORT, value); }
    inline void setTempControlMode(uint16_t value) { cfgSetU16(NVS_CONFIG_AUTO_FAN_SPEED, value); }
    inline void setPoolMode(uint16_t value) { cfgSetU16(NVS_CONFIG_POOL_MODE, value); }
    inline void setPoolBalance(uint16_t value) { cfgSetU16(NVS_CONFIG_POOL_MODE_BALANCE, value); }

    inline void setPidTargetTemp(uint16_t value) { cfgSetU16(NVS_CONFIG_PID_TARGET_TEMP, value); }
    inline void setPidP(uint16_t value) { cfgSetU16(NVS_CONFIG_PID_P, value); }
    inline void setPidI(uint16_t value) { cfgSetU16(NVS_CONFIG_PID_I, value); }
    inline void setPidD(uint16_t value) { cfgSetU16(NVS_CONFIG_PID_D, value); }

    // Indexed fan-channel getters (ch=0 → ch0 NVS keys, ch=1 → fan1 NVS keys)
    // ch0 defaults: mode=CONFIG_AUTO_FAN_SPEED_VALUE, speed=CONFIG_FAN_SPEED, overheat=CONFIG_OVERHEAT_TEMP
    // ch1 defaults: mode=3 (linked), speed=100%, overheat=80°C
    inline uint16_t getFanMode(int ch, uint16_t def) {
        return ch == 0 ? cfgGetU16(NVS_CONFIG_AUTO_FAN_SPEED, def)
                       : cfgGetU16(NVS_CONFIG_FAN1_MODE, def);
    }
    inline uint16_t getFanManualSpeed(int ch) {
        return ch == 0 ? cfgGetU16(NVS_CONFIG_FAN_SPEED, CONFIG_FAN_SPEED)
                       : cfgGetU16(NVS_CONFIG_FAN1_SPEED, 100);
    }
    inline uint16_t getFanOverheatTemp(int ch) {
        return ch == 0 ? cfgGetU16(NVS_CONFIG_OVERHEAT_TEMP, CONFIG_OVERHEAT_TEMP)
                       : cfgGetU16(NVS_CONFIG_FAN1_OVERHEAT, CONFIG_OVERHEAT_TEMP);
    }
    inline uint16_t getFanPidTargetTemp(int ch, uint16_t d) {
        return ch == 0 ? cfgGetU16(NVS_CONFIG_PID_TARGET_TEMP, d)
                       : cfgGetU16(NVS_CONFIG_FAN1_PID_TEMP, d);
    }
    inline uint16_t getFanPidP(int ch, uint16_t d) {
        return ch == 0 ? cfgGetU16(NVS_CONFIG_PID_P, d)
                       : cfgGetU16(NVS_CONFIG_FAN1_PID_P, d);
    }
    inline uint16_t getFanPidI(int ch, uint16_t d) {
        return ch == 0 ? cfgGetU16(NVS_CONFIG_PID_I, d)
                       : cfgGetU16(NVS_CONFIG_FAN1_PID_I, d);
    }
    inline uint16_t getFanPidD(int ch, uint16_t d) {
        return ch == 0 ? cfgGetU16(NVS_CONFIG_PID_D, d)
                       : cfgGetU16(NVS_CONFIG_FAN1_PID_D, d);
    }

    // Indexed fan-channel setters
    inline void setFanMode(int ch, uint16_t v) {
        if (ch == 0) cfgSetU16(NVS_CONFIG_AUTO_FAN_SPEED, v);
        else         cfgSetU16(NVS_CONFIG_FAN1_MODE, v);
    }
    inline void setFanManualSpeed(int ch, uint16_t v) {
        if (ch == 0) cfgSetU16(NVS_CONFIG_FAN_SPEED, v);
        else         cfgSetU16(NVS_CONFIG_FAN1_SPEED, v);
    }
    inline void setFanOverheatTemp(int ch, uint16_t v) {
        if (ch == 0) cfgSetU16(NVS_CONFIG_OVERHEAT_TEMP, v);
        else         cfgSetU16(NVS_CONFIG_FAN1_OVERHEAT, v);
    }
    inline void setFanPidTargetTemp(int ch, uint16_t v) {
        if (ch == 0) cfgSetU16(NVS_CONFIG_PID_TARGET_TEMP, v);
        else         cfgSetU16(NVS_CONFIG_FAN1_PID_TEMP, v);
    }
    inline void setFanPidP(int ch, uint16_t v) {
        if (ch == 0) cfgSetU16(NVS_CONFIG_PID_P, v);
        else         cfgSetU16(NVS_CONFIG_FAN1_PID_P, v);
    }
    inline void setFanPidI(int ch, uint16_t v) {
        if (ch == 0) cfgSetU16(NVS_CONFIG_PID_I, v);
        else         cfgSetU16(NVS_CONFIG_FAN1_PID_I, v);
    }
    inline void setFanPidD(int ch, uint16_t v) {
        if (ch == 0) cfgSetU16(NVS_CONFIG_PID_D, v);
        else         cfgSetU16(NVS_CONFIG_FAN1_PID_D, v);
    }

    // Fan PID: use max(ASIC, VReg) as input instead of ASIC only
    inline bool isFanPidUseMax() { return cfgGetU16(NVS_CONFIG_FAN_PID_USE_MAX, 1) != 0; }
    inline void setFanPidUseMax(bool v) { cfgSetU16(NVS_CONFIG_FAN_PID_USE_MAX, v ? 1 : 0); }

    // ---- uint64_t Getters ----
    uint64_t getBestDiff();
    uint32_t getTotalFoundBlocks();
    inline uint32_t getStratumDifficulty() { return (uint32_t) cfgGetU64(NVS_CONFIG_STRATUM_DIFFICULTY, CONFIG_STRATUM_DIFFICULTY); }

    // ---- uint64_t Setters ----
    void setBestDiff(uint64_t value);
    void setTotalFoundBlocks(uint32_t value);
    inline void setStratumDifficulty(uint32_t value) { cfgSetU64(NVS_CONFIG_STRATUM_DIFFICULTY, value); }
    inline void setVrFrequency(uint32_t value) { cfgSetU64(NVS_CONFIG_VR_FREQUENCY, value); }

    // ---- Boolean Getters (Stored as uint16_t but used as bool) ----
    inline bool isInvertScreenEnabled() { return cfgGetU16(NVS_CONFIG_INVERT_SCREEN, 0) != 0; } // todo unused?
    inline bool isSelfTestEnabled() { return cfgGetU16(NVS_CONFIG_SELF_TEST, 0) != 0; }
    inline bool isAutoScreenOffEnabled() { return cfgGetU16(NVS_CONFIG_AUTO_SCREEN_OFF, CONFIG_AUTO_SCREEN_OFF_VALUE) != 0; }
    inline bool isInfluxEnabled() { return cfgGetU16(NVS_CONFIG_INFLUX_ENABLE, CONFIG_INFLUX_ENABLE_VALUE) != 0; }
    inline bool isDiscordWatchdogAlertEnabled() { return cfgGetU16(NVS_CONFIG_ALERT_DISCORD_WATCHDOG_ENABLE, CONFIG_ALERT_DISCORD_WATCHDOG_ENABLE_VALUE) != 0; }
    inline bool isDiscordBlockFoundAlertEnabled() { return cfgGetU16(NVS_CONFIG_ALERT_DISCORD_BLOCK_FOUND_ENABLE, CONFIG_ALERT_DISCORD_BLOCK_FOUND_ENABLE_VALUE) != 0; }
    inline bool isDiscordBestDiffAlertEnabled() { return cfgGetU16(NVS_CONFIG_ALERT_DISCORD_BEST_DIFF, CONFIG_ALERT_DISCORD_BEST_DIFF_ENABLE_VALUE) != 0; }
    inline bool isDiscordCoinbaseVerifyAlertEnabled() { return cfgGetU16(NVS_CONFIG_ALERT_DISCORD_COINBASE_VERIFY, 0) != 0; }
    inline bool isStratumKeepaliveEnabled() { return cfgGetU16(NVS_CONFIG_STRATUM_KEEPALIVE, CONFIG_STRATUM_KEEPALIVE_ENABLE_VALUE) != 0; }
    inline bool isStratumEnonceSubscribe() { return cfgGetU16(NVS_CONFIG_STRATUM_ENONCE_SUB, CONFIG_STRATUM_ENONCE_SUBSCRIBE_VALUE) != 0; }
    inline bool isStratumFallbackEnonceSubscribe() { return cfgGetU16(NVS_CONFIG_STRATUM_FALLBACK_ENONCE_SUB, CONFIG_STRATUM_FALLBACK_ENONCE_SUBSCRIBE_VALUE) != 0; }
    inline bool isStratumTLS() { return cfgGetU16(NVS_CONFIG_STRATUM_TLS, CONFIG_STRATUM_TLS_VALUE) != 0; }
    inline bool isStratumFallbackTLS() { return cfgGetU16(NVS_CONFIG_STRATUM_FALLBACK_TLS, CONFIG_STRATUM_FALLBACK_TLS_VALUE) != 0; }
    inline bool isShowBlockFoundEnabled() { return cfgGetU16(NVS_CONFIG_SHOW_BLOCK_FOUND_ENABLE, CONFIG_SHOW_BLOCK_FOUND_ENABLE_VALUE) != 0; }
    inline bool isCanEnabled() { return cfgGetU16(NVS_CONFIG_CAN_ENABLED, 0) != 0; }

    // Stratum V2
    inline uint16_t getStratumProtocol() { return cfgGetU16(NVS_CONFIG_STRATUM_PROTOCOL, 0); }
    inline void setStratumProtocol(uint16_t value) { cfgSetU16(NVS_CONFIG_STRATUM_PROTOCOL, value); }
    inline uint16_t getFallbackStratumProtocol() { return cfgGetU16(NVS_CONFIG_FB_STRATUM_PROTOCOL, 0); }
    inline void setFallbackStratumProtocol(uint16_t value) { cfgSetU16(NVS_CONFIG_FB_STRATUM_PROTOCOL, value); }
    inline char* getSV2AuthorityPubkey() { return cfgGetStrAlloc(NVS_CONFIG_SV2_AUTHORITY_PUBKEY, ""); }
    inline void setSV2AuthorityPubkey(const char* value) { cfgSetStr(NVS_CONFIG_SV2_AUTHORITY_PUBKEY, value); }
    inline char* getFallbackSV2AuthorityPubkey() { return cfgGetStrAlloc(NVS_CONFIG_FB_SV2_AUTHORITY_PUBKEY, ""); }
    inline void setFallbackSV2AuthorityPubkey(const char* value) { cfgSetStr(NVS_CONFIG_FB_SV2_AUTHORITY_PUBKEY, value); }
    inline uint16_t getSV2ChannelType() { return cfgGetU16(NVS_CONFIG_SV2_CHANNEL_TYPE, 0); }
    inline void setSV2ChannelType(uint16_t value) { cfgSetU16(NVS_CONFIG_SV2_CHANNEL_TYPE, value); }
    inline uint16_t getFallbackSV2ChannelType() { return cfgGetU16(NVS_CONFIG_FB_SV2_CHANNEL_TYPE, 0); }
    inline void setFallbackSV2ChannelType(uint16_t value) { cfgSetU16(NVS_CONFIG_FB_SV2_CHANNEL_TYPE, value); }
    inline bool isSV2RequireAuth() { return cfgGetU16(NVS_CONFIG_SV2_REQUIRE_AUTH, 0) != 0; }
    inline void setSV2RequireAuth(bool value) { cfgSetU16(NVS_CONFIG_SV2_REQUIRE_AUTH, value ? 1 : 0); }
    inline bool isFallbackSV2RequireAuth() { return cfgGetU16(NVS_CONFIG_FB_SV2_REQUIRE_AUTH, 0) != 0; }
    inline void setFallbackSV2RequireAuth(bool value) { cfgSetU16(NVS_CONFIG_FB_SV2_REQUIRE_AUTH, value ? 1 : 0); }

    // ---- Boolean Setters ----
    inline void setFlipScreen(bool value) { cfgSetU16(NVS_CONFIG_FLIP_SCREEN, value ? 1 : 0); }
    inline void setInvertScreen(bool value) { cfgSetU16(NVS_CONFIG_INVERT_SCREEN, value ? 1 : 0); }
    inline void setFanPolarity(bool value) { cfgSetU16(NVS_CONFIG_FAN_PWM_POLARITY, value ? 1 : 0); }
    inline void setSelfTest(bool value) { cfgSetU16(NVS_CONFIG_SELF_TEST, value ? 1 : 0); }
    inline void setAutoScreenOff(bool value) { cfgSetU16(NVS_CONFIG_AUTO_SCREEN_OFF, value ? 1 : 0); }
    inline void setInfluxEnabled(bool value) { cfgSetU16(NVS_CONFIG_INFLUX_ENABLE, value ? 1 : 0); }
    inline void setDiscordWatchdogAlertEnabled(bool value) { cfgSetU16(NVS_CONFIG_ALERT_DISCORD_WATCHDOG_ENABLE, value ? 1 : 0); }
    inline void setDiscordAlertBlockFoundEnabled(bool value) { cfgSetU16(NVS_CONFIG_ALERT_DISCORD_BLOCK_FOUND_ENABLE, value ? 1 : 0); }
    inline void setDiscordAlertBestDiffEnabled(bool value) { cfgSetU16(NVS_CONFIG_ALERT_DISCORD_BEST_DIFF, value ? 1 : 0); }
    inline void setDiscordCoinbaseVerifyAlertEnabled(bool value) { cfgSetU16(NVS_CONFIG_ALERT_DISCORD_COINBASE_VERIFY, value ? 1 : 0); }
    inline void setStratumKeepaliveEnabled(bool value) { cfgSetU16(NVS_CONFIG_STRATUM_KEEPALIVE, value ? 1 : 0); }
    inline void setStratumEnonceSubscribe(bool value) { cfgSetU16(NVS_CONFIG_STRATUM_ENONCE_SUB, value ? 1 : 0); }
    inline void setStratumFallbackEnonceSubscribe(bool value) { cfgSetU16(NVS_CONFIG_STRATUM_FALLBACK_ENONCE_SUB, value ? 1 : 0); }
    inline void setStratumTLS(bool value) { cfgSetU16(NVS_CONFIG_STRATUM_TLS, value ? 1 : 0); }
    inline void setStratumFallbackTLS(bool value) { cfgSetU16(NVS_CONFIG_STRATUM_FALLBACK_TLS, value ? 1 : 0); }
    inline void setShowBlockFoundEnabled(bool value) { cfgSetU16(NVS_CONFIG_SHOW_BLOCK_FOUND_ENABLE, value ? 1 : 0); }
    inline void setCanEnabled(bool value) { cfgSetU16(NVS_CONFIG_CAN_ENABLED, value ? 1 : 0); }

    // with board specific default values
    inline uint16_t getAsicFrequency(uint16_t d) { return cfgGetU16(NVS_CONFIG_ASIC_FREQ, d); }
    inline uint16_t getAsicVoltage(uint16_t d) { return cfgGetU16(NVS_CONFIG_ASIC_VOLTAGE, d); }
    inline uint16_t getAsicJobInterval(uint16_t d) { return cfgGetU16(NVS_CONFIG_ASIC_JOB_INTERVAL, d); }
    inline bool isFlipScreenEnabled(bool d) { return cfgGetU16(NVS_CONFIG_FLIP_SCREEN, d ? 1 : 0) != 0; }
    inline bool isFanPolarity(bool d) { return cfgGetU16(NVS_CONFIG_FAN_PWM_POLARITY, d ? 1 : 0) != 0; }
    inline uint16_t getPidTargetTemp(uint16_t d) { return cfgGetU16(NVS_CONFIG_PID_TARGET_TEMP, d); }
    inline uint16_t getPidP(uint16_t d) { return cfgGetU16(NVS_CONFIG_PID_P, d); }
    inline uint16_t getPidI(uint16_t d) { return cfgGetU16(NVS_CONFIG_PID_I, d); }
    inline uint16_t getPidD(uint16_t d) { return cfgGetU16(NVS_CONFIG_PID_D, d); }
    inline uint32_t getVrFrequency(uint32_t d) { return (uint32_t) cfgGetU64(NVS_CONFIG_VR_FREQUENCY, d); }

    // OTP Replay-Protection state (last_step + 3-bit mask)
    inline void getOTPReplayState(int64_t& base_step, uint8_t& mask) {
        base_step = (int64_t) cfgGetU64(NVS_CONFIG_OTP_LAST_STEP, 0ULL);
        mask      = (uint8_t) cfgGetU16(NVS_CONFIG_OTP_USED_MASK, 0);
    }

    inline void setOTPReplayState(int64_t base_step, uint8_t mask) {
        cfgSetU64(NVS_CONFIG_OTP_LAST_STEP, (uint64_t) base_step);
        cfgSetU16(NVS_CONFIG_OTP_USED_MASK, (uint16_t)(mask & 0x07));
    }

    inline void setOTPSecret(const char* value) { cfgSetStr(NVS_CONFIG_OTP_SECRET, value); }
    inline char* getOTPSecret() { return cfgGetStrAlloc(NVS_CONFIG_OTP_SECRET, ""); }

    inline void setOTTBootId(uint32_t boot_id) { cfgSetU64(NVS_CONFIG_OTP_BOOT_ID, boot_id); }
    inline uint32_t getOTPBootId() { return (uint32_t) cfgGetU64(NVS_CONFIG_OTP_BOOT_ID, 0); }

    inline void setOTPSessionKey(const char* value) { cfgSetStr(NVS_CONFIG_OTP_SESSION_KEY, value); }
    inline char* getOTPSessionKey() { return cfgGetStrAlloc(NVS_CONFIG_OTP_SESSION_KEY, ""); }

    inline void setOTPEnabled(bool value) { cfgSetU16(NVS_CONFIG_OTP_ENABLED, value ? 1 : 0); }
    inline bool isOTPEnabled() { return cfgGetU16(NVS_CONFIG_OTP_ENABLED, 0) != 0; }

    // ---- Indexed pool accessors (0 = primary, 1 = fallback, 2/3 = quad pools) ----
    // The legacy primary/fallback settings keep their own NVS keys; pools 2 and 3
    // use the dedicated stratum_p2_*/stratum_p3_* keys. Invalid indexes fall back
    // to the primary pool so callers can never walk off the arrays.
    inline char* getStratumURLAt(int pool) {
        switch (pool) {
            case 1:  return getStratumFallbackURL();
            case 2:  return getStratumP2URL();
            case 3:  return getStratumP3URL();
            default: return getStratumURL();
        }
    }
    inline char* getStratumUserAt(int pool) {
        switch (pool) {
            case 1:  return getStratumFallbackUser();
            case 2:  return getStratumP2User();
            case 3:  return getStratumP3User();
            default: return getStratumUser();
        }
    }
    inline char* getStratumPassAt(int pool) {
        switch (pool) {
            case 1:  return getStratumFallbackPass();
            case 2:  return getStratumP2Pass();
            case 3:  return getStratumP3Pass();
            default: return getStratumPass();
        }
    }
    inline uint16_t getStratumPortAt(int pool) {
        switch (pool) {
            case 1:  return getStratumFallbackPortNumber();
            case 2:  return cfgGetU16(NVS_CONFIG_STRATUM_P2_PORT, 0);
            case 3:  return cfgGetU16(NVS_CONFIG_STRATUM_P3_PORT, 0);
            default: return getStratumPortNumber();
        }
    }
    inline bool isStratumEnonceSubscribeAt(int pool) {
        switch (pool) {
            case 1:  return isStratumFallbackEnonceSubscribe();
            case 2:  return cfgGetU16(NVS_CONFIG_STRATUM_P2_ENONCE_SUB, 0) != 0;
            case 3:  return cfgGetU16(NVS_CONFIG_STRATUM_P3_ENONCE_SUB, 0) != 0;
            default: return isStratumEnonceSubscribe();
        }
    }
    inline bool isStratumTLSAt(int pool) {
        switch (pool) {
            case 1:  return isStratumFallbackTLS();
            case 2:  return cfgGetU16(NVS_CONFIG_STRATUM_P2_TLS, 0) != 0;
            case 3:  return cfgGetU16(NVS_CONFIG_STRATUM_P3_TLS, 0) != 0;
            default: return isStratumTLS();
        }
    }
    inline uint16_t getStratumProtocolAt(int pool) {
        switch (pool) {
            case 1:  return getFallbackStratumProtocol();
            case 2:  return cfgGetU16(NVS_CONFIG_P2_STRATUM_PROTOCOL, 0);
            case 3:  return cfgGetU16(NVS_CONFIG_P3_STRATUM_PROTOCOL, 0);
            default: return getStratumProtocol();
        }
    }
    inline void setStratumURLAt(int pool, const char* value) {
        switch (pool) {
            case 1:  setStratumFallbackURL(value); break;
            case 2:  cfgSetStr(NVS_CONFIG_STRATUM_P2_URL, value); break;
            case 3:  cfgSetStr(NVS_CONFIG_STRATUM_P3_URL, value); break;
            default: setStratumURL(value); break;
        }
    }
    inline void setStratumUserAt(int pool, const char* value) {
        switch (pool) {
            case 1:  setStratumFallbackUser(value); break;
            case 2:  cfgSetStr(NVS_CONFIG_STRATUM_P2_USER, value); break;
            case 3:  cfgSetStr(NVS_CONFIG_STRATUM_P3_USER, value); break;
            default: setStratumUser(value); break;
        }
    }
    inline void setStratumPassAt(int pool, const char* value) {
        switch (pool) {
            case 1:  setStratumFallbackPass(value); break;
            case 2:  cfgSetStr(NVS_CONFIG_STRATUM_P2_PASS, value); break;
            case 3:  cfgSetStr(NVS_CONFIG_STRATUM_P3_PASS, value); break;
            default: setStratumPass(value); break;
        }
    }
    inline void setStratumPortAt(int pool, uint16_t value) {
        switch (pool) {
            case 1:  setStratumFallbackPortNumber(value); break;
            case 2:  cfgSetU16(NVS_CONFIG_STRATUM_P2_PORT, value); break;
            case 3:  cfgSetU16(NVS_CONFIG_STRATUM_P3_PORT, value); break;
            default: setStratumPortNumber(value); break;
        }
    }
    inline void setStratumEnonceSubscribeAt(int pool, bool value) {
        switch (pool) {
            case 1:  setStratumFallbackEnonceSubscribe(value); break;
            case 2:  cfgSetU16(NVS_CONFIG_STRATUM_P2_ENONCE_SUB, value ? 1 : 0); break;
            case 3:  cfgSetU16(NVS_CONFIG_STRATUM_P3_ENONCE_SUB, value ? 1 : 0); break;
            default: setStratumEnonceSubscribe(value); break;
        }
    }
    inline void setStratumTLSAt(int pool, bool value) {
        switch (pool) {
            case 1:  setStratumFallbackTLS(value); break;
            case 2:  cfgSetU16(NVS_CONFIG_STRATUM_P2_TLS, value ? 1 : 0); break;
            case 3:  cfgSetU16(NVS_CONFIG_STRATUM_P3_TLS, value ? 1 : 0); break;
            default: setStratumTLS(value); break;
        }
    }
    inline void setStratumProtocolAt(int pool, uint16_t value) {
        switch (pool) {
            case 1:  setFallbackStratumProtocol(value); break;
            case 2:  cfgSetU16(NVS_CONFIG_P2_STRATUM_PROTOCOL, value); break;
            case 3:  cfgSetU16(NVS_CONFIG_P3_STRATUM_PROTOCOL, value); break;
            default: setStratumProtocol(value); break;
        }
    }

    // ---- Indexed Stratum V2 accessors ----
    inline char* getSV2AuthorityPubkeyAt(int pool) {
        switch (pool) {
            case 1:  return getFallbackSV2AuthorityPubkey();
            case 2:  return cfgGetStrAlloc(NVS_CONFIG_P2_SV2_AUTHORITY_PUBKEY, "");
            case 3:  return cfgGetStrAlloc(NVS_CONFIG_P3_SV2_AUTHORITY_PUBKEY, "");
            default: return getSV2AuthorityPubkey();
        }
    }
    inline void setSV2AuthorityPubkeyAt(int pool, const char* value) {
        switch (pool) {
            case 1:  setFallbackSV2AuthorityPubkey(value); break;
            case 2:  cfgSetStr(NVS_CONFIG_P2_SV2_AUTHORITY_PUBKEY, value); break;
            case 3:  cfgSetStr(NVS_CONFIG_P3_SV2_AUTHORITY_PUBKEY, value); break;
            default: setSV2AuthorityPubkey(value); break;
        }
    }
    inline uint16_t getSV2ChannelTypeAt(int pool) {
        switch (pool) {
            case 1:  return getFallbackSV2ChannelType();
            case 2:  return cfgGetU16(NVS_CONFIG_P2_SV2_CHANNEL_TYPE, 0);
            case 3:  return cfgGetU16(NVS_CONFIG_P3_SV2_CHANNEL_TYPE, 0);
            default: return getSV2ChannelType();
        }
    }
    inline void setSV2ChannelTypeAt(int pool, uint16_t value) {
        switch (pool) {
            case 1:  setFallbackSV2ChannelType(value); break;
            case 2:  cfgSetU16(NVS_CONFIG_P2_SV2_CHANNEL_TYPE, value); break;
            case 3:  cfgSetU16(NVS_CONFIG_P3_SV2_CHANNEL_TYPE, value); break;
            default: setSV2ChannelType(value); break;
        }
    }
    inline bool isSV2RequireAuthAt(int pool) {
        switch (pool) {
            case 1:  return isFallbackSV2RequireAuth();
            case 2:  return cfgGetU16(NVS_CONFIG_P2_SV2_REQUIRE_AUTH, 0) != 0;
            case 3:  return cfgGetU16(NVS_CONFIG_P3_SV2_REQUIRE_AUTH, 0) != 0;
            default: return isSV2RequireAuth();
        }
    }
    inline void setSV2RequireAuthAt(int pool, bool value) {
        switch (pool) {
            case 1:  setFallbackSV2RequireAuth(value); break;
            case 2:  cfgSetU16(NVS_CONFIG_P2_SV2_REQUIRE_AUTH, value ? 1 : 0); break;
            case 3:  cfgSetU16(NVS_CONFIG_P3_SV2_REQUIRE_AUTH, value ? 1 : 0); break;
            default: setSV2RequireAuth(value); break;
        }
    }

    // ---- Quad-pool weights (relative share, 0 = pool idle) ----
    inline uint16_t getPoolWeight(int pool) {
        switch (pool) {
            case 0:  return cfgGetU16(NVS_CONFIG_POOL_WEIGHT0, 25);
            case 1:  return cfgGetU16(NVS_CONFIG_POOL_WEIGHT1, 25);
            case 2:  return cfgGetU16(NVS_CONFIG_POOL_WEIGHT2, 25);
            case 3:  return cfgGetU16(NVS_CONFIG_POOL_WEIGHT3, 25);
            default: return 25;
        }
    }
    inline void setPoolWeight(int pool, uint16_t value) {
        switch (pool) {
            case 0:  cfgSetU16(NVS_CONFIG_POOL_WEIGHT0, value); break;
            case 1:  cfgSetU16(NVS_CONFIG_POOL_WEIGHT1, value); break;
            case 2:  cfgSetU16(NVS_CONFIG_POOL_WEIGHT2, value); break;
            case 3:  cfgSetU16(NVS_CONFIG_POOL_WEIGHT3, value); break;
            default: break;
        }
    }

    // 0 = disabled, 1 = Basic (address present), 2 = Extended (address present + fee <= maxFee)
    inline void setCoinbaseVerifyMode(int pool, uint16_t v) {
        switch (pool) {
            case 1:  cfgSetU16(NVS_CONFIG_FB_COINBASE_VERIFY_MODE, v); break;
            case 2:  cfgSetU16(NVS_CONFIG_P2_COINBASE_VERIFY_MODE, v); break;
            case 3:  cfgSetU16(NVS_CONFIG_P3_COINBASE_VERIFY_MODE, v); break;
            default: cfgSetU16(NVS_CONFIG_COINBASE_VERIFY_MODE, v); break;
        }
    }
    inline uint16_t getCoinbaseVerifyMode(int pool = 0) {
        switch (pool) {
            case 1:  return cfgGetU16(NVS_CONFIG_FB_COINBASE_VERIFY_MODE, 0);
            case 2:  return cfgGetU16(NVS_CONFIG_P2_COINBASE_VERIFY_MODE, 0);
            case 3:  return cfgGetU16(NVS_CONFIG_P3_COINBASE_VERIFY_MODE, 0);
            default: return cfgGetU16(NVS_CONFIG_COINBASE_VERIFY_MODE, 0);
        }
    }
    inline void setCoinbaseMaxFee(int pool, uint16_t v) {
        switch (pool) {
            case 1:  cfgSetU16(NVS_CONFIG_FB_COINBASE_MAX_FEE, v); break;
            case 2:  cfgSetU16(NVS_CONFIG_P2_COINBASE_MAX_FEE, v); break;
            case 3:  cfgSetU16(NVS_CONFIG_P3_COINBASE_MAX_FEE, v); break;
            default: cfgSetU16(NVS_CONFIG_COINBASE_MAX_FEE, v); break;
        }
    }
    // stored as tenths of percent: 5 = 0.5%, 30 = 3.0%
    inline uint16_t getCoinbaseMaxFee(int pool = 0) {
        switch (pool) {
            case 1:  return cfgGetU16(NVS_CONFIG_FB_COINBASE_MAX_FEE, 30);
            case 2:  return cfgGetU16(NVS_CONFIG_P2_COINBASE_MAX_FEE, 30);
            case 3:  return cfgGetU16(NVS_CONFIG_P3_COINBASE_MAX_FEE, 30);
            default: return cfgGetU16(NVS_CONFIG_COINBASE_MAX_FEE, 30);
        }
    }
    inline void setCoinbaseVerifyForce(int pool, bool v) {
        switch (pool) {
            case 1:  cfgSetU16(NVS_CONFIG_FB_COINBASE_VERIFY_FORCE, v ? 1 : 0); break;
            case 2:  cfgSetU16(NVS_CONFIG_P2_COINBASE_VERIFY_FORCE, v ? 1 : 0); break;
            case 3:  cfgSetU16(NVS_CONFIG_P3_COINBASE_VERIFY_FORCE, v ? 1 : 0); break;
            default: cfgSetU16(NVS_CONFIG_COINBASE_VERIFY_FORCE, v ? 1 : 0); break;
        }
    }
    inline bool getCoinbaseVerifyForce(int pool = 0) {
        switch (pool) {
            case 1:  return cfgGetU16(NVS_CONFIG_FB_COINBASE_VERIFY_FORCE, 0) != 0;
            case 2:  return cfgGetU16(NVS_CONFIG_P2_COINBASE_VERIFY_FORCE, 0) != 0;
            case 3:  return cfgGetU16(NVS_CONFIG_P3_COINBASE_VERIFY_FORCE, 0) != 0;
            default: return cfgGetU16(NVS_CONFIG_COINBASE_VERIFY_FORCE, 0) != 0;
        }
    }

    void migrate_config();
}
