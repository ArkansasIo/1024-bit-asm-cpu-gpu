#!/usr/bin/env python3
"""Deterministic software model of an Arkan-10000 GPU workgroup."""
from __future__ import annotations
import argparse
import json
from pathlib import Path

WIDTH = 10_000
MASK = (1 << WIDTH) - 1
MAX_WORK_ITEMS = 1_000_000
OPS = {"add", "xor", "and", "or"}

def dispatch(op: str, lhs: list[int], rhs: list[int]) -> list[int]:
    op = op.lower()
    if op not in OPS:
        raise ValueError(f"unsupported operation {op!r}; choose one of {sorted(OPS)}")
    if len(lhs) != len(rhs):
        raise ValueError("input buffers must have equal lengths")
    if len(lhs) > MAX_WORK_ITEMS:
        raise ValueError(f"workgroup exceeds {MAX_WORK_ITEMS} items")
    out: list[int] = []
    for index, (a, b) in enumerate(zip(lhs, rhs)):
        if not isinstance(a, int) or not isinstance(b, int) or a < 0 or b < 0:
            raise ValueError(f"work item {index}: values must be non-negative integers")
        if a > MASK or b > MASK:
            raise ValueError(f"work item {index}: input exceeds {WIDTH}-bit width")
        if op == "add":
            value = (a + b) & MASK
        elif op == "xor":
            value = a ^ b
        elif op == "and":
            value = a & b
        else:
            value = a | b
        out.append(value & MASK)
    return out

def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--op", choices=sorted(OPS), default="add")
    parser.add_argument("--count", type=int, default=8)
    args = parser.parse_args()
    if not 0 <= args.count <= MAX_WORK_ITEMS:
        parser.error(f"--count must be between 0 and {MAX_WORK_ITEMS}")
    lhs = list(range(args.count))
    rhs = [2 * value + 1 for value in range(args.count)]
    results = dispatch(args.op, lhs, rhs)
    print(json.dumps({
        "architecture": "Arkan-10000 GPU reference model",
        "width_bits": WIDTH,
        "operation": args.op,
        "work_items": len(results),
        "results_preview": results[:8],
    }, indent=2))
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
