#!/usr/bin/env python3
"""Small deterministic reference VM for the Arkan-10000 sample assembly."""
from __future__ import annotations

import argparse
from pathlib import Path
import re

WIDTH = 10_000
MASK = (1 << WIDTH) - 1
REGISTER_COUNT = 32
REG_RE = re.compile(r"R([0-9]+)$", re.IGNORECASE)

def reg_index(token: str) -> int:
    match = REG_RE.fullmatch(token)
    if not match:
        raise ValueError(f"invalid register: {token}")
    index = int(match.group(1))
    if not 0 <= index < REGISTER_COUNT:
        raise ValueError(f"register out of range: {token}")
    return index

def execute(path: Path) -> list[int]:
    regs = [0] * REGISTER_COUNT
    halted = False
    for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        instruction = line.split(";", 1)[0].strip()
        if not instruction:
            continue
        fields = instruction.replace(",", " ").split()
        op = fields[0].upper()
        try:
            if op == "LI" and len(fields) == 3:
                regs[reg_index(fields[1])] = int(fields[2], 0) & MASK
            elif op == "ADD" and len(fields) == 4:
                dst, lhs, rhs = map(reg_index, fields[1:])
                regs[dst] = (regs[lhs] + regs[rhs]) & MASK
            elif op == "XOR" and len(fields) == 4:
                dst, lhs, rhs = map(reg_index, fields[1:])
                regs[dst] = (regs[lhs] ^ regs[rhs]) & MASK
            elif op == "HALT" and len(fields) == 1:
                halted = True
                break
            else:
                raise ValueError(f"unknown instruction or wrong operand count: {instruction}")
        except (ValueError, IndexError) as exc:
            raise ValueError(f"{path}:{line_number}: {exc}") from exc
    if not halted:
        raise ValueError(f"{path}: program ended without HALT")
    return regs

def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("program", type=Path)
    args = parser.parse_args()
    regs = execute(args.program)
    print(f"Executed: {args.program}")
    print(f"Data width: {WIDTH} bits")
    print(f"R0={regs[0]:#x}")
    print(f"R1={regs[1]:#x}")
    print(f"R2={regs[2]:#x}")
    print(f"R3={regs[3]:#x}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
