# Arkan CPU/GPU Research Platform

A research repository for exact-width CPU/GPU datapaths, a reference VM, FPGA RTL sketches, host assembly helpers, and generated program workloads.

> **Status:** software and RTL prototypes only. This repository does not contain fabricated custom silicon or a production-ready OS.

## Architecture variants

- **Arkan-1024:** initial 1024-bit arithmetic prototype in `simulator/`.
- **Arkan-10000:** exact 10,000-bit arithmetic and reference-program tooling in `cpu10000/` and `tools/`.

A 10,000-bit value is represented as 157 little-endian 64-bit limbs. The final limb uses only its low 16 bits; all operations must mask the unused 48 bits. Address width and instruction encoding are separate architectural choices.

## Repository map

- `docs/ARCHITECTURE.md` — original 1024-bit platform architecture.
- `docs/ARCHITECTURE_10000.md` — exact-width 10,000-bit design.
- `docs/ISA.md` — initial ISA concepts for the 1024-bit variant.
- `docs/HARDWARE.md` — server/client and FPGA hardware profile.
- `docs/OPERATING_SYSTEM.md`, `os/` — OS layers and implementation status.
- `docs/SERVER_CLIENT.md` — future networked compute model.
- `cpu10000/` — C++23 exact-width integer and unit tests.
- `simulator/` — original C++23 1024-bit arithmetic prototype.
- `cpu_sim.asm` — original NASM x86-64 host emulator.
- `asm/x86_64/` — NASM host helper routines.
- `hardware/rtl/` — SystemVerilog research blocks.
- `tools/arkan_vm.py` — Python reference interpreter for the draft text ISA.
- `tools/generate_programs.py` — deterministic program corpus generator.
- `tools/validate_programs.py` — generate and execute a corpus and write a SHA-256 manifest.
- `programs/samples/` — hand-written examples.

## Generate and validate 10,000 programs

Requires Python 3.10 or newer. From the repository root:

```bash
python tools/validate_programs.py --count 10000 --out generated/programs
```

This creates 10,000 individual `.asm` files plus `manifest.csv`, and executes every generated program using the Python reference VM. Generated files are build artifacts and are not checked into Git by default.

Run one sample:

```bash
python tools/arkan_vm.py programs/samples/program_00000.asm
```

## Build the C++23 prototype

Requires CMake 3.25+ and a C++23-capable compiler.

```bash
cmake -S cpu10000 -B build/cpu10000
cmake --build build/cpu10000
ctest --test-dir build/cpu10000 --output-on-failure
```

## Current limitations

- The 10,000-bit C++ component is an arithmetic library, not yet a full instruction-executing hardware CPU.
- The Python VM supports only `LI`, `ADD`, `XOR`, and `HALT`; it is an executable draft, not a frozen binary ISA.
- SystemVerilog files are design sketches and have not been synthesized or FPGA-verified.
- NASM code is a host helper, not a native 10,000-bit instruction.
- `os/` is a roadmap scaffold, not a bootable kernel.
- GPU throughput, silicon area, timing, and power are not claimed without measured implementation evidence.

## Development principles

1. Treat the C++ and Python models as reference implementations.
2. Test boundary bits at 0, 63/64, 9983/9984, and 9999.
3. Compare generated-program results deterministically and retain SHA-256 manifests.
4. Simulate and assert RTL before synthesis.
5. Use a named target FPGA and publish resource/timing results before making hardware claims.
6. Keep experimental server services isolated until authentication, sandboxing, and update integrity are implemented.

## 2026 toolchain baseline

Use C++23 explicitly (`-std=c++23`), NASM x86-64 host helpers, Python 3.10+, CMake 3.25+, and SystemVerilog aligned with IEEE 1800-2023. Actual tool versions should be pinned in CI when a build runner is added.
