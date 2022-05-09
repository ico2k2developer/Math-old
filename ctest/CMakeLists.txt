cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

include_directories(../libs)
link_libraries(array)
link_libraries(linear)

add_subdirectory(array)