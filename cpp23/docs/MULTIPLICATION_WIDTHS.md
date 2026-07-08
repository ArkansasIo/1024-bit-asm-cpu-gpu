# 1024-bit Multiplication Widths

This note describes how a 1024-bit value interacts with scalar widths of 8, 16, 32, and 64 bits.

## 1. Representation
The value is stored as 16 little-endian 64-bit limbs:

- `v = sum(limb[i] * 2^(64*i))` for `i = 0..15`

## 2. Scalar widths
Before multiplication, the scalar is promoted to a wider intermediate type.

### 8-bit scalar
- Input width: 8 bits
- Internal promotion: 64 bits or wider
- Result width: up to 1032 bits before trimming or overflow handling

### 16-bit scalar
- Input width: 16 bits
- Internal promotion: 64 bits or wider
- Result width: up to 1040 bits before trimming or overflow handling

### 32-bit scalar
- Input width: 32 bits
- Internal promotion: 64 bits or wider
- Result width: up to 1056 bits before trimming or overflow handling

### 64-bit scalar
- Input width: 64 bits
- Internal promotion: 128-bit intermediates are typically needed
- Result width: up to 1088 bits before trimming or overflow handling

## 3. Recommended implementation
Use the following pattern for scalar multiply:

1. Multiply each limb by the scalar.
2. Add carry into the next limb.
3. Preserve the final carry as overflow or extend the result width.

## 4. Power-of-two shortcuts
If the scalar is a power of two, use a shift instead of a general multiply:

- `* 8` -> `<< 3`
- `* 16` -> `<< 4`
- `* 32` -> `<< 5`
- `* 64` -> `<< 6`

That shortcut is useful for both performance and correctness testing.

## 5. Project meaning
This repository currently models the multiply-width problem as documentation and future ISA work.
The C++23 and assembly trees both use the same limb layout, so the same multiplication rules apply to both implementations.
