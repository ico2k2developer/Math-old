//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p s1 = array_news("ABCDEF123", 9);
        TYPE_ARRAY_SIZE i;

        assert(s1 == array_strncpy2(s1,15,"GHIJKL"));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == array_strncpy2(s1,15,"GHIJKL"));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == array_strncpy2(s1,0,"987654"));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == array_strncpy2(s1,3,"QWERTY"));
        nonnull(s1);
        zero(strcmp("QWE", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 4));
        assert(s1->used == 3);
        zero(geta(s1,3));

        null(array_strncpy2(NULL,33,atos(s1)));
        nonnull(s1);
        zero(strcmp("QWE", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 4));
        assert(s1->used == 3);
        zero(geta(s1,3));

        assert(s1 == array_strncpy2(s1,33, NULL));
        nonnull(s1);
        zero(strcmp("QWE", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 4));
        assert(s1->used == 3);
        zero(geta(s1,3));

        null(array_strncpy2(NULL,10, NULL));
ctestend