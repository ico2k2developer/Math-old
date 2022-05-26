//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p a = array_new(2);
        seta(a,0,3);
        seta(a,1,7);
        a->used = 2;

        assert(array_resize(&a, 2) == a);
        assert(a->bytes == 2);
        assert(a->used == 2);
        nonnull(a->a);
        assert(geta(a,0) == 3);
        assert(geta(a,1) == 7);

        nonnull(array_resize(&a, 10));
        assert(a->bytes == 10);
        assert(a->used == 2);
        nonnull(a->a);
        assert(geta(a,0) == 3);
        assert(geta(a,1) == 7);

        nonnull(array_resize(&a, 0));
        zero(a->bytes);
        zero(a->used);
        null(a->a);

        nonnull(array_resize(&a, 5));
        assert(a->bytes == 5);
        zero(a->used);
        nonnull(a->a);

        null(array_resize(NULL, 0));
ctestend