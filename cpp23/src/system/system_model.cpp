#include "system_model.hpp"

namespace cpu_gpu_1024 {

void SystemModel::reset() {
    board = {};
    ram = {};
    firmware = {};
    storage = {};
    power = {};
    cooling = {};
    cpu = nullptr;
    gpu = nullptr;
}

} // namespace cpu_gpu_1024
