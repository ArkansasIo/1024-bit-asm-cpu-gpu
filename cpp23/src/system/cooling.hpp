#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024::system {

struct Cooling final {
    static void init(CoolingState& cooling);
    static void enable(CoolingState& cooling);
    static void set_temperature(CoolingState& cooling, std::uint64_t temp_c);
    static void set_fan(CoolingState& cooling, std::uint64_t rpm);
};

} // namespace cpu_gpu_1024::system
