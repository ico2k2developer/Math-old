cmake_minimum_required(VERSION 3.21)
project(numbers C)

set(CMAKE_C_STANDARD 11)

add_library(numbers numbers.c n.c)
target_link_libraries(numbers bool8)
target_include_directories(numbers PUBLIC .)