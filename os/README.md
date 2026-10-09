# Arkan OS — experimental kernel roadmap

This directory is a design scaffold, not a bootable operating system yet.

## Milestones
1. Emulator console and deterministic panic/logging interface.
2. Platform boot contract and memory map.
3. Timer interrupt, trap entry/return, and scheduler skeleton.
4. Physical page allocator and virtual memory.
5. Privilege boundary, syscall ABI, and process model.
6. Device-driver interfaces for console, storage, network, and accelerator.
7. Filesystem, package manager, signed updates, and server services.

Until those milestones are implemented and tested, run the simulator on a supported host OS and do not treat this scaffold as deployable kernel software.
