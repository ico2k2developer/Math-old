//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_t a;

        a.bytes = 10;
        assert(array_sizeof(&a) == (sizeof(array_t) + 10));

        a.bytes = 0;
        assert(array_sizeof(&a) == (sizeof(array_t) + 0));

        zero(array_sizeof(NULL));
ctestend