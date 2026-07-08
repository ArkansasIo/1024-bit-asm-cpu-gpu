#include "../../include/firmware.hpp"

int main() {
    using namespace cpu_gpu_1024;

    CmosMemory cmos;
    NvramImage nvram;
    BiosController bios;
    bios.attach(cmos, nvram);
    bios.apply_defaults();

    SystemState system{};
    MotherboardLayout board{};
    MemoryRegion ram{};
    MemoryRegion firmware{};
    system.board = &board;
    system.ram = &ram;
    system.firmware = &firmware;

    return bios.boot(system).success ? 0 : 1;
}
