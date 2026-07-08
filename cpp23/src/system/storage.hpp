#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024::system {

struct Storage final {
    static void init(StorageDevice& device);
    static void set_capacity(StorageDevice& device, std::uint64_t capacity);
};

} // namespace cpu_gpu_1024::system
