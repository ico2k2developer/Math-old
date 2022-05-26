//
// Created by ico2k2 on 27/5/2022.
//
#include "../../test.h"

#include "numbers/numbers.h"

cteststart()
        number_N_p n = number_N_new(0);
        char* s;

        number_N_assign(n,0);
        s = number_N_print(n);
        zero(strcmp(s,"0"));
        free(s);

        n = number_N_new(1);
        s = number_N_print(n);
        zero(strcmp(s,"1"));
        free(s);

        n = number_N_new(NUMBER_N_INF);
        s = number_N_print(n);
        zero(strcmp(s,"inf"));
        free(s);

        number_N_del(n);
ctestend