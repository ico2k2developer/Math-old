//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        arrayp s1 = newas("ABCDEF123",9);
        arrayp s2 = newas("GHIJKL",6);
        TYPE_ARRAY_SIZE i;

        assert(s1 == stracpy(s1,s2));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s2 == stracpy(s2,NULL));
        nonnull(s2);
        assert(s2->bytes == (sizeof(char) * 7));
        foreach(s2->bytes,i)
            zero(geta(s2,i));
        zero(s2->used);

        null(stracpy(NULL,s1));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        null(stracpy(NULL,NULL));
ctestend