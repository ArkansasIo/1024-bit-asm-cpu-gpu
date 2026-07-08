#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::gpu {

struct VectorAlu final {
    static void copy(WideWord& dst, const WideWord& src);
    static void add(WideWord& dst, const WideWord& src);
};

} // namespace cpu_gpu_1024::modules::gpu
