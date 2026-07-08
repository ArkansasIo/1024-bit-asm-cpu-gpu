cmake_minimum_required(VERSION 3.24)
project(cpu_gpu_1024_cpp23 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(cpu_gpu_1024
    src/cpu/cpu_1024.cpp
    src/gpu/gpu_1024.cpp
    src/system/system_model.cpp
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
