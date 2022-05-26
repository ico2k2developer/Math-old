//
// Created by ico2k2 on 26/5/2022.
//
#include "../../test.h"

#include "numbers/numbers.h"

cteststart()
        number_N_t a,b;

        a.value = 0;
        b.value = 0;
        number_N_diff(&a,&b);
        zero(a.value);

        a.value = 0;
        b.value = 1;
        number_N_diff(&a,&b);
        one(a.value);

        a.value = 2;
        b.value = 1;
        number_N_diff(&a,&b);
        one(a.value);

        a.value = 2;
        b.value = NUMBER_N_INF;
        number_N_diff(&a,&b);
        assert(a.value == NUMBER_N_INF);

        a.value = NUMBER_N_INF;
        b.value = NUMBER_N_INF;
        number_N_diff(&a,&b);
        zero(a.value);

        a.value = NUMBER_N_INF;
        b.value = 0;
        number_N_diff(&a,&b);
        assert(a.value == NUMBER_N_INF);
ctestend