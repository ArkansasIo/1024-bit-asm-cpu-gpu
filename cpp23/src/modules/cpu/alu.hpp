#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::cpu {

struct Alu final {
    static void zero(WideWord& word);
    static void copy(WideWord& dst, const WideWord& src);
    static void add(WideWord& dst, const WideWord& src);
    static void sub(WideWord& dst, const WideWord& src);
    static bool equal(const WideWord& a, const WideWord& b);
    static void load_imm64(WideWord& dst, std::uint64_t imm);
};

} // namespace cpu_gpu_1024::modules::cpu
