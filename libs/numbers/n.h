//
// Created by Ico on 26/5/2022.
//

#ifndef MATH2_N_H
#define MATH2_N_H

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <bool8.h>
#include <array.h>

#define TYPE_NUMBER_N       uint_fast64_t
#define MIN_NUMBER_N        0
#define MAX_NUMBER_N        UINT_FAST64_MAX - 2

#define NUMBER_N_INF        UINT_FAST64_MAX
#define NUMBER_N_IMP        UINT_FAST64_MAX - 1

#define NUMBER_N_MAX_DIGITS     20

typedef struct
{
    TYPE_NUMBER_N value;
}number_N_t;

typedef number_N_t* number_N_p;

number_N_p number_N_new(TYPE_NUMBER_N value);
number_N_p number_N_alloc(number_N_p* target,TYPE_NUMBER_N value);
number_N_p number_N_clone(number_N_p source);
number_N_p number_N_overwrite(number_N_p target,number_N_p source);
void number_N_del(number_N_p n);

TYPE_NUMBER_N number_N_value(number_N_p n);
array_p number_N_print(number_N_p n,array_p* string);
number_N_p number_N_assign(number_N_p n,TYPE_NUMBER_N value);

bool8_t number_N_zero(number_N_p inf);
bool8_t number_N_inf(number_N_p inf);
bool8_t number_N_imp(number_N_p imp);
bool8_t number_N_valid(number_N_p n);
bool8_t number_N_regular(number_N_p n);

bool8_t number_N_mayor(number_N_p mayor,number_N_p than);
bool8_t number_N_mayoreq(number_N_p mayoreq,number_N_p than);
bool8_t number_N_minor(number_N_p minor,number_N_p than);
bool8_t number_N_minoreq(number_N_p minoreq,number_N_p than);
bool8_t number_N_equal(number_N_p equal,number_N_p to);
bool8_t number_N_mayor_raw(number_N_p mayor,TYPE_NUMBER_N than);
bool8_t number_N_mayoreq_raw(number_N_p mayoreq,TYPE_NUMBER_N than);
bool8_t number_N_minor_raw(number_N_p minor,TYPE_NUMBER_N than);
bool8_t number_N_minoreq_raw(number_N_p minoreq,TYPE_NUMBER_N than);
bool8_t number_N_equal_raw(number_N_p equal,TYPE_NUMBER_N to);

number_N_p number_N_sum(number_N_p target,number_N_p add);
number_N_p number_N_diff(number_N_p target,number_N_p sub);
number_N_p number_N_prod(number_N_p target,number_N_p prod);
number_N_p number_N_div(number_N_p target,number_N_p div);
number_N_p number_N_remainder(number_N_p target,number_N_p div);
number_N_p number_N_pow(number_N_p target,number_N_p pow);
number_N_p number_N_sum_raw(number_N_p target,TYPE_NUMBER_N add);
number_N_p number_N_diff_raw(number_N_p target,TYPE_NUMBER_N sub);
number_N_p number_N_prod_raw(number_N_p target,TYPE_NUMBER_N prod);
number_N_p number_N_div_raw(number_N_p target,TYPE_NUMBER_N div);
number_N_p number_N_remainder_raw(number_N_p target,TYPE_NUMBER_N div);
number_N_p number_N_pow_raw(number_N_p target,TYPE_NUMBER_N pow);

#endif //MATH2_N_H
