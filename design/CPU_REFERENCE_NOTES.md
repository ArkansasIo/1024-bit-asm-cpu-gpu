# CPU Reference Notes

## What to borrow
- OpenTitan shows how an open SoC is organized around documentation, IP blocks, and a monorepo structure.
- CVA6 shows a practical open CPU core with a clearly documented repository split, verification environment, and user manual.
- OpenRISC gives a historical open CPU reference with a simple load-store style ISA and a Wishbone-centric SoC story.

## What matters for this repo
- a clean fetch/decode/execute split
- separate instruction memory and data memory
- a register file layout that scales past one word
- explicit system components around the CPU core

## Architectural gap
The current ASM model is 1024-bit by register width, not by industry-standard ISA design.
That means the useful part of these references is structure, not instruction compatibility.
