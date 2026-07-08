#include "../gpu/gpu_1024.hpp"

#include <array>

int main() {
    using namespace cpu_gpu_1024;

    Gpu1024 gpu;
    gpu.state.work_items = 4;
    const std::array<std::uint64_t, 2> kernel{
        encode_gpu_op(GpuOp::vadd, 0, 1),
        encode_gpu_op(GpuOp::halt, 0, 0)
    };
    gpu.load_kernel(kernel);
    gpu.dispatch();
    return 0;
}
