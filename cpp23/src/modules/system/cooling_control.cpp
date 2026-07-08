#include "cooling_control.hpp"

namespace cpu_gpu_1024::modules::system {

void CoolingControl::init(CoolingState& cooling) {
    cooling = {};
}

void CoolingControl::enable(CoolingState& cooling) {
    cooling.enabled = true;
}

void CoolingControl::set_temperature(CoolingState& cooling, std::uint64_t temp_c) {
    cooling.temp_c = temp_c;
}

void CoolingControl::set_fan(CoolingState& cooling, std::uint64_t rpm) {
    cooling.fan_rpm = rpm;
}

} // namespace cpu_gpu_1024::modules::system
