#include "ram_controller.hpp"

namespace cpu_gpu_1024::modules::system {

void RamController::init(MemoryRegion& region, std::uint64_t base, std::uint64_t size, MemoryRole role) {
    region.base = base;
    region.size = size;
    region.role = role;
    region.flags = 0;
    region.cursor = 0;
}

bool RamController::contains(const MemoryRegion& region, std::uint64_t address) {
    return address >= region.base && address < (region.base + region.size);
}

std::uint64_t RamController::advance(MemoryRegion& region, std::uint64_t delta) {
    region.cursor += delta;
    return region.cursor;
}

} // namespace cpu_gpu_1024::modules::system
