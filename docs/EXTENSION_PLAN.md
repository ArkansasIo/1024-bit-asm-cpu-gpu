# Extension Plan

## 1. CPU
Planned CPU additions:

- load/store instructions
- bitwise logic instructions
- shifts and rotates
- compare-and-branch variants
- multi-qword immediate loading

## 2. GPU
Planned GPU additions:

- decode a small kernel program from `memory[]`
- index vector registers by work-item ID
- add per-work-item branching
- add kernel parameters and shared memory access

## 3. Memory
Planned memory additions:

- explicit RAM region
- instruction memory separated from data memory
- basic bounds checks for read/write helpers

## 4. Tooling
Planned tooling additions:

- a build script for NASM and the linker
- a small validation program for the opcode encoders
- diagram updates when the ISA expands
