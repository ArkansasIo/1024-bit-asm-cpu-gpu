#include "ram.hpp"

namespace cpu_gpu_1024::system {

void Ram::init(MemoryRegion& region, std::uint64_t base, std::uint64_t size, MemoryRole role) {
    region.base = base;
    region.size = size;
    region.role = role;
    region.flags = 0;
    region.cursor = 0;
}

bool Ram::contains(const MemoryRegion& region, std::uint64_t address) {
    return address >= region.base && address < (region.base + region.size);
}

std::uint64_t Ram::advance(MemoryRegion& region, std::uint64_t delta) {
    region.cursor += delta;
    return region.cursor;
}

} // namespace cpu_gpu_1024::system
