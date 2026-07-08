#include "../../include/os.hpp"

#include <algorithm>
#include <sstream>

namespace cpu_gpu_1024 {

void FirmwareApi::attach(CmosMemory& cmos, NvramImage& nvram) {
    cmos_ = &cmos;
    nvram_ = &nvram;
}

ApiResponse FirmwareApi::read_cmos(std::size_t index) const {
    if (cmos_ == nullptr) {
        return {false, 0, "cmos not attached"};
    }
    return {true, cmos_->read(index), "ok"};
}

ApiResponse FirmwareApi::write_cmos(std::size_t index, std::uint8_t value) {
    if (cmos_ == nullptr) {
        return {false, 0, "cmos not attached"};
    }
    cmos_->write(index, value);
    return {true, value, "ok"};
}

ApiResponse FirmwareApi::read_nvram(std::size_t index) const {
    if (nvram_ == nullptr) {
        return {false, 0, "nvram not attached"};
    }
    return {true, nvram_->read(index), "ok"};
}

ApiResponse FirmwareApi::write_nvram(std::size_t index, std::uint8_t value) {
    if (nvram_ == nullptr) {
        return {false, 0, "nvram not attached"};
    }
    nvram_->write(index, value);
    return {true, value, "ok"};
}

ApiResponse FirmwareApi::status() const {
    return {cmos_ != nullptr && nvram_ != nullptr, 0, "firmware api ready"};
}

void GuiRenderer::set_title(std::string_view title) {
    frame_.title.assign(title.begin(), title.end());
}

void GuiRenderer::set_status(std::string_view status) {
    frame_.status.assign(status.begin(), status.end());
}

void GuiRenderer::set_size(std::uint32_t width, std::uint32_t height) {
    frame_.width = width;
    frame_.height = height;
}

const GuiFrame& GuiRenderer::frame() const noexcept {
    return frame_;
}

std::string GuiRenderer::render_text() const {
    std::ostringstream out;
    out << "[" << frame_.title << "] "
        << frame_.width << "x" << frame_.height
        << " | " << frame_.status;
    return out.str();
}

void Kernel::reset() {
    processes_ = {};
    next_pid_ = 1;
}

std::uint32_t Kernel::spawn(std::string_view name) {
    for (auto& process : processes_) {
        if (!process.running) {
            process.pid = next_pid_++;
            process.name.assign(name.begin(), name.end());
            process.running = true;
            return process.pid;
        }
    }
    return 0;
}

bool Kernel::stop(std::uint32_t pid) {
    for (auto& process : processes_) {
        if (process.running && process.pid == pid) {
            process.running = false;
            return true;
        }
    }
    return false;
}

std::size_t Kernel::process_count() const noexcept {
    std::size_t count = 0;
    for (const auto& process : processes_) {
        if (process.running) {
            ++count;
        }
    }
    return count;
}

void OperatingSystem::boot(BiosController& bios, SystemState& system) {
    bios.apply_defaults();
    kernel.reset();
    gui.set_title("1024-bit OS");
    gui.set_status(bios.boot(system).success ? "booted" : "boot failed");
    api.status();
}

std::string OperatingSystem::status_text() const {
    std::ostringstream out;
    out << gui.render_text() << " | processes=" << kernel.process_count();
    return out.str();
}

} // namespace cpu_gpu_1024
