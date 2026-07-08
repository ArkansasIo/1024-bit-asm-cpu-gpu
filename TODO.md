# TODO - 1024-bit CPU/GPU asm project

- [x] Create `cpu_1024.asm` skeleton
- [x] Create `gpu_1024.asm` skeleton
- [x] Add 1024-bit helper logic to CPU (move/add/sub/compare/immediate load)
- [x] Add CPU opcode handlers (MOV/ADD/SUB/BEQ)
- [x] Add GPU opcode/kernel wiring (copy/add dispatch loop)
- [x] Create UML diagrams (CPU datapath, GPU datapath, memory/register model)
- [x] Create design documents (architecture overview, ISA placeholder, memory model, extension plan)
- [x] Create a build/run README
- [x] Add system-level component model (motherboard, RAM, storage, power, cooling)
- [x] Add split source tree under `src/` and shared constants under `include/`
- [x] Add build helper scripts under `scripts/`
- [x] Add repository layout documentation
- [x] Add examples and test scaffolding
- [x] Add shared types, structs, and deeper module breakdowns
- [x] Add module and type system documentation
- [x] Add external design/reference survey and CAD notes
- [x] Add parallel C++23 implementation tree

## Follow-up ideas
- Add load/store instructions once shared RAM is defined.
- Expand the CPU immediate format beyond a single qword.
- Replace the fixed GPU kernel with a decoded kernel program format.
