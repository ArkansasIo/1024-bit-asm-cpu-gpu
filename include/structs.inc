; Shared structure declarations for component and state layouts.

struc cpu_state
    .pc:        resq 1
    .sp:        resq 1
    .regfile:   resq (CPU_REGISTER_COUNT * LIMBS_1024)
    .flags:     resq 1
    .mode:      resq 1
endstruc

struc gpu_state
    .pc:        resq 1
    .work_items: resq 1
    .current_wi: resq 1
    .vregfile:  resq (GPU_VECTOR_COUNT * LIMBS_1024)
    .mode:      resq 1
endstruc

struc memory_region
    .base:      resq 1
    .size:      resq 1
    .role:      resq 1
    .flags:     resq 1
    .cursor:    resq 1
endstruc

struc bus_endpoint
    .component: resq 1
    .port:      resq 1
    .mode:      resq 1
endstruc

struc motherboard_layout
    .cpu:       resq 1
    .gpu:       resq 1
    .ram:       resq 1
    .firmware:  resq 1
    .storage:   resq 1
    .power:     resq 1
    .cooling:   resq 1
    .bus:       resq 1
    .clock_hz:  resq 1
endstruc

struc system_state
    .board:     resq 1
    .cpu:       resq 1
    .gpu:       resq 1
    .ram:       resq 1
    .firmware:  resq 1
    .storage:   resq 1
    .power:     resq 1
    .cooling:   resq 1
endstruc

struc power_state
    .voltage_mv:    resq 1
    .current_ma:    resq 1
    .thermal_limit:  resq 1
    .enabled:       resq 1
endstruc

struc cooling_state
    .fan_rpm:       resq 1
    .temp_c:        resq 1
    .policy:        resq 1
    .enabled:       resq 1
endstruc

struc storage_device
    .kind:      resq 1
    .capacity:  resq 1
    .io_mode:   resq 1
    .base_lba:  resq 1
endstruc
