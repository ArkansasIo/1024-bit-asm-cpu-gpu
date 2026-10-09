cmake_minimum_required(VERSION 3.25)
project(Arkan1024Simulator VERSION 0.1.0 LANGUAGES CXX)

add_executable(arkan1024
    src/main.cpp
)
target_compile_features(arkan1024 PRIVATE cxx_std_23)
set_target_properties(arkan1024 PROPERTIES CXX_EXTENSIONS OFF)

if(MSVC)
    target_compile_options(arkan1024 PRIVATE /W4 /permissive-)
else()
    target_compile_options(arkan1024 PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)
endif()
