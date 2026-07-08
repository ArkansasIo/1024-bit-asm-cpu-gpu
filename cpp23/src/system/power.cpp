#include "power.hpp"

namespace cpu_gpu_1024::system {

void Power::init(PowerState& power) {
    power = {};
}

void Power::enable(PowerState& power) {
    power.enabled = true;
}

void Power::set_voltage(PowerState& power, std::uint64_t mv) {
    power.voltage_mv = mv;
}

void Power::set_current(PowerState& power, std::uint64_t ma) {
    power.current_ma = ma;
}

} // namespace cpu_gpu_1024::system
