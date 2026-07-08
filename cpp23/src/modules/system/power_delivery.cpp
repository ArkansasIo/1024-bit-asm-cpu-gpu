#include "power_delivery.hpp"

namespace cpu_gpu_1024::modules::system {

void PowerDelivery::init(PowerState& power) {
    power = {};
}

void PowerDelivery::enable(PowerState& power) {
    power.enabled = true;
}

void PowerDelivery::set_voltage(PowerState& power, std::uint64_t mv) {
    power.voltage_mv = mv;
}

void PowerDelivery::set_current(PowerState& power, std::uint64_t ma) {
    power.current_ma = ma;
}

} // namespace cpu_gpu_1024::modules::system
