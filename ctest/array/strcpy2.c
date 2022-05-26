//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p s1 = array_news("ABCDEF123", 9);
        TYPE_ARRAY_SIZE i;

        assert(s1 == array_strcpy2(s1, "GHIJKL"));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        null(array_strcpy2(NULL, atos(s1)));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == array_strcpy2(s1, NULL));
        nonnull(s1);
        assert(s1->bytes == (sizeof(char) * 10));
        foreach(s1->bytes,i)
            zero(geta(s1,i));
        zero(s1->used);

        null(array_strcpy2(NULL, NULL));
ctestend