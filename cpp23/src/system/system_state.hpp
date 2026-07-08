#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024::system {

struct SystemStateModel final {
    SystemState state{};

    void reset();
};

} // namespace cpu_gpu_1024::system
