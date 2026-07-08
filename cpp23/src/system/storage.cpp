#include "storage.hpp"

namespace cpu_gpu_1024::system {

void Storage::init(StorageDevice& device) {
    device = {};
}

void Storage::set_capacity(StorageDevice& device, std::uint64_t capacity) {
    device.capacity = capacity;
}

} // namespace cpu_gpu_1024::system
