#pragma once
#include <cstdint>
#include "data/snapshot.hpp"
#include "kernel/lora_kernel.hpp"

namespace lora {

struct ControllerState {
    std::uint32_t next_broadcast_ms;
    std::uint32_t next_seq;
    LoraConfig config;
};

struct ControllerInput {
    std::uint32_t now_ms;
    bool request_snapshot;
};

struct EncodedPacket {
    PacketType type;
    std::uint8_t len;
    std::uint8_t data[64];
};

struct ControllerOutput {
    bool send_packet;
    EncodedPacket packet;
};

void controller_init(ControllerState& state, const LoraConfig& cfg);
ControllerOutput controller_tick(ControllerState& state, const ControllerInput& in);
bool encode_snapshot_request(std::uint32_t seq, EncodedPacket& out);
bool encode_periodic_beacon(std::uint32_t seq, EncodedPacket& out);
bool decode_snapshot_reply(const std::uint8_t* data, std::uint8_t len, Snapshot& out);

}

