//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        arrayp s1 = newas("ABCDEF123",9);
        TYPE_ARRAY_SIZE i;

        assert(s1 == strancpy2(s1,15,"987654"));
        nonnull(s1);
        zero(strcmp("987654", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == strancpy2(s1,6,"LMNOPQRSTU"));
        nonnull(s1);
        zero(strcmp("LMNOPQ", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == strancpy2(s1,0,"JKL"));
        nonnull(s1);
        zero(strcmp("LMNOPQ", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        null(strancpy2(NULL,5,"NULL"));
        nonnull(s1);
        zero(strcmp("LMNOPQ", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == strancpy2(s1,0,NULL));
        nonnull(s1);
        zero(strcmp("LMNOPQ", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == strancpy2(s1,3,NULL));
        nonnull(s1);
        assert(s1->bytes == (sizeof(char) * 10));
        foreach(3,i)
            zero(geta(s1,i));
        for(; i < s1->used; i++)
            nonzero(geta(s1,i));
        zero(s1->used);

        null(strancpy2(NULL,0,"NULL"));
        null(strancpy2(NULL,5,NULL));
        null(strancpy2(NULL,0,NULL));
ctestend