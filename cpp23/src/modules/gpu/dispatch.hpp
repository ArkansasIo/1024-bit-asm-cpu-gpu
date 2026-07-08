#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::gpu {

struct DecodedGpuOp final {
    GpuOp op{};
    std::uint8_t dst{};
    std::uint8_t src{};
};

struct Dispatch final {
    static DecodedGpuOp split(std::uint64_t raw);
    static bool step(GpuState& state, std::span<const std::uint64_t> memory);
};

} // namespace cpu_gpu_1024::modules::gpu
