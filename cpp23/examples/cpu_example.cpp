#include "../src/cpu/cpu_1024.hpp"

#include <array>

int main() {
    using namespace cpu_gpu_1024;

    Cpu1024 cpu;
    const std::array<std::uint64_t, 4> program{
        encode_cpu_op(CpuOp::mov_imm, 0, 0, 7),
        encode_cpu_op(CpuOp::mov_imm, 1, 0, 5),
        encode_cpu_op(CpuOp::sub, 0, 1, 0),
        encode_cpu_op(CpuOp::halt, 0, 0, 0)
    };
    cpu.load_program(program);
    cpu.run();
    return 0;
}
