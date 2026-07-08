#include "decode.hpp"

namespace cpu_gpu_1024::modules::cpu {

DecodedCpuOp Decode::split(std::uint64_t raw) {
    return {
        static_cast<CpuOp>(raw & 0xFFU),
        static_cast<std::uint8_t>((raw >> 8U) & 0xFFU),
        static_cast<std::uint8_t>((raw >> 16U) & 0xFFU),
        raw >> 24U
    };
}

} // namespace cpu_gpu_1024::modules::cpu
