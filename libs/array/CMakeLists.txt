cmake_minimum_required(VERSION 3.21)
project(array C)

set(CMAKE_C_STANDARD 11)

add_library(array array.c doc.h)
target_include_directories(array PUBLIC .)