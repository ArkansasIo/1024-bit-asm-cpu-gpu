# Memory Model

## 1. Register layout
Both CPU and GPU models store 1024-bit values as 16 qwords.

For a register `R`:

- `R[0]` is the least significant 64 bits.
- `R[15]` is the most significant 64 bits.

Each register therefore occupies 128 bytes.

## 2. CPU storage
The CPU uses `regfile` as a flat qword array:

- 16 registers
- 16 qwords per register
- 256 qwords total

## 3. GPU storage
The GPU uses `vregfile` as a flat qword array:

- vector registers follow the same 16-limb layout
- dispatch currently operates on a small fixed register set

## 4. Program memory
`memory[]` is a qword array stored in `.data`.

Current uses:

- CPU opcode stream
- GPU control stream

## 5. Missing piece
There is no general-purpose RAM abstraction yet.

The next design step is to separate:

- instruction memory
- shared RAM
- register file storage

That separation will make load/store instructions and kernel-style memory traffic easier to define.
