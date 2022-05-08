cmake_minimum_required(VERSION 3.21)
project(literal C)

set(CMAKE_C_STANDARD 11)

add_library(linear literal.c var.c matrix.c doc.h)
target_link_libraries(linear array)
target_include_directories(linear PUBLIC .)