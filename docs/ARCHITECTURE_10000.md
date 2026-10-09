# Arkan-10000 CPU/GPU Architecture — Draft 0.1

## Design intent

Arkan-10000 is a research architecture. Its exact-width 10,000-bit values are a software-defined data type and proposed vector register width, not a claim that a fabricated 10,000-bit silicon processor exists.

## Exact width

- Architectural wide register: exactly 10,000 bits (1,250 bytes).
- Software storage: 157 little-endian 64-bit limbs (1,0048 allocated bit positions); only the low 16 bits of limb 156 are valid.
- Every result must mask bits 10,000 through 10,047.
- Address registers and host pointers remain 64-bit in the first prototype.
- Instruction encoding is independent of register width. Draft VM uses readable assembly text; a binary ISA is a later milestone.

## CPU reference model

The first software milestone implements unsigned add/subtract, bitwise AND/OR/XOR/NOT, and logical shifts with modulo-2^10000 semantics. A simple interpreter executes LI, ADD, XOR, and HALT. It is a reference VM, not a cycle-accurate pipeline.

## GPU research model

The GPU path starts as a software work-item model and an RTL sketch. A GPU job is described as a kernel plus bounded buffers, work groups, and explicit synchronization. Large-width arithmetic is a specialized workload; conventional GPUs are generally designed around much narrower scalar/vector lanes and matrix units. A custom 10,000-bit datapath would require resource, timing, memory-bandwidth, and power analysis before choosing FPGA or ASIC hardware.

## Hardware and software boundaries

- Host: x86-64, NASM host helpers, C++23 simulator.
- Program tools: Python generator, interpreter, validation scripts, manifest with SHA-256.
- RTL: SystemVerilog register-file and GPU-lane sketches.
- OS: design scaffold only; no bootable kernel yet.
- Server/client: later protocol and isolated job runner; no public network exposure until security controls exist.

## Verification requirements

1. Compare C++ arithmetic with Python arbitrary-precision integer reference tests.
2. Test carry/borrow at bit 0, bit 63/64, bit 9983/9984, and bit 9999.
3. Ensure every operation preserves the 10,000-bit invariant.
4. Execute generated programs deterministically and compare checksums across runs.
5. Use RTL simulation and assertions before synthesis.
6. Measure resource usage and timing on a named FPGA before making hardware claims.
