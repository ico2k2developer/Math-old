cmake_minimum_required(VERSION 3.21)
project(Math2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Math2 main.c)

add_subdirectory(libs/array)
target_link_libraries(Math2 array)

add_subdirectory(libs/linear)
target_link_libraries(Math2 linear)

enable_testing()
add_subdirectory(ctest)