#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024::system {

struct Power final {
    static void init(PowerState& power);
    static void enable(PowerState& power);
    static void set_voltage(PowerState& power, std::uint64_t mv);
    static void set_current(PowerState& power, std::uint64_t ma);
};

} // namespace cpu_gpu_1024::system
