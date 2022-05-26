//
// Created by ico2k2 on 8/5/2022.
//
#include "../test.h"

#include <array.h>

cteststart()
        array_p a;

        a = array_new(10);
        array_del(a);

        a = array_new(5);
        array_resize(&a, 0);
        array_del(a);
ctestend