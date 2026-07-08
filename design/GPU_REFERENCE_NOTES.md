# GPU Reference Notes

## What to borrow
- Vortex is the closest open GPU reference in this search set.
- It is a full-stack open-source GPGPU with a driver, compiler toolchain, and RTL/simulator support.
- The project structure is useful because it separates the hardware core from drivers and compiler support.

## Useful ideas
- SIMT-style execution model
- command/dispatch stream separated from kernel logic
- compiler/runtime split from execution hardware
- explicit memory movement concerns over PCIe or board interconnect

## What matters for this repo
- a kernel dispatch loop
- work-item state
- vector register file layout
- a future shared-memory model between CPU and GPU

## Limitation
The repository still has no real GPU RTL or board layout.
The current assembly file is only a behavior scaffold.
