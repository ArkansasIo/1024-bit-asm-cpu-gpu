# Repository Layout

This project is organized as a small hardware-and-ISA scaffold.

## Top level
- `cpu_1024.asm` - runnable CPU emulator scaffold.
- `gpu_1024.asm` - runnable GPU dispatch scaffold.
- `README.md` - project overview.
- `TODO.md` - remaining work list.

## `docs/`
- `ARCHITECTURE.md` - high-level architecture.
- `ISA.md` - opcode layout.
- `MEMORY_MODEL.md` - register and memory model.
- `EXTENSION_PLAN.md` - future work.
- `SYSTEM_COMPONENTS.md` - motherboard and surrounding component overview.
- `TYPE_SYSTEM.md` - types, structs, and module conventions.
- `MODULE_INDEX.md` - module index.
- `REPO_LAYOUT.md` - this file.

## `design/`
External reference survey and design notes for CPU, GPU, CAD, and 1024-scale systems.

## `cpp23/`
Parallel C++23 implementation tree with source, docs, UML, design notes, examples, and tests.

## `src/`
Split source tree for component-level organization.

- `src/cpu/` - CPU-specific constants and module stubs.
- `src/gpu/` - GPU-specific constants and module stubs.
- `src/system/` - motherboard, RAM, storage, power, and bus stubs.
- `src/types/` - shared type constants.
- `src/structs/` - shared structure layouts.
- `src/modules/` - CPU, GPU, and system behavior modules.
- `src/README.md` - notes for the split source tree.

## `include/`
Shared constants and reusable definitions.

## `scripts/`
Build helper scripts and future automation entry points.

## `examples/`
Sample CPU and GPU source files.

## `tests/`
Smoke-test scaffolding.

## `uml/`
PlantUML diagrams for the CPU, GPU, memory model, and system components.
