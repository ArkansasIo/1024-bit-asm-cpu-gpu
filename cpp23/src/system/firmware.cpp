#include "firmware.hpp"

namespace cpu_gpu_1024::system {

void Firmware::init(MemoryRegion& region, std::uint64_t base, std::uint64_t size) {
    region.base = base;
    region.size = size;
    region.role = MemoryRole::firmware_rom;
    region.flags = 0;
    region.cursor = 0;
}

} // namespace cpu_gpu_1024::system
