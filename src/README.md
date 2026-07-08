# Source Tree

This directory is a split-out scaffold for the hardware model.

The top-level `cpu_1024.asm` and `gpu_1024.asm` remain the runnable entry points.
The files under `src/` are organized for a cleaner future split.

## Layout
- `src/cpu/` - CPU constants and source modules.
- `src/gpu/` - GPU constants and source modules.
- `src/system/` - motherboard and board-level component stubs.
- `src/types/` - shared type constants.
- `src/structs/` - shared structure layouts.
- `src/modules/` - deeper CPU/GPU/system module breakdown.
