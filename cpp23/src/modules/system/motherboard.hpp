#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::system {

struct Motherboard final {
    static void clear(MotherboardLayout& layout);
    static void set_clock(MotherboardLayout& layout, std::uint64_t hz);
    static void attach_cpu(MotherboardLayout& layout, void* cpu);
    static void attach_gpu(MotherboardLayout& layout, void* gpu);
    static void attach_ram(MotherboardLayout& layout, void* ram);
};

} // namespace cpu_gpu_1024::modules::system
