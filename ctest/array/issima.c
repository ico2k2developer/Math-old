//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array a;
        array b;

        a.bytes = 10;
        a.used = 0;
        b.bytes = 10;
        b.used = 0;
        assert(issima(&a,&b));

        a.bytes = 10;
        a.used = 1;
        b.bytes = 10;
        b.used = 5;
        assert(issima(&a,&b));

        a.bytes = 0;
        a.used = 0;
        b.bytes = 0;
        b.used = 0;
        assert(issima(&a,&b));

        assert(!issima(NULL,&b));
        assert(!issima(&a,NULL));
        assert(issima(NULL,NULL));
ctestend