cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

include_directories(../libs)
link_libraries(array)
link_libraries(linear)

add_executable(ctest_array_newa array/newa.c)
add_executable(ctest_array_newa0 array/newa0.c)
add_executable(ctest_array_newas array/newas.c)
add_executable(ctest_array_resize array/resize.c)
add_executable(ctest_array_ensuresize array/ensuresize.c)
add_executable(ctest_array_copya array/copya.c)

add_test(array_newa ctest_array_newa)
add_test(array_newa0 ctest_array_newa0)
add_test(array_newas ctest_array_newas)
add_test(array_resize ctest_array_resize)
add_test(array_ensuresize ctest_array_ensuresize)
add_test(array_copya ctest_array_copya)