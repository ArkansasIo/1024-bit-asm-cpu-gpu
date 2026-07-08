#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::cpu {

struct DecodedCpuOp final {
    CpuOp op{};
    std::uint8_t dst{};
    std::uint8_t src{};
    std::uint64_t imm{};
};

struct Decode final {
    static DecodedCpuOp split(std::uint64_t raw);
};

} // namespace cpu_gpu_1024::modules::cpu
