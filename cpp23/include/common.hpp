#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <string_view>

namespace cpu_gpu_1024 {

using Limb = std::uint64_t;
using WideWord = std::array<Limb, 16>;

inline constexpr std::size_t limb_count = 16;
inline constexpr std::size_t cpu_register_count = 16;
inline constexpr std::size_t gpu_vector_count = 8;
inline constexpr std::size_t bytes_per_wide_word = limb_count * sizeof(Limb);

enum class ComponentKind : std::uint8_t {
    motherboard = 1,
    cpu = 2,
    gpu = 3,
    ram = 4,
    firmware = 5,
    storage = 6,
    bus = 7,
    power = 8,
    cooling = 9
};

enum class BusKind : std::uint8_t {
    memory = 1,
    command = 2,
    expansion = 3,
    storage = 4
};

enum class MemoryRole : std::uint8_t {
    opcode_stream = 1,
    shared_ram = 2,
    firmware_rom = 3,
    storage_image = 4
};

enum class ExecMode : std::uint8_t {
    cpu = 1,
    gpu = 2,
    boot = 3
};

enum class CpuOp : std::uint8_t {
    halt = 0xFF,
    mov_imm = 0x01,
    add = 0x02,
    sub = 0x03,
    beq = 0x04
};

enum class GpuOp : std::uint8_t {
    halt = 0xFF,
    vcopy = 0x10,
    vadd = 0x11
};

constexpr std::uint64_t encode_cpu_op(CpuOp op, std::uint8_t dst, std::uint8_t src, std::uint64_t imm) {
    return static_cast<std::uint64_t>(op)
        | (static_cast<std::uint64_t>(dst) << 8U)
        | (static_cast<std::uint64_t>(src) << 16U)
        | (imm << 24U);
}

constexpr std::uint64_t encode_gpu_op(GpuOp op, std::uint8_t dst, std::uint8_t src) {
    return static_cast<std::uint64_t>(op)
        | (static_cast<std::uint64_t>(dst) << 8U)
        | (static_cast<std::uint64_t>(src) << 16U);
}

} // namespace cpu_gpu_1024
