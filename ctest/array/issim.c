//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_t a;
        array_t b;

        a.bytes = 10;
        a.used = 0;
        b.bytes = 10;
        b.used = 0;
        assert(array_issim(&a, &b));

        a.bytes = 10;
        a.used = 1;
        b.bytes = 10;
        b.used = 5;
        assert(array_issim(&a, &b));

        a.bytes = 0;
        a.used = 0;
        b.bytes = 0;
        b.used = 0;
        assert(array_issim(&a, &b));

        assert(!array_issim(NULL, &b));
        assert(!array_issim(&a, NULL));
        assert(array_issim(NULL, NULL));
ctestend