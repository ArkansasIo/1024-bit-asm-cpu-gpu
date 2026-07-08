# Firmware API

The firmware API exposes a minimal control surface over CMOS and NVRAM.

## Operations
- read CMOS byte
- write CMOS byte
- read NVRAM byte
- write NVRAM byte
- report attachment status

## Use in the project
The API exists so the BIOS and OS layers can exchange configuration and status without depending on hardware details.
