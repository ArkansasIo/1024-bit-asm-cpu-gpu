; SysV AMD64 ABI helper for the host simulator.
; uint64_t arkan_u64_add_carry(uint64_t a, uint64_t b, uint8_t *carry_out)
; Arguments: RDI=a, RSI=b, RDX=carry_out; return sum in RAX.
; This helper is for host-side 64-bit limbs, not a native 10000-bit instruction.
BITS 64
DEFAULT REL
section .text
global arkan_u64_add_carry
arkan_u64_add_carry:
    mov     rax, rdi
    add     rax, rsi
    setc    cl
    mov     byte [rdx], cl
    ret
