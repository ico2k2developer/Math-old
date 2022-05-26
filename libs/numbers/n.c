//
// Created by Ico on 26/5/2022.
//
#include "n.h"

number_N_p number_N_new(const TYPE_NUMBER_N value)
{
    number_N_p result = (number_N_p) malloc(sizeof(number_N_t));
    if(result)
        number_N_assign(result,value);
    return result;
}

void number_N_del(const number_N_p n)
{
    free(n);
}

TYPE_NUMBER_N number_N_value(const number_N_p n)
{
    if(n)
        return n->value;
    else
        return MIN_NUMBER_N;
}

char* number_N_print(const number_N_p n)
{
    char* string = (char*)malloc(sizeof(char) * (NUMBER_N_MAX_DIGITS + 1));
    if(string)
    {
        if(number_N_inf(n))
            strcpy_s(string,NUMBER_N_MAX_DIGITS + 1,"inf");
        else
            sprintf_s(string,NUMBER_N_MAX_DIGITS + 1,NUMBER_N_PRINTF_PLHDR,number_N_value(n));
    }
    return string;
}

number_N_p number_N_assign(const number_N_p n,const TYPE_NUMBER_N value)
{
    n->value = value;
    return n;
}

bool8_t number_N_zero(const number_N_p inf)
{
    return number_N_value(inf) == MIN_NUMBER_N;
}

bool8_t number_N_inf(const number_N_p inf)
{
    return number_N_value(inf) == NUMBER_N_INF;
}

bool8_t number_N_mayor(const number_N_p mayor,const number_N_p than)
{
    return number_N_value(mayor) > number_N_value(than);
}

bool8_t number_N_mayoreq(const number_N_p mayoreq,const number_N_p than)
{
    return number_N_value(mayoreq) >= number_N_value(than);
}

bool8_t number_N_minor(const number_N_p minor,const number_N_p than)
{
    return number_N_value(minor) < number_N_value(than);
}

bool8_t number_N_minoreq(const number_N_p minoreq,const number_N_p than)
{
    return number_N_value(minoreq) <= number_N_value(than);
}

bool8_t number_N_equal(const number_N_p equal,const number_N_p to)
{
    return number_N_value(equal) == number_N_value(to);
}

number_N_p number_N_sum(const number_N_p target,const number_N_p add)
{
    if(number_N_inf(target) || number_N_inf(add))
        number_N_assign(target,NUMBER_N_INF);
    else
        number_N_assign(target,number_N_value(target) + number_N_value(add));
    return target;
}

number_N_p number_N_diff(const number_N_p target,const number_N_p sub)
{
    if(number_N_inf(target) || number_N_inf(sub))
    {
        if(number_N_equal(target,sub))
            number_N_assign(target,MIN_NUMBER_N);
        else
            number_N_assign(target,NUMBER_N_INF);
    }
    else
    {
        if(number_N_mayor(target,sub))
            number_N_assign(target,number_N_value(target) - number_N_value(sub));
        else
            number_N_assign(target,number_N_value(sub) - number_N_value(target));
    }
    return target;
}

number_N_p number_N_prod(const number_N_p target,const number_N_p prod)
{
    if(number_N_inf(target) || number_N_inf(prod))
    {
        if(number_N_zero(target) || number_N_zero(prod))
            number_N_assign(target,MIN_NUMBER_N);
        else
            number_N_assign(target,NUMBER_N_INF);
    }
    else
        number_N_assign(target,number_N_value(target) * number_N_value(prod));
    return target;
}

number_N_p number_N_div(const number_N_p target,const number_N_p div)
{
    if(number_N_zero(div))
        number_N_assign(target,NUMBER_N_INF);
    else if(number_N_inf(div))
    {
        if(number_N_inf(target))
            number_N_assign(target,1);
        else
            number_N_assign(target,MIN_NUMBER_N);
    }
    else if(!number_N_inf(target))
    {
        if(number_N_mayor(div,target))
            number_N_assign(target,MIN_NUMBER_N);
        else
            number_N_assign(target, number_N_value(target) / number_N_value(div));
    }
    return target;
}