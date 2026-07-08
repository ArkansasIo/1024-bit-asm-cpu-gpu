%include "../../include/common.inc"

; CPU opcode field helpers.
%define CPU_OP_MASK   0xFF
%define CPU_DST_SHIFT 8
%define CPU_SRC_SHIFT 16
%define CPU_IMM_SHIFT 24

%macro CPU_OP 1
    ((%1) & CPU_OP_MASK)
%endmacro

%macro CPU_DST 1
    (((%1) >> CPU_DST_SHIFT) & 0xFF)
%endmacro

%macro CPU_SRC 1
    (((%1) >> CPU_SRC_SHIFT) & 0xFF)
%endmacro

%macro CPU_IMM 1
    (((%1) >> CPU_IMM_SHIFT) & 0xFFFFFFFFFF)
%endmacro

; Planned extensions:
; - load/store
; - logical ops
; - shifts/rotates
; - compare-and-branch variants
