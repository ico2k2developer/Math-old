//
// Created by ico2k2 on 26/5/2022.
//
#include "../../test.h"

#include "numbers/numbers.h"

cteststart()
        number_N_t n;

        number_N_assign(&n,0);
        zero(n.value);

        number_N_assign(&n,1);
        one(n.value);

        number_N_assign(&n,NUMBER_N_INF);
        assert(n.value == NUMBER_N_INF);
ctestend