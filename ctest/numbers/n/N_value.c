//
// Created by ico2k2 on 26/5/2022.
//
#include "../../test.h"

#include "numbers/numbers.h"

cteststart()
        number_N_t n;

        n.value = 0;
        zero(number_N_value(&n));

        n.value = 1;
        one(number_N_value(&n));

        n.value = NUMBER_N_INF;
        assert(number_N_value(&n) == NUMBER_N_INF);
ctestend