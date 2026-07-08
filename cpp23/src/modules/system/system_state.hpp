#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::system {

struct SystemStateModule final {
    static void reset(SystemState& state);
};

} // namespace cpu_gpu_1024::modules::system
