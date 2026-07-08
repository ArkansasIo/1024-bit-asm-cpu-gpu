#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024 {

class Cpu1024;
class Gpu1024;

class SystemModel final {
public:
    Cpu1024* cpu{};
    Gpu1024* gpu{};
    MotherboardLayout board{};
    MemoryRegion ram{};
    MemoryRegion firmware{};
    StorageDevice storage{};
    PowerState power{};
    CoolingState cooling{};

    void reset();
};

} // namespace cpu_gpu_1024
