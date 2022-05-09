//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array a;

        a.bytes = 10;
        assert(sizeofa(&a) == (sizeof(array) + 10));

        a.bytes = 0;
        assert(sizeofa(&a) == (sizeof(array) + 0));

        zero(sizeofa(NULL));
ctestend