//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p a;

        a = array_new(1);
        nonnull(a);
        nonnull(a->data);
        assert(a->bytes == 1);
        zero(a->used);

        a = array_new(2);
        seta(a,0,4);
        a->used++;
        nonnull(a);
        nonnull(a->data);
        assert(a->bytes == 2);
        assert(a->used == 1);
        assert(geta(a,0) == 4);

        a = array_new(0);
        nonnull(a);
        nonnull(a->data);
        zero(a->bytes);
        zero(a->used);
ctestend