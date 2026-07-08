; Common assembly constants shared by future source splits.

%define LIMBS_1024 16
%define BYTES_PER_LIMB 8
%define BYTES_PER_1024_VALUE (LIMBS_1024 * BYTES_PER_LIMB)

%define CPU_REGISTER_COUNT 16
%define GPU_VECTOR_COUNT 8

%define OP_HALT    0xFF
%define OP_MOV_IMM 0x01
%define OP_ADD     0x02
%define OP_SUB     0x03
%define OP_BEQ     0x04

%define OP_VCOPY   0x10
%define OP_VADD    0x11

%define COMPONENT_MOTHERBOARD 1
%define COMPONENT_CPU          2
%define COMPONENT_GPU          3
%define COMPONENT_RAM          4
%define COMPONENT_FIRMWARE     5
%define COMPONENT_STORAGE      6
%define COMPONENT_BUS          7
%define COMPONENT_POWER        8
%define COMPONENT_COOLING      9

%define BUS_TYPE_MEMORY        1
%define BUS_TYPE_COMMAND       2
%define BUS_TYPE_EXPANSION     3
%define BUS_TYPE_STORAGE       4

%define MEMORY_ROLE_OPCODE_STREAM 1
%define MEMORY_ROLE_SHARED_RAM     2
%define MEMORY_ROLE_FIRMWARE_ROM   3
%define MEMORY_ROLE_STORAGE_IMAGE  4

%define EXEC_MODE_CPU          1
%define EXEC_MODE_GPU          2
%define EXEC_MODE_BOOT         3

%macro CPU_ENCODE_OP 4
    (%1 | (%2 << 8) | (%3 << 16) | (%4 << 24))
%endmacro

%macro GPU_ENCODE_OP 3
    (%1 | (%2 << 8) | (%3 << 16))
%endmacro
