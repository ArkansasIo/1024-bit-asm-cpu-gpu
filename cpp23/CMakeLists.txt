cmake_minimum_required(VERSION 3.24)
project(cpu_gpu_1024_cpp23 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CPU_GPU_1024_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build-output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CPU_GPU_1024_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CPU_GPU_1024_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CPU_GPU_1024_OUTPUT_DIR})

add_library(cpu_gpu_1024
    src/cpu/cpu_1024.cpp
    src/gpu/gpu_1024.cpp
    src/system/system_model.cpp
    src/firmware/firmware.cpp
    src/os/os.cpp
    src/system/motherboard.cpp
    src/system/ram.cpp
    src/system/firmware.cpp
    src/system/storage.cpp
    src/system/power.cpp
    src/system/cooling.cpp
    src/system/bus.cpp
    src/system/system_state.cpp
    src/modules/cpu/alu.cpp
    src/modules/cpu/fetch.cpp
    src/modules/cpu/decode.cpp
    src/modules/cpu/execute.cpp
    src/modules/gpu/vector_alu.cpp
    src/modules/gpu/fetch.cpp
    src/modules/gpu/dispatch.cpp
    src/modules/system/motherboard.cpp
    src/modules/system/ram_controller.cpp
    src/modules/system/power_delivery.cpp
    src/modules/system/cooling_control.cpp
    src/modules/system/interconnect.cpp
    src/modules/system/system_state.cpp
)

target_include_directories(cpu_gpu_1024
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(cpu_1024_app src/apps/cpu_main.cpp)
target_link_libraries(cpu_1024_app PRIVATE cpu_gpu_1024)

add_executable(gpu_1024_app src/apps/gpu_main.cpp)
target_link_libraries(gpu_1024_app PRIVATE cpu_gpu_1024)

add_executable(cpu_smoke_test tests/smoke/cpu_smoke.cpp)
target_link_libraries(cpu_smoke_test PRIVATE cpu_gpu_1024)

add_executable(gpu_smoke_test tests/smoke/gpu_smoke.cpp)
target_link_libraries(gpu_smoke_test PRIVATE cpu_gpu_1024)

add_executable(firmware_smoke_test tests/smoke/firmware_smoke.cpp)
target_link_libraries(firmware_smoke_test PRIVATE cpu_gpu_1024)

add_executable(os_smoke_test tests/smoke/os_smoke.cpp)
target_link_libraries(os_smoke_test PRIVATE cpu_gpu_1024)

add_executable(firmware_setup_app src/apps/firmware_main.cpp)
target_link_libraries(firmware_setup_app PRIVATE cpu_gpu_1024)

add_executable(os_setup_app src/apps/os_main.cpp)
target_link_libraries(os_setup_app PRIVATE cpu_gpu_1024)
