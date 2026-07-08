#pragma once

#include <span>

#include "../../include/system.hpp"

namespace cpu_gpu_1024 {

class Cpu1024 final {
public:
    CpuState state{};
    std::array<std::uint64_t, 256> opcode_memory{};

    Cpu1024();

    void reset();
    void load_program(std::span<const std::uint64_t> program);
    bool step();
    void run();

private:
    static void zero_word(WideWord& word);
    static void copy_word(WideWord& dst, const WideWord& src);
    static void add_word(WideWord& dst, const WideWord& src);
    static void sub_word(WideWord& dst, const WideWord& src);
    static bool equal_word(const WideWord& a, const WideWord& b);
    static void load_imm64(WideWord& dst, std::uint64_t imm);
};

} // namespace cpu_gpu_1024
