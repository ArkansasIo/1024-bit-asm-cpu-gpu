# C++23 Memory Model

1024-bit values are represented as 16 64-bit limbs.

## CPU
- 16 registers
- each register is 128 bytes

## GPU
- 8 vector registers in the scaffold
- same 16-limb representation

## System
- separate regions for RAM and firmware
- storage represented as metadata
