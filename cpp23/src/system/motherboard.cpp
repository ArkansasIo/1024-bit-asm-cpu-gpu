#include "motherboard.hpp"

namespace cpu_gpu_1024::system {

void Motherboard::clear(MotherboardLayout& layout) {
    layout = {};
}

void Motherboard::set_clock(MotherboardLayout& layout, std::uint64_t hz) {
    layout.clock_hz = hz;
}

void Motherboard::attach_cpu(MotherboardLayout& layout, void* cpu) {
    layout.cpu = cpu;
}

void Motherboard::attach_gpu(MotherboardLayout& layout, void* gpu) {
    layout.gpu = gpu;
}

void Motherboard::attach_ram(MotherboardLayout& layout, void* ram) {
    layout.ram = ram;
}

} // namespace cpu_gpu_1024::system
