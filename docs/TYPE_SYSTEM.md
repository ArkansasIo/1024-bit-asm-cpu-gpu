# Type System

This repository uses assembly-friendly type and layout files instead of classes.

## 1. Type files
Type files define symbolic constants for component kinds, memory roles, bus kinds, and execution modes.

Examples:

- `include/common.inc`
- `src/types/component_types.inc`
- `src/types/bus_types.inc`
- `src/types/memory_types.inc`
- `src/types/execution_types.inc`

## 2. Struct files
Struct files use `struc` to define state and layout records.

Examples:

- `include/structs.inc`
- `src/structs/cpu_state.inc`
- `src/structs/gpu_state.inc`
- `src/structs/system_state.inc`
- `src/structs/memory_region.inc`
- `src/structs/board_layout.inc`

## 3. Module files
Module files organize behavior by responsibility.

Examples:

- CPU fetch, decode, execute, ALU
- GPU fetch, dispatch, vector ALU
- system motherboard, RAM controller, power, cooling, interconnect

## 4. Why this shape
Assembly does not naturally use classes and subclasses.
The closest equivalent is:

- types for symbolic values
- structs for memory layout
- modules for behavior
- submodules for tighter responsibility splits
