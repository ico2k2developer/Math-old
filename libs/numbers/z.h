//
// Created by Ico on 27/5/2022.
//

#ifndef MATH2_Z_H
#define MATH2_Z_H

#include "n.h"

#define CHAR_PLUS_SIGN      '+'
#define CHAR_MINUS_SIGN     '-'

#define TYPE_NUMBER_Z       TYPE_NUMBER_N
#define MAX_NUMBER_Z        MAX_NUMBER_Z

#define NUMBER_Z_INF        NUMBER_N_INF
#define NUMBER_Z_IMP        NUMBER_N_IMP

#define NUMBER_Z_MAX_DIGITS     NUMBER_N_MAX_DIGITS + 1

typedef struct
{
    number_N_t value;
    bool8_t sign;
}number_Z_t;

typedef number_Z_t* number_Z_p;

number_Z_p number_Z_new(bool8_t sign,TYPE_NUMBER_Z value);
number_Z_p number_Z_alloc(number_Z_p* target,bool8_t sign,TYPE_NUMBER_Z value);
number_Z_p number_Z_clone(number_Z_p source);
number_Z_p number_Z_overwrite(number_Z_p target,number_Z_p source);
void number_Z_del(number_Z_p n);
number_N_p number_Z_toN(number_Z_p n);

bool8_t number_Z_sign(number_Z_p sign);
TYPE_NUMBER_Z number_Z_value(number_Z_p n);
array_p number_Z_print(number_Z_p n,array_p* string);
number_Z_p number_Z_assign(number_Z_p n,TYPE_NUMBER_Z value);

bool8_t number_Z_zero(number_Z_p inf);
bool8_t number_Z_inf(number_Z_p inf);
bool8_t number_Z_imp(number_Z_p imp);
bool8_t number_Z_valid(number_Z_p n);
bool8_t number_Z_regular(number_Z_p n);

bool8_t number_Z_mayor(number_Z_p mayor,number_Z_p than);
bool8_t number_Z_mayoreq(number_Z_p mayoreq,number_Z_p than);
bool8_t number_Z_minor(number_Z_p minor,number_Z_p than);
bool8_t number_Z_minoreq(number_Z_p minoreq,number_Z_p than);
bool8_t number_Z_equal(number_Z_p equal,number_Z_p to);

number_Z_p number_Z_sum(number_Z_p target,number_Z_p add);
number_Z_p number_Z_diff(number_Z_p target,number_Z_p sub);
number_Z_p number_Z_prod(number_Z_p target,number_Z_p prod);
number_Z_p number_Z_div(number_Z_p target,number_Z_p div);
number_Z_p number_Z_remainder(number_Z_p target,number_Z_p div);
number_Z_p number_Z_pow(number_Z_p target,number_Z_p pow);

#endif //MATH2_Z_H
