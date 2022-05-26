//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p source = array_new0(10);
        TYPE_ARRAY_SIZE i;
        foreachau(source,i)
            seta(source,i,(i + 1) * 2);
        array_p copy;

        copy = array_copy(source);
        nonnull(copy);
        assert(copy->bytes == source->bytes);
        assert(copy->used == source->used);
        nonnull(copy->data);
        foreachau(copy,i)
            assert(geta(source,i) == ((i + 1) * 2));

        source->data = NULL;
        copy = array_copy(source);
        nonnull(copy);
        assert(copy->bytes == source->bytes);
        assert(copy->used == source->used);
        null(copy->data);

        null(array_copy(NULL));

        array_del(source);
        array_del(copy);
ctestend