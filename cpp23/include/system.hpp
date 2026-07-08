#pragma once

#include "common.hpp"

namespace cpu_gpu_1024 {

struct CpuState {
    std::uint64_t pc{};
    std::uint64_t sp{};
    std::array<WideWord, cpu_register_count> regs{};
    std::uint64_t flags{};
    ExecMode mode{ExecMode::boot};
};

struct GpuState {
    std::uint64_t pc{};
    std::uint64_t work_items{};
    std::uint64_t current_wi{};
    std::array<WideWord, gpu_vector_count> vregs{};
    ExecMode mode{ExecMode::boot};
};

struct MemoryRegion {
    std::uint64_t base{};
    std::uint64_t size{};
    MemoryRole role{MemoryRole::shared_ram};
    std::uint64_t flags{};
    std::uint64_t cursor{};
};

struct BusEndpoint {
    void* component{};
    std::uint64_t port{};
    BusKind mode{BusKind::command};
};

struct MotherboardLayout {
    void* cpu{};
    void* gpu{};
    void* ram{};
    void* firmware{};
    void* storage{};
    void* power{};
    void* cooling{};
    void* bus{};
    std::uint64_t clock_hz{};
};

struct PowerState {
    std::uint64_t voltage_mv{};
    std::uint64_t current_ma{};
    std::uint64_t thermal_limit{};
    bool enabled{};
};

struct CoolingState {
    std::uint64_t fan_rpm{};
    std::uint64_t temp_c{};
    std::uint64_t policy{};
    bool enabled{};
};

struct StorageDevice {
    std::uint64_t kind{};
    std::uint64_t capacity{};
    std::uint64_t io_mode{};
    std::uint64_t base_lba{};
};

struct SystemState {
    MotherboardLayout* board{};
    CpuState* cpu{};
    GpuState* gpu{};
    MemoryRegion* ram{};
    MemoryRegion* firmware{};
    StorageDevice* storage{};
    PowerState* power{};
    CoolingState* cooling{};
};

} // namespace cpu_gpu_1024
