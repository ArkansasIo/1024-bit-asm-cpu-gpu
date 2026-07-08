# 1024-bit CPU/GPU asm

This repository contains NASM-style assembly for a simple 1024-bit CPU model and a matching GPU-style dispatch model.

Each 1024-bit value is represented as 16 64-bit limbs.

## Files
- `cpu_1024.asm` - CPU emulator scaffold with 1024-bit helpers and a small opcode loop.
- `gpu_1024.asm` - GPU dispatch scaffold with 1024-bit vector helpers and a simple kernel loop.
- `src/` - split-out source and include tree for CPU, GPU, and system components.
- `docs/ARCHITECTURE.md` - architecture overview.
- `docs/ISA.md` - opcode layout and instruction notes.
- `docs/MULTIPLICATION_WIDTHS.md` - 1024-bit multiply rules for 8/16/32/64-bit scalars.
- `docs/SHIFT_BY_64.md` - limb-aligned shift and power-of-two multiply rules.
- `docs/BIOS_CMOS_OS.md` - BIOS, CMOS, NVRAM, API, GUI, and OS model.
- `docs/MEMORY_MODEL.md` - register and memory model.
- `docs/EXTENSION_PLAN.md` - next-step design notes.
- `docs/L0_TO_L10_CASH.md` - level 0 to 10 cash schedule.
- `docs/SYSTEM_COMPONENTS.md` - motherboard, RAM, storage, power, and bus overview.
- `docs/REPO_LAYOUT.md` - directory map for the full scaffold.
- `design/` - external reference survey and design notes.
- `scripts/` - build helper scripts.
- `examples/` - sample CPU/GPU programs.
- `tests/` - smoke-test scaffold.
- `include/` - shared constants and structure declarations.
- `src/types/`, `src/structs/`, `src/modules/` - type, struct, and module scaffolding.
- `cpp23/` - parallel C++23 implementation tree.
- `uml/*.puml` - PlantUML diagrams for the CPU, GPU, memory model, and system components.

## Build
You need NASM and a 64-bit linker.

Example on Linux or WSL:

```bat
nasm -felf64 cpu_1024.asm -o cpu_1024.o
ld cpu_1024.o -o cpu_1024

nasm -felf64 gpu_1024.asm -o gpu_1024.o
ld gpu_1024.o -o gpu_1024
```

## Status
The core helpers are in place:
- CPU: move, add, subtract, compare, immediate load
- GPU: copy, add, dispatch loop

The project is still a scaffold, but the files now line up with the design docs and diagrams.
