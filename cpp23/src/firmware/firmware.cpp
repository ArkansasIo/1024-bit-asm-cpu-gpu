#include "../../include/firmware.hpp"

#include <algorithm>

namespace cpu_gpu_1024 {

void CmosMemory::reset() {
    bytes_.fill(0);
}

std::uint8_t CmosMemory::read(std::size_t index) const {
    return bytes_.at(index);
}

void CmosMemory::write(std::size_t index, std::uint8_t value) {
    bytes_.at(index) = value;
}

void NvramImage::reset() {
    bytes_.fill(0);
}

std::uint8_t NvramImage::read(std::size_t index) const {
    return bytes_.at(index);
}

void NvramImage::write(std::size_t index, std::uint8_t value) {
    bytes_.at(index) = value;
}

BiosController::BiosController(BiosConfig config) : config_(std::move(config)) {}

void BiosController::attach(CmosMemory& cmos, NvramImage& nvram) {
    cmos_ = &cmos;
    nvram_ = &nvram;
}

void BiosController::apply_defaults() {
    if (cmos_) {
        cmos_->reset();
        cmos_->write(0, 0x10);
        cmos_->write(1, 0x24);
    }
    if (nvram_) {
        nvram_->reset();
    }
    config_.gui_enabled = true;
    config_.api_enabled = true;
    config_.screen_width = 1024;
    config_.screen_height = 768;
}

BootReport BiosController::boot(SystemState& system) const {
    if (system.board == nullptr || system.ram == nullptr) {
        return {false, "missing board or ram"};
    }

    if (system.firmware == nullptr) {
        return {false, "missing firmware region"};
    }

    return {true, "boot handoff complete"};
}

const BiosConfig& BiosController::config() const noexcept {
    return config_;
}

BiosConfig& BiosController::config() noexcept {
    return config_;
}

} // namespace cpu_gpu_1024
