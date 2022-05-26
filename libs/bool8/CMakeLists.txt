cmake_minimum_required(VERSION 3.21)
project(bool8 C)

set(CMAKE_C_STANDARD 11)

add_library(bool8 bool8.c bool8.h)
target_include_directories(bool8 PUBLIC .)