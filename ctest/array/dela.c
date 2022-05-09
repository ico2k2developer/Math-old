//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        arrayp a;

        a = newa(10);
        dela(a);

        a = newa(5);
        resize(&a,0);
        dela(a);
ctestend