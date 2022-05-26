//
// Created by Ico on 26/5/2022.
//

#ifndef MATH2_N_H
#define MATH2_N_H

#include <stdint.h>
#include <bool8.h>

#define TYPE_NUMBER_N       uint_fast64_t
#define MIN_NUMBER_N        0
#define MAX_NUMBER_N        UINT_FAST64_MAX - 1

#define NUMBER_N_INCLUDES_0 (MIN_NUMBER_N == 0)
#define NUMBER_N_INF        UINT_FAST64_MAX

typedef struct
{
    TYPE_NUMBER_N value;
}number_N_t;

typedef number_N_t* number_N_p;

TYPE_NUMBER_N number_N_value(number_N_p n);

#if NUMBER_N_INCLUDES_0
bool8_t number_N_zero(number_N_p inf);
#endif
bool8_t number_N_inf(number_N_p inf);

bool8_t number_N_mayor(number_N_p mayor,number_N_p than);
bool8_t number_N_mayoreq(number_N_p mayoreq,number_N_p than);
bool8_t number_N_minor(number_N_p minor,number_N_p than);
bool8_t number_N_minoreq(number_N_p minoreq,number_N_p than);
bool8_t number_N_equal(number_N_p equal,number_N_p to);

number_N_p number_N_sum(number_N_p target,number_N_p add);
number_N_p number_N_prod(number_N_p target,number_N_p prod);
number_N_p number_N_div(number_N_p target,number_N_p div);

#endif //MATH2_N_H
