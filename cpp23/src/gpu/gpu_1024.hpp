#pragma once

#include <span>

#include "../../include/system.hpp"

namespace cpu_gpu_1024 {

class Gpu1024 final {
public:
    GpuState state{};
    std::array<std::uint64_t, 128> control_memory{};

    Gpu1024();

    void reset();
    void load_kernel(std::span<const std::uint64_t> program);
    bool step();
    void dispatch();

private:
    static void copy_word(WideWord& dst, const WideWord& src);
    static void add_word(WideWord& dst, const WideWord& src);
};

} // namespace cpu_gpu_1024
