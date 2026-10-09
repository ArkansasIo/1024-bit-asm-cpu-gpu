# Experimental 1024-Bit ISA — Draft 0.1

## Scope

This document defines initial design constraints, not a complete stable ISA. The reference simulator is the executable specification once implemented and tested.

## Proposed architectural state

- 32 general-purpose registers, each 1024 bits (128 bytes).
- 64-bit program counter.
- 64-bit virtual address model for the first simulator.
- Status/exception state and privilege mode.
- Optional vector/floating-point facilities are separate extensions.

## Initial instruction word

Draft encoding: fixed 1024-bit (128-byte) instruction word. Fields are reserved for opcode, register indices, sub-opcode, immediate/control fields, and extension space. The exact bit offsets and reserved-bit policy must be frozen in the decoder implementation and conformance tests.

Fixed-width 1024-bit instructions are intentionally experimental and inefficient for storage/cache bandwidth. They are not the same as 1024-bit data operations. A compact encoding may be added as a distinct ISA revision after the fixed-width baseline works.

## Instruction families

1. Integer: move, add, subtract, bitwise logic, compare.
2. Wide arithmetic: add/subtract with carry, shifts, rotate, multiply/divide as later extensions.
3. Memory: load/store with defined size and alignment.
4. Control flow: branch, conditional branch, call, return.
5. System: trap, return-from-trap, syscall, fence.
6. GPU dispatch: queue submission and synchronization through privileged runtime interfaces, not arbitrary user-mode device writes.

## Required semantics

For every opcode, specify:
- Encoding and reserved fields.
- Source/destination register behavior.
- Exact 1024-bit wraparound or signed/unsigned behavior.
- Memory ordering and alignment.
- Privilege restrictions.
- Exceptions and program-counter behavior.
- At least one positive and one negative test.

## Arithmetic conventions

- Bitwise operations operate on exactly 1024 bits.
- Unsigned addition may produce a carry-out flag.
- Signed integers use two's-complement representation.
- Overflow behavior must be explicitly selected per opcode.
- Serialize values as exactly 128 bytes using the platform's defined byte order.

## Stability

Any change to register count, encoding, endianness, privilege rules, or exception behavior requires an ISA version bump and updated golden tests.
