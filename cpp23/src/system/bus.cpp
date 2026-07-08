#include "bus.hpp"

namespace cpu_gpu_1024::system {

void Bus::init(BusEndpoint& endpoint) {
    endpoint = {};
}

void Bus::connect(BusEndpoint& endpoint, void* component, std::uint64_t port, BusKind mode) {
    endpoint.component = component;
    endpoint.port = port;
    endpoint.mode = mode;
}

bool Bus::connected(const BusEndpoint& endpoint) {
    return endpoint.component != nullptr;
}

} // namespace cpu_gpu_1024::system
