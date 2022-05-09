//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        arrayp a;

        a = newa(1);
        nonnull(a);
        nonnull(a->a);
        assert(a->bytes == 1);
        zero(a->used);

        a = newa(2);
        seta(a,0,4);
        a->used++;
        nonnull(a);
        nonnull(a->a);
        assert(a->bytes == 2);
        assert(a->used == 1);
        assert(geta(a,0) == 4);

        a = newa(0);
        nonnull(a);
        nonnull(a->a);
        zero(a->bytes);
        zero(a->used);
ctestend