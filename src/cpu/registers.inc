%include "../../include/common.inc"

; CPU register model notes.
; A 1024-bit register uses 16 qwords.

%define CPU_REG_LIMBS LIMBS_1024
%define CPU_REG_BYTES  BYTES_PER_1024_VALUE

%macro CPU_REG_OFFSET 1
    ((%1) * CPU_REG_BYTES)
%endmacro

%macro CPU_REG_PTR 3
    mov %1, %2
    mov r11, %3
    imul r11, CPU_REG_BYTES
    add %1, r11
%endmacro
