//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p a;
        TYPE_ARRAY_SIZE i;

        a = array_new0(1);
        nonnull(a);
        nonnull(a->a);
        assert(a->bytes == 1);
        zero(a->used);
        foreach(a->bytes,i)
            zero(geta(a,i));

        a = array_new0(2);
        seta(a,0,4);
        a->used++;
        nonnull(a);
        nonnull(a->a);
        assert(a->bytes == 2);
        assert(a->used == 1);
        assert(geta(a,0) == 4);
        assert(geta(a,1) == 0);

        a = array_new0(0);
        nonnull(a);
        nonnull(a->a);
        zero(a->bytes);
        zero(a->used);
        foreach(a->bytes,i)
            zero(geta(a,i));
ctestend