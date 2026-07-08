# System Components

This document adds the board-level pieces that sit around the CPU and GPU models.

## 1. Motherboard
The motherboard is the physical and logical board that connects the main system parts.

Responsibilities:

- hosts the CPU socket or CPU package
- routes memory channels to RAM
- exposes chipset and peripheral buses
- connects storage, firmware, and expansion devices
- distributes power and clocking

## 2. CPU
The CPU in this repository is an assembly-level model that represents:

- a program counter
- a 16-register 1024-bit register file
- an opcode stream
- simple arithmetic and branch operations

## 3. GPU
The GPU model represents:

- a dispatch loop
- a vector register file
- per-work-item execution
- a small kernel opcode stream

In a real system, the GPU would usually also have local VRAM or shared memory.

## 4. RAM
RAM is the system's main working memory.

Typical roles:

- instructions
- stack data
- heap data
- shared buffers between CPU and GPU

In the current assembly scaffold, `memory[]` is a stand-in for program memory, not a full RAM subsystem.

## 5. Firmware / ROM
Firmware is non-volatile startup code.

Typical roles:

- power-on initialization
- hardware setup
- boot device selection
- handing control to a loader or kernel

This project does not model firmware execution yet.

## 6. Storage
Storage is persistent data memory.

Examples:

- SSD
- HDD
- removable media

Storage is outside the current assembly model, but it matters for a complete machine layout.

## 7. Bus and interconnect
System components communicate over buses and interconnects.

Examples:

- memory bus
- PCIe
- internal CPU/GPU fabric
- peripheral links

These links define how CPU, GPU, RAM, and devices exchange data.

## 8. Power and cooling
A complete system also needs:

- PSU / voltage regulation
- heatsinks and fans or liquid cooling
- thermal monitoring

These parts are not logical execution components, but they are required for a real board.

## 9. Current abstraction boundary
This repository currently models:

- CPU register state
- GPU vector state
- a simplified program/control memory

Next steps, if expanded further, would be:

- shared RAM
- a motherboard-level bus model
- firmware and boot flow
- storage-backed loading of programs and kernels
