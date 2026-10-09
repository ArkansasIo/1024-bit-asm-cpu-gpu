cmake_minimum_required(VERSION 3.25)
project(Arkan10000 VERSION 0.1.0 LANGUAGES CXX)

add_executable(arkan10000 src/main.cpp)
target_include_directories(arkan10000 PRIVATE include)
target_compile_features(arkan10000 PRIVATE cxx_std_23)
set_target_properties(arkan10000 PROPERTIES CXX_EXTENSIONS OFF)

add_executable(test_uint10000 tests/test_uint10000.cpp)
target_include_directories(test_uint10000 PRIVATE include)
target_compile_features(test_uint10000 PRIVATE cxx_std_23)
set_target_properties(test_uint10000 PROPERTIES CXX_EXTENSIONS OFF)

enable_testing()
add_test(NAME uint10000 COMMAND test_uint10000)

if(MSVC)
  target_compile_options(arkan10000 PRIVATE /W4 /permissive-)
  target_compile_options(test_uint10000 PRIVATE /W4 /permissive-)
else()
  target_compile_options(arkan10000 PRIVATE -Wall -Wextra -Wpedantic)
  target_compile_options(test_uint10000 PRIVATE -Wall -Wextra -Wpedantic)
endif()
