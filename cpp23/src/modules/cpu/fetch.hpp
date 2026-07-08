#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::cpu {

struct Fetch final {
    static std::uint64_t read_opcode(std::span<const std::uint64_t> memory, std::uint64_t pc);
};

} // namespace cpu_gpu_1024::modules::cpu
