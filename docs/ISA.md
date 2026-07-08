# ISA Placeholder

This document defines the current opcode format for the CPU and the GPU scaffold.

## 1. CPU opcode format
Each instruction is one qword.

Layout:

- op: bits 0..7
- dst: bits 8..15
- src: bits 16..23
- imm: bits 24..63

Semantics:

- `HALT (0xFF)` stops execution.
- `MOV_IMM (0x01)` loads the low qword of `imm` into `R[dst]` and clears the rest of the 1024-bit register.
- `ADD (0x02)` performs `R[dst] += R[src]`.
- `SUB (0x03)` performs `R[dst] -= R[src]`.
- `BEQ (0x04)` compares `R[dst]` and `R[src]`, then branches to the qword index stored in the next memory slot if they are equal.

## 2. GPU opcode format
The GPU scaffold uses the same qword layout.

Current semantics:

- `HALT (0xFF)` ends dispatch.
- `VCOPY (0x10)` copies one 1024-bit vector register to another.
- `VADD (0x11)` adds one 1024-bit vector register into another.

## 3. Extension plan
- Add logical ops and shifts.
- Add load/store once a shared RAM model exists.
- Expand immediate handling so a full 1024-bit constant can be loaded from multiple qwords.
