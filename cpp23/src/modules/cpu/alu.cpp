#include "alu.hpp"

namespace cpu_gpu_1024::modules::cpu {

void Alu::zero(WideWord& word) {
    word.fill(0);
}

void Alu::copy(WideWord& dst, const WideWord& src) {
    dst = src;
}

void Alu::add(WideWord& dst, const WideWord& src) {
    std::uint64_t carry = 0;
    for (std::size_t i = 0; i < limb_count; ++i) {
        const auto a = dst[i];
        const auto b = src[i];
        const auto sum1 = a + b;
        const auto c1 = sum1 < a;
        const auto sum2 = sum1 + carry;
        const auto c2 = sum2 < sum1;
        dst[i] = sum2;
        carry = static_cast<std::uint64_t>(c1 || c2);
    }
}

void Alu::sub(WideWord& dst, const WideWord& src) {
    std::uint64_t borrow = 0;
    for (std::size_t i = 0; i < limb_count; ++i) {
        const auto a = dst[i];
        const auto b = src[i];
        const auto diff1 = a - b;
        const auto b1 = a < b;
        const auto diff2 = diff1 - borrow;
        const auto b2 = diff1 < borrow;
        dst[i] = diff2;
        borrow = static_cast<std::uint64_t>(b1 || b2);
    }
}

bool Alu::equal(const WideWord& a, const WideWord& b) {
    return a == b;
}

void Alu::load_imm64(WideWord& dst, std::uint64_t imm) {
    zero(dst);
    dst[0] = imm;
}

} // namespace cpu_gpu_1024::modules::cpu
