# C++23 Architecture

The C++23 tree mirrors the same conceptual system as the assembly tree:

- CPU core with 1024-bit registers
- GPU dispatch core with vector registers
- system component model
- board-level wiring

The implementation uses:

- `std::array` for fixed-width register storage
- `std::span` for program/kernel loading
- strong enums for opcode and component kinds
- plain structs for system state

The goal is clarity and testability, not hardware synthesis.
