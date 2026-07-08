#pragma once

#include "../../../include/system.hpp"

namespace cpu_gpu_1024::modules::system {

struct Interconnect final {
    static void connect(BusEndpoint& endpoint, void* component, std::uint64_t port, BusKind mode);
    static void clear(BusEndpoint& endpoint);
};

} // namespace cpu_gpu_1024::modules::system
