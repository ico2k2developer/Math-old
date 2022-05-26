//
// Created by ico2k2 on 26/5/2022.
//
#include "../test.h"

#include <bool8.h>

cteststart()
        bool8_t b = 0xFF;

        bool8_uncheck(&b,0);
        assert(b == (2 + 4 + 8 + 16 + 32 + 64 + 128));

        bool8_uncheck(&b,3);
        assert(b == (2 + 4 + 16 + 32 + 64 + 128));

        bool8_uncheck(&b,5);
        assert(b == (2 + 4 + 16 + 64 + 128));

        bool8_uncheck(&b,7);
        assert(b == (2 + 4 + 16 + 64));
ctestend