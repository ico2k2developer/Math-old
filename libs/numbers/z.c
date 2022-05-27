//
// Created by Ico on 27/5/2022.
//
#include "z.h"

number_Z_p number_Z_new(const bool8_t sign,const TYPE_NUMBER_Z value)
{
    number_Z_p result;
    return number_Z_alloc(&result,sign,value);
}

number_Z_p number_Z_alloc(number_Z_p* target,const bool8_t sign,const TYPE_NUMBER_Z value)
{
    *target = (number_Z_p)malloc(sizeof(number_Z_t));
    if(*target)
    {
        number_N_assign(&((*target)->value),value);
        (*target)->sign = sign ? TRUE : FALSE;
    }
    return *target;
}

number_Z_p number_Z_clone(const number_Z_p source)
{
    return number_Z_new(number_Z_sign(source),number_Z_value(source));
}

number_Z_p number_Z_overwrite(number_Z_p target,number_Z_p source)
{
    target->value = source->value;
    target->sign = source->sign;
    return target;
}

void number_Z_del(number_Z_p n)
{
    free(n);
}

number_N_p number_Z_toN(number_Z_p n)
{
    return &n->value;
}

bool8_t number_Z_sign(number_Z_p sign)
{
    return sign->sign;
}

TYPE_NUMBER_Z number_Z_value(number_Z_p n)
{
    return number_N_value(number_Z_toN(n));
}

array_p number_Z_print(number_Z_p n,array_p* string)
{
    array_ensuresize(string,sizeof(char) * (NUMBER_Z_MAX_DIGITS + 1));
    if(number_Z_sign(n))
        seta(*string,0,CHAR_PLUS_SIGN);
    else
        seta(*string,0,CHAR_MINUS_SIGN);
    array_p new = array_new(sizeof(char) * (NUMBER_Z_MAX_DIGITS + 1));
    number_N_print(number_Z_toN(n),&new);
    return string;
}

number_Z_p number_Z_assign(number_Z_p n,TYPE_NUMBER_N value);

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

#include "z.h"
