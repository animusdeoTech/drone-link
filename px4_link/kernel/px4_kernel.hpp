#pragma once
#include <cstdint>
#include "data/telemetry.hpp"

namespace px4 {

struct KernelConfig {
    const char* device_name;
    std::uint32_t baudrate;
};

struct KernelState;

using TelemetryCallback = void(*)(const TelemetryFrame& frame);

bool kernel_init(KernelState*& state, const KernelConfig& cfg, TelemetryCallback cb);
void kernel_poll(KernelState& state);
void kernel_close(KernelState*& state);

}

