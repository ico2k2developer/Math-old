//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        arrayp a = newa(2);
        seta(a,0,3);
        seta(a,1,7);
        a->used = 2;

        assert(ensuresize(&a,2) == a);
        assert(a->bytes == 2);
        assert(a->used == 2);
        nonnull(a->a);
        assert(geta(a,0) == 3);
        assert(geta(a,1) == 7);

        nonnull(ensuresize(&a,10));
        assert(a->bytes == 10);
        assert(a->used == 2);
        nonnull(a->a);
        assert(geta(a,0) == 3);
        assert(geta(a,1) == 7);

        nonnull(ensuresize(&a,0));
        assert(a->bytes == 10);
        assert(a->used == 2);
        nonnull(a->a);
        assert(geta(a,0) == 3);
        assert(geta(a,1) == 7);

        nonnull(ensuresize(&a,5));
        assert(a->bytes == 10);
        assert(a->used == 2);
        nonnull(a->a);
        assert(geta(a,0) == 3);
        assert(geta(a,1) == 7);

        null(ensuresize(NULL,0));
ctestend