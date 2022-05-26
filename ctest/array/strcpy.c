//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p s1 = array_news("ABCDEF123", 9);
        array_p s2 = array_news("GHIJKL", 6);
        TYPE_ARRAY_SIZE i;

        assert(s1 == array_strcpy(s1, s2));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s2 == array_strcpy(s2, NULL));
        nonnull(s2);
        assert(s2->bytes == (sizeof(char) * 7));
        foreach(s2->bytes,i)
            zero(geta(s2,i));
        zero(s2->used);

        null(array_strcpy(NULL, s1));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        null(array_strcpy(NULL, NULL));

        array_del(s1);
        array_del(s2);
ctestend