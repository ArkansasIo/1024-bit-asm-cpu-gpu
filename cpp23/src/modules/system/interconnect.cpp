#include "interconnect.hpp"

namespace cpu_gpu_1024::modules::system {

void Interconnect::connect(BusEndpoint& endpoint, void* component, std::uint64_t port, BusKind mode) {
    endpoint.component = component;
    endpoint.port = port;
    endpoint.mode = mode;
}

void Interconnect::clear(BusEndpoint& endpoint) {
    endpoint = {};
}

} // namespace cpu_gpu_1024::modules::system
