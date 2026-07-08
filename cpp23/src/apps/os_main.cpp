#include "../../include/firmware.hpp"
#include "../../include/os.hpp"

#include <iostream>

int main() {
    using namespace cpu_gpu_1024;

    CmosMemory cmos;
    NvramImage nvram;
    BiosController bios;
    bios.attach(cmos, nvram);

    MotherboardLayout board{};
    MemoryRegion ram{};
    MemoryRegion firmware{};
    SystemState system{};
    system.board = &board;
    system.ram = &ram;
    system.firmware = &firmware;

    OperatingSystem os;
    os.api.attach(cmos, nvram);
    os.boot(bios, system);
    os.kernel.spawn("init");

    std::cout << os.status_text() << '\n';
    return 0;
}
