# Experimental Operating System

## Goal

Develop a small, auditable OS that can eventually boot on a supported FPGA/SoC platform. Early milestones run in a simulator or virtual machine. The initial host OS remains responsible for hardware access until the custom kernel has a tested boot and driver path.

## Layer plan

### 0. Host development environment
- C++23 simulator, CMake build, unit tests, sanitizers where available.
- Reproducible build metadata and versioned test vectors.

### 1. Firmware / boot contract
- Defined machine entry point and memory map.
- Boot information structure with RAM map, CPU features, and device descriptors.
- Serial console for early debugging.
- Signed/verified boot is a requirement before production deployment.

### 2. Kernel foundation
- Trap/interrupt entry and exit.
- Timer and basic scheduler.
- Physical page allocator, then virtual memory.
- User/kernel privilege separation.
- System call ABI and process/thread lifecycle.

### 3. Core services
- IPC and message queues.
- VFS abstraction and read-only initial filesystem.
- Logging, panic handling, crash dump format.
- Driver model and device discovery.

### 4. Drivers
- UART/console and timer first.
- Block storage and network interface next.
- GPU driver only after a stable command ABI and memory ownership model.
- IOMMU or equivalent DMA isolation where supported by hardware.

### 5. User space
- Init/service manager.
- Shell and diagnostic tools.
- Package format and update manager.
- Server daemon and client SDK/UI.
- Authentication, authorization, audit logs, and secure update signing.

## Security requirements before network exposure

- Memory-safe parsing for untrusted protocol inputs where possible.
- Authentication on every administrative endpoint.
- Least privilege for services and device access.
- Secure secret storage; never commit keys or passwords.
- Signed updates and rollback/recovery procedure.
- Fuzzing of syscalls, filesystem parsers, and network parsers.
- Threat model, dependency inventory, and documented vulnerability response.

## Completion criteria

The OS is not considered bootable until a clean build starts in a documented emulator/board, emits console output, handles a timer interrupt, enforces a privilege boundary, and passes a reproducible test suite. It is not production-ready until driver, security, reliability, and recovery testing is complete.
