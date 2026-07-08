#include "vector_alu.hpp"

namespace cpu_gpu_1024::modules::gpu {

void VectorAlu::copy(WideWord& dst, const WideWord& src) {
    dst = src;
}

void VectorAlu::add(WideWord& dst, const WideWord& src) {
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

} // namespace cpu_gpu_1024::modules::gpu
