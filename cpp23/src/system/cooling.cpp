#include "cooling.hpp"

namespace cpu_gpu_1024::system {

void Cooling::init(CoolingState& cooling) {
    cooling = {};
}

void Cooling::enable(CoolingState& cooling) {
    cooling.enabled = true;
}

void Cooling::set_temperature(CoolingState& cooling, std::uint64_t temp_c) {
    cooling.temp_c = temp_c;
}

void Cooling::set_fan(CoolingState& cooling, std::uint64_t rpm) {
    cooling.fan_rpm = rpm;
}

} // namespace cpu_gpu_1024::system
