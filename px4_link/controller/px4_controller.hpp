#pragma once
#include <cstdint>
#include "data/telemetry.hpp"

namespace px4 {

struct ControllerConfig {
    std::uint32_t max_hz;
};

struct ControllerState {
    std::uint64_t last_update_us;
    std::uint32_t last_seq;
    ControllerConfig config;
};

struct ControllerInput {
    TelemetryFrame frame;
};

struct ControllerOutput {
    bool forward_to_link;
    TelemetryFrame frame;
};

void controller_init(ControllerState& state, const ControllerConfig& cfg);
ControllerOutput controller_tick(ControllerState& state, const ControllerInput& in);

}

