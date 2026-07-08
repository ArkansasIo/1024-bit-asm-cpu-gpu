# BIOS, CMOS, NVRAM, and OS Model

This C++23 layer models a firmware and operating-system stack around the 1024-bit CPU/GPU system.

## CMOS
- small mutable configuration store
- boot flags and GUI/API toggles

## NVRAM
- persistent firmware-backed storage
- configuration snapshots and boot metadata

## BIOS
- initializes firmware state
- validates board and RAM presence
- hands off boot state

## OS
- kernel state
- process table
- firmware API
- GUI state and renderer

## GUI
The GUI currently renders to text. It is a stateful front end, not a full desktop toolkit integration.
