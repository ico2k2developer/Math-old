//
// Created by ico2k2 on 26/5/2022.
//
#include "../test.h"

#include <bool8.h>

cteststart()
        bool8_t b;
        uint8_t i;

        b = 0;
        for(i = 0; i < (sizeof(b) * 8); i++)
            zero(bool8_get(b,i));

        b = 1;
        one(bool8_get(b,0));
        for(i = 1; i < (sizeof(b) * 8); i++)
            zero(bool8_get(b,i));

        b = 0xF0;
        for(i = 0; i < (sizeof(b) * 8 / 2); i++)
            zero(bool8_get(b,i));
        for(; i < (sizeof(b) * 8); i++)
            one(bool8_get(b,i));

        b = 0xFF;
        for(i = 0; i < (sizeof(b) * 8); i++)
            one(bool8_get(b,i));
ctestend