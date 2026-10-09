# System Architecture

## 1. Platform definition

The platform is a research computer architecture with a 1024-bit general-purpose data path, a separate parallel GPU execution model, a server profile, client workstations, and an experimental operating system.

The first deliverable is a deterministic software reference model. Hardware implementations must be verified against it.

## 2. Logical blocks

```text
Client Applications
       |
Client OS + UI + SDK
       | authenticated RPC
Server API / Scheduler / Storage
       |
Host OS or Experimental OS
       |
CPU ISA + GPU Compute Runtime
       |
Reference Simulator -> FPGA RTL -> (future) custom silicon
```

## 3. CPU model

- Architectural general-purpose registers: 32 x 1024 bits (initial proposal).
- Program counter: 64-bit address.
- Address model: 64-bit virtual addresses initially; physical address width is a platform parameter.
- Flags: explicit condition state; avoid implicit side effects where practical.
- Memory operations: load/store, alignment rules, endianness, and atomicity must be specified in the ISA.
- Exception model: illegal instruction, access fault, arithmetic fault, interrupt, and system call.
- Privilege model: user, supervisor/kernel, and machine/firmware modes.
- Instruction encoding: versioned fixed-width 1024-bit instruction words for the first experimental ISA, with reserved fields required to be zero. This is an encoding choice, not a requirement of 1024-bit data registers.

A 1024-bit word is 128 bytes. A 1024-byte instruction is 8192 bits and is a separate, much more expensive encoding choice; do not conflate the two.

## 4. GPU model

- Separate command queue and device-memory abstraction.
- Work submitted as kernels, grids, blocks/work groups, and lanes.
- Initial software model prioritizes correctness, determinism, and memory-boundary checking over speed.
- Explicit host/device buffers and synchronization fences.
- Atomic operations and floating-point behavior must be specified before conformance tests.
- The CPU reference model and GPU model share typed memory interfaces but do not assume identical execution pipelines.

## 5. Memory and I/O

- Main memory exposed as byte-addressable storage.
- 1024-bit registers are represented as 128-byte values.
- Little-endian byte order is the proposed initial convention; changing it later requires a versioned ABI.
- DMA-capable devices must use bounded buffers and explicit ownership transfer.
- MMIO ranges are described by the platform firmware/device tree rather than hard-coded into applications.

## 6. Software layers

1. ISA specification and conformance tests.
2. CPU/GPU reference simulator.
3. Firmware/boot interface.
4. Kernel: traps, scheduling, virtual memory, IPC.
5. Drivers: console, timer, block storage, network, GPU.
6. Filesystem and network stack.
7. Server services and client UI/SDK.
8. Toolchain: assembler, disassembler, linker, debugger, package builder.

## 7. Verification principles

- Every instruction has encoding, semantics, privilege rules, exceptions, and tests.
- Use golden test vectors for 1024-bit arithmetic and serialization.
- Fuzz instruction decoding and memory access boundaries.
- Differentially test any RTL against the C++23 reference model.
- No performance claims until benchmark programs and hardware measurements are published.
