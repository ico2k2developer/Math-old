//
// Created by ico2k2 on 26/5/2022.
//
#include "../../test.h"

#include "numbers/numbers.h"

cteststart()
        number_N_p n;

        n = number_N_new(0);
        nonnull(n);
        zero(n->value);
        number_N_del(n);

        n = number_N_new(1);
        nonnull(n);
        one(n->value);
        number_N_del(n);

        n = number_N_new(NUMBER_N_INF);
        nonnull(n);
        assert(n->value == NUMBER_N_INF);
        number_N_del(n);
ctestend