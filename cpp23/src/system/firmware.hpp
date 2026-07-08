#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024::system {

struct Firmware final {
    static void init(MemoryRegion& region, std::uint64_t base, std::uint64_t size);
};

} // namespace cpu_gpu_1024::system
