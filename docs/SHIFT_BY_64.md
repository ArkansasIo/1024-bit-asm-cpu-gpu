# 1024-bit Shifts by 64-bit Steps

This document covers limb-aligned shifts on a 1024-bit value.

Because the value is stored as 16 little-endian 64-bit limbs, a shift by 64 bits is a whole-limb shift.

## 1. Base layout
A 1024-bit value is stored as:

- `limb[0]` = least significant 64 bits
- `limb[15]` = most significant 64 bits

## 2. Shift by 64 bits
Shifting left by 64 bits is equivalent to:

- moving `limb[i]` into `limb[i + 1]`
- clearing `limb[0]`
- dropping the old `limb[15]`

Shifting right by 64 bits is the reverse:

- moving `limb[i]` into `limb[i - 1]`
- clearing `limb[15]`
- dropping the old `limb[0]`

## 3. Shift by multiples of 64 bits
General limb-aligned shifts are:

- `<< 64`  => 1 limb
- `<< 128` => 2 limbs
- `<< 192` => 3 limbs
- `<< 256` => 4 limbs
- `<< 320` => 5 limbs
- `<< 384` => 6 limbs
- `<< 448` => 7 limbs
- `<< 512` => 8 limbs
- `<< 576` => 9 limbs
- `<< 640` => 10 limbs
- `<< 704` => 11 limbs
- `<< 768` => 12 limbs
- `<< 832` => 13 limbs
- `<< 896` => 14 limbs
- `<< 960` => 15 limbs
- `<< 1024` => full overflow beyond the register width

Right shifts follow the same limb-count rules in the opposite direction.

## 4. Why this matters
Limb-aligned shifts are simpler than bit-level shifts because they can be implemented as copy-and-clear operations over the 16-limb array.

This is useful for:

- fast multiply-by-`2^(64*n)` paths
- register move operations between wider and narrower views
- serialization and deserialization of 1024-bit values

## 5. Relationship to multiplication
Multiplying by `2^64`, `2^128`, `2^192`, and so on is the same as shifting left by 64, 128, 192 bits, etc.

So for this project:

- multiply by a power of two at 64-bit boundaries
- shift by a multiple of 64 bits

These are the same operation at the limb level.
