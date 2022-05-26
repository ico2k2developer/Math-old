cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

include_directories(../libs)
link_libraries(bool8)
link_libraries(array)
link_libraries(linear)

add_subdirectory(bool8)
add_subdirectory(array)
add_subdirectory(linear)