#include "dispatch.hpp"

#include "fetch.hpp"
#include "vector_alu.hpp"

namespace cpu_gpu_1024::modules::gpu {

DecodedGpuOp Dispatch::split(std::uint64_t raw) {
    return {
        static_cast<GpuOp>(raw & 0xFFU),
        static_cast<std::uint8_t>((raw >> 8U) & 0xFFU),
        static_cast<std::uint8_t>((raw >> 16U) & 0xFFU)
    };
}

bool Dispatch::step(GpuState& state, std::span<const std::uint64_t> memory) {
    const auto raw = Fetch::read_opcode(memory, state.pc);
    const auto op = split(raw);

    auto& dst = state.vregs.at(op.dst);
    auto& src = state.vregs.at(op.src);

    switch (op.op) {
    case GpuOp::halt:
        return false;
    case GpuOp::vcopy:
        VectorAlu::copy(dst, src);
        ++state.pc;
        return true;
    case GpuOp::vadd:
        VectorAlu::add(dst, src);
        ++state.pc;
        return true;
    default:
        ++state.pc;
        return true;
    }
}

} // namespace cpu_gpu_1024::modules::gpu
