# 1024-bit Multiplication Widths

This document describes how a 1024-bit value interacts with scalar widths of 8, 16, 32, and 64 bits.

## 1. Base representation
A 1024-bit value is stored as 16 little-endian 64-bit limbs:

- `v = sum(limb[i] * 2^(64*i))` for `i = 0..15`

That layout is used throughout the assembly and C++23 trees.

## 2. Scalar multiplication cases
When multiplying a 1024-bit value by a smaller scalar, the scalar is promoted to a wider internal type before the operation begins.

### 8-bit scalar
- Input width: 8 bits
- Internal promotion: 64 bits or wider
- Result width: up to 1032 bits before truncation or carry handling

### 16-bit scalar
- Input width: 16 bits
- Internal promotion: 64 bits or wider
- Result width: up to 1040 bits before truncation or carry handling

### 32-bit scalar
- Input width: 32 bits
- Internal promotion: 64 bits or wider
- Result width: up to 1056 bits before truncation or carry handling

### 64-bit scalar
- Input width: 64 bits
- Internal promotion: 128 bits for intermediate products if available
- Result width: up to 1088 bits before truncation or carry handling

## 3. Limb-wise algorithm
The standard approach is:

1. Multiply each 64-bit limb by the scalar.
2. Add carry into the next limb.
3. Store the low 64 bits of each step.
4. Keep the final carry as overflow or as an extra high limb.

This is a schoolbook multiply pattern with a single scalar.

## 4. Practical interpretation
If the scalar is 8, 16, or 32 bits, 64-bit intermediates are usually enough for the low half of the product on common compilers and assemblers.

If the scalar is 64 bits, you generally need 128-bit intermediate products to preserve correctness before splitting the result into low and high limbs.

## 5. Shift-equivalent cases
If the scalar is a power of two, multiplication can be replaced with a shift:

- `x * 8` is `x << 3`
- `x * 16` is `x << 4`
- `x * 32` is `x << 5`
- `x * 64` is `x << 6`

For the current project, these are useful because shift-based paths are simpler to implement and verify than a full general multiply.

## 6. Future ISA notes
Planned multiply support should distinguish:

- scalar multiply by 8/16/32/64-bit values
- full 1024-bit by 1024-bit multiply
- multiply-by-power-of-two shift shortcuts

Those are different operations and should not be collapsed into one opcode without a clear encoding plan.
