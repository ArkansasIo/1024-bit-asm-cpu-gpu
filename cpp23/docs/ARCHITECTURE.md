# C++23 Architecture Overview

The C++23 implementation mirrors the assembly scaffold with explicit types and standard library containers.

## CPU
- 16 general-purpose 1024-bit registers
- opcode memory stream
- move/add/sub/branch behavior

## GPU
- vector register file
- kernel dispatch stream
- copy/add behavior

## System
- motherboard layout
- RAM, firmware, storage, power, cooling

## Implementation style
- fixed-size containers
- no dynamic allocation in core state
- plain structs for system wiring
