//
// Created by ico2k2 on 26/5/2022.
//
#include "../test.h"

#include <bool8.h>

cteststart()
        bool8_t b = 0;

        bool8_check(&b,0);
        assert(b == (1));

        bool8_check(&b,3);
        assert(b == (1 + 8));

        bool8_check(&b,5);
        assert(b == (1 + 8 + 32));

        bool8_check(&b,7);
        assert(b == (1 + 8 + 32 + 128));
ctestend