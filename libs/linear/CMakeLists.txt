cmake_minimum_required(VERSION 3.21)
project(linear C)

set(CMAKE_C_STANDARD 11)

add_library(linear linear.c)
target_link_libraries(linear bool8)
target_link_libraries(linear array)
target_link_libraries(linear numbers)
target_include_directories(linear PUBLIC .)