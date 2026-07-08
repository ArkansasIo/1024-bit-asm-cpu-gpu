# BIOS, CMOS, NVRAM, and OS Model

This document describes the firmware and operating-system layer added on top of the 1024-bit CPU/GPU scaffold.

## 1. CMOS
CMOS is modeled as a small mutable configuration store.

Use cases:

- boot order
- GUI enable flags
- API enable flags
- screen resolution
- basic firmware configuration

## 2. NVRAM
NVRAM is modeled as a larger persistent firmware-backed store.

Use cases:

- firmware configuration snapshots
- boot metadata
- persistent settings

## 3. BIOS
BIOS is modeled as the boot-time firmware controller.

Responsibilities:

- initialize CMOS defaults
- prepare NVRAM
- check board and RAM availability
- hand off to the operating system

## 4. Operating system
The OS layer is a lightweight Linux-like control model, not a real Linux clone.

It includes:

- kernel state
- process table
- a small firmware API
- a GUI state and renderer

## 5. API
The API is firmware-facing and can:

- read/write CMOS
- read/write NVRAM
- report status

## 6. GUI
The GUI is modeled as a stateful renderer.

It exposes:

- title
- status
- width and height

The renderer currently produces text output. That keeps the project dependency-light while still giving a usable UI layer.

## 7. Scope note
This repository now has a documented BIOS/CMOS/NVRAM/OS layer, but it is still a scaffold.
It is not a production BIOS or a Linux implementation.
