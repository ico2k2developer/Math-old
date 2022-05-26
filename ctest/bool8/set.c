//
// Created by ico2k2 on 26/5/2022.
//
#include "../test.h"

#include <bool8.h>

cteststart()
        bool8_t b = 0xF0;

        bool8_set(&b,0,1);
        assert(b == (1 + 16 + 32 + 64 + 128));

        bool8_set(&b,7,0);
        assert(b == (1 + 16 + 32 + 64));

        bool8_set(&b,1,1);
        assert(b == (1 + 2 + 16 + 32 + 64));

        bool8_set(&b,6,0);
        assert(b == (1 + 2 + 16 + 32));

        bool8_set(&b,2,1);
        assert(b == (1 + 2 + 4 + 16 + 32));

        bool8_set(&b,5,0);
        assert(b == (1 + 2 + 4 + 16));

        bool8_set(&b,3,1);
        assert(b == (1 + 2 + 4 + 8 + 16));

        bool8_set(&b,4,0);
        assert(b == (1 + 2 + 4 + 8));
ctestend