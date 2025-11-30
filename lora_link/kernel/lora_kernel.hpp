#pragma once
#include <cstdint>
#include "data/snapshot.hpp"

namespace lora {

struct RadioState;

using RxCallback = void(*)(const std::uint8_t* data, std::uint8_t len, LinkMetrics metrics);

bool radio_init(RadioState*& state, const LoraConfig& cfg, RxCallback cb);
void radio_set_config(RadioState& state, const LoraConfig& cfg);
bool radio_send(RadioState& state, const std::uint8_t* data, std::uint8_t len);
void radio_poll(RadioState& state);
void radio_close(RadioState*& state);

}

