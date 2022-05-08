//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

ctest(
        arrayp source = newa0(10);
        TYPE_ARRAY_SIZE i;
        foreachau(source,i)
            seta(source,i,(i + 1) * 2);
        arrayp copy;

        copy = copya(source);
        nonnull(copy);
        assert(copy->bytes == source->bytes);
        assert(copy->used == source->used);
        nonnull(copy->a);
        foreachau(copy,i)
            assert(geta(source,i) == ((i + 1) * 2));

        source->a = NULL;
        copy = copya(source);
        nonnull(copy);
        assert(copy->bytes == source->bytes);
        assert(copy->used == source->used);
        null(copy->a);

        null(copya(NULL));
)