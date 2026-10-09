; Arkan-10000 sample program 00000
; Demonstrates immediate load, wide-register addition, XOR, and halt.
LI R0, 0x000000000000002A
LI R1, 0x0000000000000015
ADD R2, R0, R1
XOR R3, R2, R1
HALT
