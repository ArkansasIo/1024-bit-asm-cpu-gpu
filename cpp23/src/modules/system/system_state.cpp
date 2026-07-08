#include "system_state.hpp"

namespace cpu_gpu_1024::modules::system {

void SystemStateModule::reset(SystemState& state) {
    state = {};
}

} // namespace cpu_gpu_1024::modules::system
