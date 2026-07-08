# Architecture Design

## 1. Representation of 1024-bit values
A 1024-bit integer is stored as 16 limbs, where each limb is a 64-bit word.

Value layout:

- `value = sum(limb[i] * 2^(64*i))` for `i = 0..15`

Current storage model:

- CPU `regfile` holds 16 registers, each register is 16 qwords wide.
- GPU `vregfile` holds vector registers using the same 16-limb layout.

## 2. CPU model
### 2.1 State
- `pc` is a qword index into `memory[]`.
- `regfile` stores 16 general-purpose 1024-bit registers.

### 2.2 Helpers
Implemented helper routines:

- `zero_reg_1024(reg)`
- `mov_reg_1024(dst, src)`
- `add_reg_1024(dst, src)`
- `sub_reg_1024(dst, src)`
- `cmp_reg_1024_eq(a, b)`
- `load_reg_imm64(dst, imm64)`

### 2.3 Opcode layout
Opcode qword layout:

- bits 0..7: op
- bits 8..15: dst
- bits 16..23: src
- bits 24..63: imm

Current opcode set:

- `OP_HALT (0xFF)`
- `OP_MOV_IMM (0x01)`
- `OP_ADD (0x02)`
- `OP_SUB (0x03)`
- `OP_BEQ (0x04)`

## 3. GPU model
### 3.1 State
- `pc` is a qword index into the control `memory[]`.
- `vregfile` stores the vector register file.
- `work_items` and `current_wi` track dispatch progress.

### 3.2 Helpers
Implemented helper routines:

- `copy_vreg_1024(dst, src)`
- `add_vreg_1024(dst, src)`

### 3.3 Dispatch model
The current GPU loop executes a simple kernel program over each work-item.

The default kernel is:

- `v0 += v1`

The next step is to decode a richer kernel program from `memory[]` and use work-item IDs to index vector lanes.

## 4. Memory model
- `memory[]` is an array of qwords stored in `.data`.
- CPU treats it as an opcode stream.
- GPU treats it as a kernel control stream.

There is no shared RAM abstraction yet.
