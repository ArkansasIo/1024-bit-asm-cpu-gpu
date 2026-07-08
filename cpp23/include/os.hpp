#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <string_view>

#include "firmware.hpp"

namespace cpu_gpu_1024 {

struct ApiResponse {
    bool ok{};
    std::uint64_t value{};
    std::string message;
};

class FirmwareApi final {
public:
    void attach(CmosMemory& cmos, NvramImage& nvram);
    ApiResponse read_cmos(std::size_t index) const;
    ApiResponse write_cmos(std::size_t index, std::uint8_t value);
    ApiResponse read_nvram(std::size_t index) const;
    ApiResponse write_nvram(std::size_t index, std::uint8_t value);
    ApiResponse status() const;

private:
    CmosMemory* cmos_{};
    NvramImage* nvram_{};
};

struct GuiFrame {
    bool visible{true};
    std::string title{"BIOS Setup"};
    std::string status{"Ready"};
    std::uint32_t width{1024};
    std::uint32_t height{768};
};

class GuiRenderer final {
public:
    void set_title(std::string_view title);
    void set_status(std::string_view status);
    void set_size(std::uint32_t width, std::uint32_t height);
    const GuiFrame& frame() const noexcept;
    std::string render_text() const;

private:
    GuiFrame frame_{};
};

struct Process {
    std::uint32_t pid{};
    std::string name;
    bool running{};
};

class Kernel final {
public:
    void reset();
    std::uint32_t spawn(std::string_view name);
    bool stop(std::uint32_t pid);
    std::size_t process_count() const noexcept;

private:
    static constexpr std::size_t max_processes = 16;
    std::array<Process, max_processes> processes_{};
    std::uint32_t next_pid_{1};
};

class OperatingSystem final {
public:
    FirmwareApi api;
    GuiRenderer gui;
    Kernel kernel;

    void boot(BiosController& bios, SystemState& system);
    std::string status_text() const;
};

} // namespace cpu_gpu_1024
