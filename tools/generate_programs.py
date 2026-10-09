#!/usr/bin/env python3
"""Generate a deterministic collection of 10,000 Arkan-10000 VM programs."""
from __future__ import annotations

import argparse
import csv
import hashlib
from pathlib import Path

PROGRAM_TEMPLATE = """; Arkan-10000 program {program_id:05d}
; Generated deterministically by tools/generate_programs.py
; ISA draft: LI, ADD, XOR, HALT. Values are 64-bit immediates zero-extended
; into the 10,000-bit architectural register.
LI R0, 0x{a:016X}
LI R1, 0x{b:016X}
ADD R2, R0, R1
XOR R3, R2, R1
HALT
"""

def render_program(program_id: int) -> str:
    # SplitMix64-style deterministic mixing; no external dependencies.
    mask = (1 << 64) - 1
    def mix(value: int) -> int:
        value = (value + 0x9E3779B97F4A7C15) & mask
        value = ((value ^ (value >> 30)) * 0xBF58476D1CE4E5B9) & mask
        value = ((value ^ (value >> 27)) * 0x94D049BB133111EB) & mask
        return value ^ (value >> 31)
    a = mix(program_id)
    b = mix(program_id ^ 0xA5A5A5A55A5A5A5A)
    return PROGRAM_TEMPLATE.format(program_id=program_id, a=a, b=b)

def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--count", type=int, default=10_000)
    parser.add_argument("--out", type=Path, default=Path("generated/programs"))
    args = parser.parse_args()
    if args.count < 1 or args.count > 1_000_000:
        parser.error("--count must be between 1 and 1,000,000")

    args.out.mkdir(parents=True, exist_ok=True)
    manifest = args.out / "manifest.csv"
    with manifest.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.writer(stream)
        writer.writerow(["program_id", "file", "sha256", "instruction_count"])
        for program_id in range(args.count):
            filename = f"program_{program_id:05d}.asm"
            content = render_program(program_id)
            path = args.out / filename
            path.write_text(content, encoding="utf-8", newline="\n")
            writer.writerow([
                program_id, filename,
                hashlib.sha256(content.encode("utf-8")).hexdigest(), 5
            ])
    print(f"Generated {args.count} programs in {args.out}")
    print(f"Manifest: {manifest}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
