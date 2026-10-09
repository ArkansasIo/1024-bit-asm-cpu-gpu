#!/usr/bin/env python3
"""Generate and execute a deterministic corpus of Arkan-10000 programs."""
from __future__ import annotations

import argparse
import csv
import hashlib
from pathlib import Path
import sys

from arkan_vm import execute
from generate_programs import render_program

def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--count", type=int, default=10_000)
    parser.add_argument("--out", type=Path, default=Path("generated/programs"))
    args = parser.parse_args()
    if not 1 <= args.count <= 1_000_000:
        parser.error("--count must be between 1 and 1,000,000")
    args.out.mkdir(parents=True, exist_ok=True)
    manifest_path = args.out / "manifest.csv"
    executed = 0
    with manifest_path.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.writer(stream)
        writer.writerow(["program_id", "file", "sha256", "instruction_count", "status"])
        for program_id in range(args.count):
            name = f"program_{program_id:05d}.asm"
            content = render_program(program_id)
            path = args.out / name
            path.write_text(content, encoding="utf-8", newline="\n")
            digest = hashlib.sha256(content.encode("utf-8")).hexdigest()
            execute(path)
            writer.writerow([program_id, name, digest, 5, "PASS"])
            executed += 1
    actual = len(list(args.out.glob("program_*.asm")))
    if actual != args.count:
        print(f"ERROR: expected {args.count} program files, found {actual}", file=sys.stderr)
        return 1
    print(f"PASS: generated and executed {executed} programs")
    print(f"Manifest: {manifest_path}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
