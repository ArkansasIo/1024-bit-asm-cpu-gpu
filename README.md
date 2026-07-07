# 1024-bit CPU/GPU asm (skeleton)

This folder contains **NASM-style** assembly skeletons modeling a 1024-bit register as **16×64-bit limbs**.

## Files
- `cpu_1024.asm` — CPU emulator skeleton + 1024-bit helpers (move/add/sub/eq-compare) + opcode layout placeholder.
- `gpu_1024.asm` — GPU compute/dispatch skeleton + vector register helpers (copy/add) + dispatch loop placeholder.

## Build
NASM is required to assemble these files.

On Windows, you can install NASM (if missing) and then build, e.g.:

```bat
nasm -felf64 "cpu_1024.asm" -o cpu_1024.o && ld cpu_1024.o -o cpu_1024
nasm -felf64 "gpu_1024.asm" -o gpu_1024.o && ld gpu_1024.o -o gpu_1024
```

## Notes
- This is currently a **structural placeholder**: instruction decoding/ISA is scaffolded but not fully wired end-to-end.
- Next steps: wire opcode handlers to the helper routines and formalize an opcode format.

