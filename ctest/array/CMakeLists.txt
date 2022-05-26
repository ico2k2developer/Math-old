cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

add_executable(ctest_array_new new.c)
add_executable(ctest_array_new0 new0.c)
add_executable(ctest_array_news news.c)
add_executable(ctest_array_resize resize.c)
add_executable(ctest_array_ensuresize ensuresize.c)
add_executable(ctest_array_copy copy.c)
add_executable(ctest_array_sizeof sizeof.c)
add_executable(ctest_array_issim issim.c)
add_executable(ctest_array_iseq iseq.c)
add_executable(ctest_array_del del.c)
add_executable(ctest_array_strcpy strcpy.c)
add_executable(ctest_array_strncpy strncpy.c)
add_executable(ctest_array_strcpy2 strcpy2.c)
add_executable(ctest_array_strncpy2 strncpy2.c)

add_test(ctest_array
        ctest_array_new
        ctest_array_new0
        ctest_array_news
        ctest_array_resize
        ctest_array_ensuresize
        ctest_array_copy
        ctest_array_sizeof
        ctest_array_issim
        ctest_array_iseq
        ctest_array_del
        ctest_array_strcpy
        ctest_array_strncpy
        ctest_array_strcpy2
        ctest_array_strncpy2
        )