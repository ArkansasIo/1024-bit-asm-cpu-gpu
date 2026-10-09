# 1024-Bit CPU + GPU Computer Platform

A research and prototyping project for a custom 1024-bit data-processing architecture, parallel compute engine, server/client platform, and operating-system stack.

> **Status:** architecture and software prototype. This repository does not claim to contain a fabricated 1024-bit silicon processor or production-ready operating system.

## Goals

- Define a 1024-bit architectural register/data path and a versioned instruction set.
- Provide a portable C++23 reference simulator before RTL/FPGA work.
- Define a GPU compute model with explicit parallel work groups and memory boundaries.
- Specify server and client hardware profiles.
- Build the OS in layers: boot/firmware interface, kernel core, memory manager, scheduler, device drivers, filesystem, networking, and user-space services.
- Keep hardware-specific code isolated behind interfaces so a simulator, FPGA prototype, and future board can share software components.

## Architecture

- `docs/ARCHITECTURE.md` — system overview and component boundaries.
- `docs/HARDWARE.md` — proposed server, client, and prototype hardware.
- `docs/ISA.md` — initial instruction-set principles.
- `docs/OPERATING_SYSTEM.md` — OS layers and implementation milestones.
- `docs/SERVER_CLIENT.md` — networked server/client model.
- `simulator/` — portable C++23 reference model (planned implementation).

## Important design choices

- **1024-bit datapath is not 1024-bit addressing.** Address width is independently defined; the initial design uses 64-bit virtual/physical addresses as a practical starting point.
- **Instruction length is versioned independently.** The architecture must explicitly distinguish a 1024-bit register from a 1024-bit instruction or a 1024-byte instruction.
- **GPU means parallel execution model first.** A software compute simulator comes before FPGA RTL or custom silicon.
- **No fabricated benchmark claims.** Performance, power, and area require a tested implementation and measured hardware.

## Development

Recommended host tools: C++23 compiler (Clang 17+, GCC 13+, or recent MSVC), CMake 3.25+, and Git. FPGA work later can use a suitable SystemVerilog toolchain and vendor tools.

## Roadmap

1. Freeze architectural terminology and instruction encoding.
2. Implement and test 1024-bit integer/vector primitives in the C++23 simulator.
3. Add instruction decoder, registers, memory bus, exceptions, and deterministic test programs.
4. Add GPU work-group simulator and host API.
5. Define a bootable minimal kernel target and emulator platform.
6. Add server services, client protocol, security model, and deployment packaging.
7. Prototype selected blocks in FPGA RTL and verify against the software reference.

## Safety and deployment

Treat the OS as experimental. Do not deploy it on production servers or expose its network services to the public internet until authentication, isolation, memory safety, update integrity, and threat-model testing are complete.
