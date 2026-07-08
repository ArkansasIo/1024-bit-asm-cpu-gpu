#include "../../include/firmware.hpp"
#include "../../include/os.hpp"

int main() {
    using namespace cpu_gpu_1024;

    CmosMemory cmos;
    NvramImage nvram;
    BiosController bios;
    bios.attach(cmos, nvram);

    SystemState system{};
    MotherboardLayout board{};
    MemoryRegion ram{};
    MemoryRegion firmware{};
    system.board = &board;
    system.ram = &ram;
    system.firmware = &firmware;

    OperatingSystem os;
    os.api.attach(cmos, nvram);
    os.boot(bios, system);
    return os.kernel.spawn("init") != 0 ? 0 : 1;
}
