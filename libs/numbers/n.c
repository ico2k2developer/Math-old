//
// Created by Ico on 26/5/2022.
//

#include "n.h"

TYPE_NUMBER_N number_N_value(const number_N_p n)
{
    if(n)
        return n->value;
    else
        return MIN_NUMBER_N;
}

#if NUMBER_N_INCLUDES_0
bool8_t number_N_zero(number_N_p inf)
{
    return number_N_value(inf) == 0;
}
#endif

bool8_t number_N_inf(number_N_p inf)
{
    return number_N_value(inf) == NUMBER_N_INF;
}

bool8_t number_N_mayor(number_N_p mayor,number_N_p than)
{
    return number_N_value(mayor) > number_N_value(than);
}

bool8_t number_N_mayoreq(number_N_p mayoreq,number_N_p than)
{
    return number_N_value(mayoreq) >= number_N_value(than);
}

bool8_t number_N_minor(number_N_p minor,number_N_p than)
{
    return number_N_value(minor) < number_N_value(than);
}

bool8_t number_N_minoreq(number_N_p minoreq,number_N_p than)
{
    return number_N_value(minoreq) <= number_N_value(than);
}

bool8_t number_N_equal(number_N_p equal,number_N_p to)
{
    return number_N_value(equal) == number_N_value(to);
}

number_N_p number_N_sum(number_N_p target,number_N_p add)
{
    if(number_N_inf(target) || number_N_inf(add))
        target->value = NUMBER_N_INF;
    else
        target->value += number_N_value(add);
    return target;
}

number_N_p number_N_prod(number_N_p target,number_N_p prod)
{
#if NUMBER_N_INCLUDES_0
    if(number_N_zero(target) || number_N_zero(prod))
        target->value = 0;
    else if
#else
    if
#endif
        (number_N_inf(target) || number_N_inf(prod))
        target->value = NUMBER_N_INF;
    else
        target->value *= number_N_value(prod);
    return target;
}

number_N_p number_N_div(number_N_p target,number_N_p div)
{
#if NUMBER_N_INCLUDES_0
    if(number_N_zero(target) || number_N_zero(div))
        target->value = 0;
    else if
#else
    if
#endif
        (number_N_inf(target) && !number_N_inf(div))
        target->value = NUMBER_N_INF;
    else if(!number_N_inf(target) && number_N_inf(div))
        target->value = MIN_NUMBER_N;
    else if(number_N_inf(target) && number_N_inf(div))
        target->value = 1;
    return target;
}