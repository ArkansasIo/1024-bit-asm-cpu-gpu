# ISA Placeholder (Draft)

This document defines the planned opcode format for the CPU and GPU scaffolds.

## 1. CPU opcode format (qword)
Layout (little-endian bit positions):

- op   : bits 0..7
- dst  : bits 8..15
- src  : bits 16..23
- imm  : bits 24..63

Semantics:

- `HALT (op=0xFF)`
  - stop execution

- `MOV_IMM (op=0x01)`
  - `R[dst] = imm` (imm treated as truncated to 1024-bit immediate pattern for now)
  - next qword(s) can be added later for full 1024-bit immediates.

- `ADD (op=0x02)`
  - `R[dst] += R[src]`

- `SUB (op=0x03)`
  - `R[dst] -= R[src]`

- `BEQ (op=0x04)`
  - compare `R[dst] == R[src]` and if equal, branch to `target`
  - target is currently expected in the next qword (or imm can be repurposed later).

## 2. Extension plan
- Add more ALU ops (AND/OR/XOR, shifts, mul placeholder)
- Add load/store ops once a shared RAM model exists.
- Add full 1024-bit immediates using multiple qwords (e.g., 16 qwords follow the instruction).

