# 1024-bit CPU/GPU C++23

This directory mirrors the assembly scaffold in modern C++23.

It models:
- a 1024-bit CPU with 16-limb registers
- a GPU-style dispatch engine with vector registers
- board-level components like motherboard, RAM, firmware, storage, power, and cooling

The tree is organized as a small library-style project with headers, source files, docs, UML, examples, and tests.

## Layout
- `include/` - shared types and constants
- `src/` - CPU, GPU, and system source files
- `docs/` - architecture and design notes
- `design/` - reference survey and implementation plan
- `uml/` - PlantUML diagrams
- `examples/` - sample programs
- `tests/` - smoke test scaffolding
- `CMakeLists.txt` - C++23 build entry point
