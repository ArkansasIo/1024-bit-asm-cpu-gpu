# 1024-bit Shifts by 64-bit Steps

This note covers limb-aligned shifts for 1024-bit values.

The representation uses 16 little-endian 64-bit limbs, so a shift by 64 bits is exactly one limb.

## 1. Shift left by 64 bits
`x << 64` means:

- move each limb up by one position
- clear the lowest limb
- drop the highest limb

## 2. Shift right by 64 bits
`x >> 64` means:

- move each limb down by one position
- clear the highest limb
- drop the lowest limb

## 3. Multiple-of-64 shifts
The same pattern applies to larger multiples:

- `<< 128` = 2 limbs
- `<< 256` = 4 limbs
- `<< 512` = 8 limbs
- `<< 1024` = outside the register width

## 4. Multiplication equivalence
Multiply-by-`2^(64*n)` is equivalent to shifting left by `64*n`.

That means the following are the same at the limb level:

- multiply by `2^64`
- shift left by 64

This is the cleanest way to express limb-aligned scaling in the project.
