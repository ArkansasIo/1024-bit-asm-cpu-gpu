# Hardware Profiles

These are proposed engineering profiles, not verified or manufactured bill-of-materials lists.

## A. Development workstation / client

- Modern x86-64 or ARM64 host CPU to run the initial simulator and toolchain.
- 32 GB RAM recommended for development; 64 GB or more for large simulations and FPGA builds.
- NVMe SSD, 1 TB or larger recommended.
- Standard discrete GPU for display and optional host-side compute; it is not the custom 1024-bit GPU.
- 1 GbE minimum; 2.5/10 GbE useful for server testing.
- Linux or Windows host environment with C++23 compiler and CMake.
- Optional FPGA development board chosen only after RTL resource estimates and I/O requirements are known.

## B. Server prototype

- x86-64/ARM64 host platform initially; it hosts the simulator and services rather than pretending to be custom 1024-bit silicon.
- ECC RAM recommended for long-running tests.
- NVMe storage with backups and monitoring.
- 10 GbE networking recommended for lab server/client tests.
- UPS, airflow, thermal monitoring, and remote management appropriate to the selected chassis.
- Separate management network where practical.
- Experimental OS runs in a virtual machine or emulator until drivers, isolation, and recovery paths are tested.

## C. Future FPGA prototype

1. Implement 1024-bit register file and arithmetic units in SystemVerilog.
2. Start with a minimal instruction subset and a memory-mapped UART/timer.
3. Verify against C++ reference vectors.
4. Estimate logic cells, BRAM, DSP usage, timing, power, and I/O requirements.
5. Select an FPGA only after those estimates. A full 1024-bit CPU plus GPU may exceed modest FPGA resources; implement incrementally.

## D. Future custom silicon

A custom ASIC requires RTL verification, synthesis, place-and-route, timing closure, power/thermal analysis, design-for-test, fabrication access, package design, and board bring-up. This project does not yet have those deliverables.

## Hardware width terminology

- **Data width:** bits processed by an operation/register.
- **Address width:** bits used to address memory.
- **Instruction width:** bits in an encoded instruction.
- **Bus width:** bits transferred per bus beat.
- **GPU lane/vector width:** bits and lanes used by parallel operations.

These values must be documented separately in all specifications.
