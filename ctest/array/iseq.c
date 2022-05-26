//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p a;
        array_p b;
        TYPE_ARRAY_SIZE i;

        a = array_new(10);
        b = array_new(10);
        foreach(10,i)
        {
            seta(a,i,(i + 1) * 2);
            seta(b,i,(i + 1) * 2);
            a->used++;
            b->used++;
        }
        assert(array_iseq(a, b));

        a->used--;
        assert(!array_iseq(a, b));

        a->used++;
        b->bytes--;
        assert(!array_iseq(a, b));

        b->bytes++;
        seta(b,4,0);
        assert(!array_iseq(a, b));

        assert(!array_iseq(a, NULL));
        assert(!array_iseq(NULL, b));
        assert(array_iseq(NULL, NULL));

        array_del(a);
        array_del(b);
ctestend