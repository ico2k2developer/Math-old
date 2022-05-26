//
// Created by ico2k2 on 26/5/2022.
//
#include "../../test.h"

#include "numbers/numbers.h"

cteststart()
        number_N_t a,b;

        a.value = 0;
        b.value = 0;
        assert(number_N_equal(&a,&b));

        a.value = 0;
        b.value = 1;
        assert(!number_N_equal(&a,&b));

        a.value = 2;
        b.value = 1;
        assert(!number_N_equal(&a,&b));

        a.value = 2;
        b.value = NUMBER_N_INF;
        assert(!number_N_equal(&a,&b));

        a.value = NUMBER_N_INF;
        b.value = NUMBER_N_INF;
        assert(number_N_equal(&a,&b));

        a.value = NUMBER_N_INF;
        b.value = 0;
        assert(!number_N_equal(&a,&b));
ctestend