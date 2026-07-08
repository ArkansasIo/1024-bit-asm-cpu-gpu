#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024::system {

struct Ram final {
    static void init(MemoryRegion& region, std::uint64_t base, std::uint64_t size, MemoryRole role);
    static bool contains(const MemoryRegion& region, std::uint64_t address);
    static std::uint64_t advance(MemoryRegion& region, std::uint64_t delta);
};

} // namespace cpu_gpu_1024::system
