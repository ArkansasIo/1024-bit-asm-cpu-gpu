#include "gpu_1024.hpp"

#include <algorithm>

namespace cpu_gpu_1024 {

Gpu1024::Gpu1024() {
    reset();
}

void Gpu1024::reset() {
    state = {};
    state.mode = ExecMode::gpu;
    control_memory.fill(0);
}

void Gpu1024::load_kernel(std::span<const std::uint64_t> program) {
    const auto count = std::min(program.size(), control_memory.size());
    std::copy_n(program.begin(), count, control_memory.begin());
}

void Gpu1024::copy_word(WideWord& dst, const WideWord& src) {
    dst = src;
}

void Gpu1024::add_word(WideWord& dst, const WideWord& src) {
    std::uint64_t carry = 0;
    for (std::size_t i = 0; i < limb_count; ++i) {
        const auto lhs = dst[i];
        const auto rhs = src[i];
        const auto sum1 = lhs + rhs;
        const auto carry1 = sum1 < lhs;
        const auto sum2 = sum1 + carry;
        const auto carry2 = sum2 < sum1;
        dst[i] = sum2;
        carry = static_cast<std::uint64_t>(carry1 || carry2);
    }
}

bool Gpu1024::step() {
    const auto raw = control_memory.at(static_cast<std::size_t>(state.pc));
    const auto op = static_cast<GpuOp>(raw & 0xFFU);
    const auto dst = static_cast<std::size_t>((raw >> 8U) & 0xFFU);
    const auto src = static_cast<std::size_t>((raw >> 16U) & 0xFFU);

    if (op == GpuOp::halt) {
        return false;
    }

    auto& dst_word = state.vregs.at(dst);
    auto& src_word = state.vregs.at(src);

    switch (op) {
    case GpuOp::vcopy:
        copy_word(dst_word, src_word);
        ++state.pc;
        return true;
    case GpuOp::vadd:
        add_word(dst_word, src_word);
        ++state.pc;
        return true;
    default:
        ++state.pc;
        return true;
    }
}

void Gpu1024::dispatch() {
    for (std::uint64_t wi = 0; wi < state.work_items; ++wi) {
        state.current_wi = wi;
        state.pc = 0;
        while (step()) {
        }
    }
}

} // namespace cpu_gpu_1024
