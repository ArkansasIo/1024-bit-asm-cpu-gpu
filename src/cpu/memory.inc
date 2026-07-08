%include "../../include/common.inc"

; CPU memory model notes.
; This mirrors the top-level `memory[]` stream until a separate RAM model is introduced.

%define CPU_MEMORY_ROLE_OPCODE_STREAM 1
%define CPU_MEMORY_ROLE_SHARED_RAM     2

%macro CPU_MEM_FETCH 3
    mov %3, [%1 + (%2 * 8)]
%endmacro
