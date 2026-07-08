#include "../../include/firmware.hpp"
#include "../../include/os.hpp"

#include <iostream>

int main() {
    using namespace cpu_gpu_1024;

    CmosMemory cmos;
    NvramImage nvram;
    BiosController bios;
    bios.attach(cmos, nvram);
    bios.apply_defaults();

    MotherboardLayout board{};
    MemoryRegion ram{};
    MemoryRegion firmware{};
    SystemState system{};
    system.board = &board;
    system.ram = &ram;
    system.firmware = &firmware;

    const auto report = bios.boot(system);
    std::cout << (report.success ? "BIOS OK: " : "BIOS FAIL: ") << report.message << '\n';
    return report.success ? 0 : 1;
}
