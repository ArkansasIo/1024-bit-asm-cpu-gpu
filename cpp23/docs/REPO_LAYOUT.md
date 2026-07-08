# C++23 Repo Layout

The C++23 tree is separate from the assembly tree and mirrors it at a higher abstraction level.

## Top level
- `README.md`
- `CMakeLists.txt`

## `include/`
- `common.hpp`
- `system.hpp`

## `src/`
- `cpu/`
- `gpu/`
- `system/`
- `firmware/`
- `os/`
- `modules/`
- `apps/`

## `design/`
- reference and implementation notes

## `docs/`
- architecture, ISA, memory model, system components
- `MULTIPLICATION_WIDTHS.md`
- `SHIFT_BY_64.md`
- `BIOS_CMOS_OS.md`
- `FIRMWARE_API.md`
- `GUI_MODEL.md`

## `uml/`
- C++23-oriented diagrams
