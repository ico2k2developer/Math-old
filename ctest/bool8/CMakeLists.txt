cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

add_executable(ctest_bool8_get get.c)
add_executable(ctest_bool8_check check.c)
add_executable(ctest_bool8_uncheck uncheck.c)
add_executable(ctest_bool8_set set.c)

add_test(bool8_get ctest_bool8_get)
add_test(bool8_check ctest_bool8_check)
add_test(bool8_uncheck ctest_bool8_uncheck)
add_test(bool8_set ctest_bool8_set)