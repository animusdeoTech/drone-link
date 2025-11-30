#pragma once
#include <cstdint>

namespace px4 {

struct Attitude {
    float roll_rad;
    float pitch_rad;
    float yaw_rad;
};

struct AngularRates {
    float roll_rate_rad_s;
    float pitch_rate_rad_s;
    float yaw_rate_rad_s;
};

struct LinearAcceleration {
    float x_m_s2;
    float y_m_s2;
    float z_m_s2;
};

struct LocalPosition {
    float x_m;
    float y_m;
    float z_m;
};

struct VelocityLocal {
    float vx_m_s;
    float vy_m_s;
    float vz_m_s;
};

struct GpsPosition {
    double lat_deg;
    double lon_deg;
    float alt_m;
    bool valid;
};

struct BatteryStatus {
    float voltage_v;
    float current_a;
    float remaining_pct;
};

struct TelemetryFrame {
    std::uint32_t seq;
    std::uint64_t drone_time_us;
    Attitude attitude;
    AngularRates angular_rates;
    LinearAcceleration acceleration;
    LocalPosition local_position;
    VelocityLocal local_velocity;
    GpsPosition gps;
    BatteryStatus battery;
};

}

