#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::cpu {

struct Execute final {
    static bool step(CpuState& state, std::span<const std::uint64_t> memory);
};

} // namespace cpu_gpu_1024::modules::cpu
