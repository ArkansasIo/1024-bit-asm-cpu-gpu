#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <string_view>

#include "system.hpp"

namespace cpu_gpu_1024 {

class CmosMemory final {
public:
    static constexpr std::size_t size = 256;

    void reset();
    std::uint8_t read(std::size_t index) const;
    void write(std::size_t index, std::uint8_t value);

private:
    std::array<std::uint8_t, size> bytes_{};
};

class NvramImage final {
public:
    static constexpr std::size_t size = 1024;

    void reset();
    std::uint8_t read(std::size_t index) const;
    void write(std::size_t index, std::uint8_t value);

private:
    std::array<std::uint8_t, size> bytes_{};
};

struct BiosConfig {
    bool gui_enabled{true};
    bool api_enabled{true};
    std::uint32_t screen_width{1024};
    std::uint32_t screen_height{768};
    std::uint64_t kernel_entry{0};
    std::uint64_t boot_device{0};
    std::string bios_name{"1024-bit BIOS"};
};

struct BootReport {
    bool success{};
    std::string message;
};

class BiosController final {
public:
    BiosController() = default;
    explicit BiosController(BiosConfig config);

    void attach(CmosMemory& cmos, NvramImage& nvram);
    void apply_defaults();
    BootReport boot(SystemState& system) const;
    const BiosConfig& config() const noexcept;
    BiosConfig& config() noexcept;

private:
    BiosConfig config_{};
    CmosMemory* cmos_{};
    NvramImage* nvram_{};
};

struct FirmwareSnapshot {
    FirmwareState state{};
    BiosConfig bios{};
};

} // namespace cpu_gpu_1024
