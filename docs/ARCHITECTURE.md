# Architecture Design (Draft)

## 1. Representation of 1024-bit values
A 1024-bit integer is stored as **16 limbs**, each limb is a 64-bit word:

- `value = Σ limb[i] * 2^(64*i)` for i=0..15

In both CPU and GPU skeletons:
- CPU: `regfile` holds 16×(16×u64) = 256 u64 words total (16 registers)
- GPU: `vregfile` holds N vectors × 16 limbs

## 2. CPU model
### 2.1 State
- `pc` : qword index into `memory[]` (opcode stream)
- `regfile`: 16 general-purpose 1024-bit registers

### 2.2 Helpers (implemented)
- `mov_reg_1024(dst, src)`
- `add_reg_1024(dst, src)`
- `sub_reg_1024(dst, src)` (borrow via CF)
- `cmp_reg_1024_eq(a, b)` returning `rax=1` if equal else `0`

### 2.3 ISA scaffold (placeholder)
Opcode fields (qword):
- bits 0..7   : op
- bits 8..15  : dst
- bits 16..23 : src
- bits 24..63 : imm (unused for now)

Example ops (placeholder constants):
- `OP_MOV_IMM (0x01)`
- `OP_ADD (0x02)`
- `OP_SUB (0x03)`
- `OP_BEQ    (0x04)`

## 3. GPU model
### 3.1 State
- `pc` : qword index into control `memory[]`
- `vregfile`: vector register file
- `work_items`, `current_wi`: dispatch loop counters

### 3.2 Kernel ops (implemented helpers)
- `copy_vreg_1024(dst, src)`
- `add_vreg_1024(dst, src)`

### 3.3 Kernel dispatch scaffold
For now the GPU runs a fixed pseudo-kernel each work-item:
- `v0 += v1`

Next: decode a kernel program from `memory[]` and map work-item IDs to vector indices.

## 4. Memory model (current)
- `memory[]` is an array of qwords stored in `.data`.
- CPU uses it as an opcode stream.
- GPU uses it as a control stream.

Next: introduce an explicit shared RAM region abstraction.

