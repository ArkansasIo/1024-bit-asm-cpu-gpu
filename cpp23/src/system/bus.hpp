#pragma once

#include "../../include/system.hpp"

namespace cpu_gpu_1024::system {

struct Bus final {
    static void init(BusEndpoint& endpoint);
    static void connect(BusEndpoint& endpoint, void* component, std::uint64_t port, BusKind mode);
    static bool connected(const BusEndpoint& endpoint);
};

} // namespace cpu_gpu_1024::system
