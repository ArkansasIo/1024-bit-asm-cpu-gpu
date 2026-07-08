#include "fetch.hpp"

namespace cpu_gpu_1024::modules::gpu {

std::uint64_t Fetch::read_opcode(std::span<const std::uint64_t> memory, std::uint64_t pc) {
    return memory[static_cast<std::size_t>(pc)];
}

} // namespace cpu_gpu_1024::modules::gpu
