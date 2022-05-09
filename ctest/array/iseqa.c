//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        arrayp a;
        arrayp b;
        TYPE_ARRAY_SIZE i;

        a = newa(10);
        b = newa(10);
        foreach(10,i)
        {
            seta(a,i,(i + 1) * 2);
            seta(b,i,(i + 1) * 2);
            a->used++;
            b->used++;
        }
        assert(iseqa(a,b));

        a->used--;
        assert(!iseqa(a,b));

        a->used++;
        b->bytes--;
        assert(!iseqa(a,b));

        b->bytes++;
        seta(b,4,0);
        assert(!iseqa(a,b));

        assert(!iseqa(a,NULL));
        assert(!iseqa(NULL,b));
        assert(iseqa(NULL,NULL));
ctestend