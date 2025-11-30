#pragma once
#include <cstdint>
#include "px4_link/data/telemetry.hpp"

namespace lora {

enum class PacketType : std::uint8_t {
    SnapshotRequest = 1,
    SnapshotReply = 2,
    PeriodicBeacon = 3
};

struct LinkMetrics {
    std::int16_t rssi_dbm;
    std::int8_t snr_db;
    std::uint8_t sf;
};

struct Snapshot {
    std::uint32_t seq;
    std::uint64_t drone_time_us;
    std::uint64_t gw_time_us;
    px4::LocalPosition local_position;
    px4::GpsPosition gps;
    LinkMetrics link;
};

struct LoraConfig {
    std::uint32_t broadcast_period_ms;
    std::uint8_t spreading_factor;
    std::uint32_t frequency_hz;
    std::uint8_t power_dbm;
};

}

