#include "cpu_1024.hpp"

#include <algorithm>

namespace cpu_gpu_1024 {

Cpu1024::Cpu1024() {
    reset();
}

void Cpu1024::reset() {
    state = {};
    state.mode = ExecMode::cpu;
    opcode_memory.fill(0);
}

void Cpu1024::load_program(std::span<const std::uint64_t> program) {
    const auto count = std::min(program.size(), opcode_memory.size());
    std::copy_n(program.begin(), count, opcode_memory.begin());
}

void Cpu1024::zero_word(WideWord& word) {
    word.fill(0);
}

void Cpu1024::copy_word(WideWord& dst, const WideWord& src) {
    dst = src;
}

void Cpu1024::add_word(WideWord& dst, const WideWord& src) {
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

void Cpu1024::sub_word(WideWord& dst, const WideWord& src) {
    std::uint64_t borrow = 0;
    for (std::size_t i = 0; i < limb_count; ++i) {
        const auto lhs = dst[i];
        const auto rhs = src[i];
        const auto diff1 = lhs - rhs;
        const auto borrow1 = lhs < rhs;
        const auto diff2 = diff1 - borrow;
        const auto borrow2 = diff1 < borrow;
        dst[i] = diff2;
        borrow = static_cast<std::uint64_t>(borrow1 || borrow2);
    }
}

bool Cpu1024::equal_word(const WideWord& a, const WideWord& b) {
    return a == b;
}

void Cpu1024::load_imm64(WideWord& dst, std::uint64_t imm) {
    zero_word(dst);
    dst[0] = imm;
}

bool Cpu1024::step() {
    const auto raw = opcode_memory.at(static_cast<std::size_t>(state.pc));
    const auto op = static_cast<CpuOp>(raw & 0xFFU);
    const auto dst = static_cast<std::size_t>((raw >> 8U) & 0xFFU);
    const auto src = static_cast<std::size_t>((raw >> 16U) & 0xFFU);
    const auto imm = raw >> 24U;

    if (op == CpuOp::halt) {
        return false;
    }

    auto& dst_word = state.regs.at(dst);
    auto& src_word = state.regs.at(src);

    switch (op) {
    case CpuOp::mov_imm:
        load_imm64(dst_word, imm);
        ++state.pc;
        return true;
    case CpuOp::add:
        add_word(dst_word, src_word);
        ++state.pc;
        return true;
    case CpuOp::sub:
        sub_word(dst_word, src_word);
        ++state.pc;
        return true;
    case CpuOp::beq:
        if (equal_word(dst_word, src_word)) {
            state.pc = opcode_memory.at(static_cast<std::size_t>(state.pc + 1));
        } else {
            state.pc += 2;
        }
        return true;
    default:
        ++state.pc;
        return true;
    }
}

void Cpu1024::run() {
    while (step()) {
    }
}

} // namespace cpu_gpu_1024
