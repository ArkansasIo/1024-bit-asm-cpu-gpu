# Board and CAD Notes

## CAD toolchain
KiCad is the primary open PCB CAD tool worth using here.
It provides schematic capture, PCB layout, 3D viewing, and Gerber-related output.

Open Cascade is the most relevant open 3D/CAD kernel found in this search.
It is useful if you want 3D mechanical models, enclosures, or board-fit checks.

## What to model on a real board
- motherboard
- CPU socket or package
- GPU slot or package
- RAM channels
- firmware ROM or boot flash
- storage controller
- power regulation
- cooling hardware
- buses and connectors

## What is missing
- actual PCB schematics
- footprints and symbols
- board placement and routing
- package models
- enclosure/mechanical CAD

## Practical conclusion
If you want real CAD files, the next step is to choose a board stack and generate:
- KiCad schematics
- PCB layout
- 3D component models
- system block diagrams
