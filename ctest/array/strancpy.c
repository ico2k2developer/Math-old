//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        arrayp s1 = newas("ABCDEF123",9);
        arrayp s2 = newas("GHIJKL",6);
        TYPE_ARRAY_SIZE i;

        assert(s1 == strancpy(s1,15,s2));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s2 == strancpy(s2,3,NULL));
        nonnull(s2);
        assert(s2->bytes == (sizeof(char) * 7));
        foreach(3,i)
            zero(geta(s2,i));
        for(; i < s2->used; i++)
            nonzero(geta(s2,i));
        zero(s2->used);

        null(strancpy(NULL,5,s1));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == strancpy(s1,0,s2));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        assert(s1 == strancpy(s1,0,NULL));
        nonnull(s1);
        zero(strcmp("GHIJKL", atos(s1)));
        assert(s1->bytes == (sizeof(char) * 10));
        assert(s1->used == 6);
        zero(geta(s1,6));

        null(strancpy(NULL,0,s1));
        null(strancpy(NULL,5,NULL));
        null(strancpy(NULL,0,NULL));
ctestend