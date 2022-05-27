//
// Created by Ico on 26/5/2022.
//
#include "n.h"

number_N_p number_N_new(const TYPE_NUMBER_N value)
{
    number_N_p result;
    return number_N_alloc(&result,value);
}

number_N_p number_N_alloc(number_N_p* target,const TYPE_NUMBER_N value)
{
    *target = (number_N_p)malloc(sizeof(number_N_t));
    if(*target)
        number_N_assign(*target,value);
    return *target;
}

number_N_p number_N_clone(const number_N_p source)
{
    return number_N_new(number_N_value(source));
}

number_N_p number_N_overwrite(const number_N_p target,const number_N_p source)
{
    target->value = source->value;
    return target;
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

array_p number_N_print(const number_N_p n,array_p* string)
{
    array_ensuresize(string,sizeof(char) * (NUMBER_N_MAX_DIGITS + 1));
    switch(number_N_value(n))
    {
        case NUMBER_N_INF:
        {
            array_strcpy2(*string,"infinite");
            break;
        }
        case NUMBER_N_IMP:
        {
            array_strcpy2(*string,"empty set");
            break;
        }
        default:
        {
            sprintf_s(atos(*string),NUMBER_N_MAX_DIGITS + 1,"%" PRIuFAST64,number_N_value(n));
        }
    }
    return *string;
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

bool8_t number_N_imp(const number_N_p imp)
{
    return number_N_value(imp) == NUMBER_N_IMP;
}

bool8_t number_N_valid(const number_N_p n)
{
    return !number_N_imp(n);
}

bool8_t number_N_regular(const number_N_p n)
{
    return number_N_valid(n) && !number_N_inf(n);
}

bool8_t number_N_mayor(const number_N_p mayor,const number_N_p than)
{
    if(number_N_valid(mayor) && number_N_valid(than))
        return number_N_value(mayor) > number_N_value(than);
    else
        return FALSE;
}

bool8_t number_N_mayoreq(const number_N_p mayoreq,const number_N_p than)
{
    if(number_N_equal(mayoreq,than))
        return TRUE;
    else if(number_N_valid(mayoreq) && number_N_valid(than))
        return number_N_mayor(mayoreq,than);
    else
        return FALSE;
}

bool8_t number_N_minor(const number_N_p minor,const number_N_p than)
{
    if(number_N_valid(minor) && number_N_valid(than))
        return number_N_value(minor) < number_N_value(than);
    else
        return FALSE;
}

bool8_t number_N_minoreq(const number_N_p minoreq,const number_N_p than)
{
    if(number_N_equal(minoreq,than))
        return TRUE;
    else if(number_N_valid(minoreq) && number_N_valid(than))
        return number_N_minor(minoreq,than);
    else
        return FALSE;
}

bool8_t number_N_mayor_raw(const number_N_p mayor,const TYPE_NUMBER_N than)
{
    return number_N_value(mayor) > than;
}

bool8_t number_N_mayoreq_raw(const number_N_p mayoreq,const TYPE_NUMBER_N than)
{
    if(number_N_valid(mayoreq))
        return number_N_value(mayoreq) >= than;
    else
        return FALSE;
}

bool8_t number_N_minor_raw(const number_N_p minor,const TYPE_NUMBER_N than)
{
    return number_N_value(minor) < than;
}

bool8_t number_N_minoreq_raw(const number_N_p minoreq,const TYPE_NUMBER_N than)
{
    if(number_N_valid(minoreq))
        return number_N_value(minoreq) <= than;
    else
        return FALSE;
}

bool8_t number_N_equal(const number_N_p equal,const number_N_p to)
{
    return number_N_value(equal) == number_N_value(to);
}

bool8_t number_N_equal_raw(const number_N_p equal,const TYPE_NUMBER_N to)
{
    return number_N_value(equal) == to;
}

number_N_p number_N_sum(const number_N_p target,const number_N_p add)
{
    if(number_N_valid(target) && number_N_valid(add))
    {
        if(number_N_inf(target) || number_N_inf(add))
            number_N_assign(target,NUMBER_N_INF);
        else
            number_N_assign(target,number_N_value(target) + number_N_value(add));
    }
    return target;
}

number_N_p number_N_diff(const number_N_p target,const number_N_p sub)
{
    if(number_N_valid(target) && number_N_valid(sub)) {
        if (number_N_inf(target) || number_N_inf(sub)) {
            if (number_N_equal(target, sub))
                number_N_assign(target, MIN_NUMBER_N);
            else
                number_N_assign(target, NUMBER_N_INF);
        } else {
            if (number_N_mayor(target, sub))
                number_N_assign(target, number_N_value(target) - number_N_value(sub));
            else
                number_N_assign(target, number_N_value(sub) - number_N_value(target));
        }
    }
    return target;
}

number_N_p number_N_prod(const number_N_p target,const number_N_p prod)
{
    if(number_N_valid(target) && number_N_valid(prod)) {
        if (number_N_inf(target) || number_N_inf(prod)) {
            if (number_N_zero(target) || number_N_zero(prod))
                number_N_assign(target, MIN_NUMBER_N);
            else
                number_N_assign(target, NUMBER_N_INF);
        } else
            number_N_assign(target, number_N_value(target) * number_N_value(prod));
    }
    return target;
}

number_N_p number_N_div(const number_N_p target,const number_N_p div)
{
    if(number_N_valid(target) && number_N_valid(div)) {
        if (number_N_zero(div))
            number_N_assign(target, NUMBER_N_INF);
        else if (number_N_inf(div)) {
            if (number_N_inf(target))
                number_N_assign(target, 1);
            else
                number_N_assign(target, MIN_NUMBER_N);
        } else if (!number_N_inf(target)) {
            if (number_N_mayor(div, target))
                number_N_assign(target, MIN_NUMBER_N);
            else
                number_N_assign(target, number_N_value(target) / number_N_value(div));
        }
    }
    return target;
}

number_N_p number_N_remainder(const number_N_p target,const number_N_p div)
{
    if(number_N_valid(target) && number_N_valid(div))
    {
        number_N_p clone = number_N_clone(target);
        number_N_div(clone,div);
        number_N_prod(clone,div);
        number_N_diff(target,clone);
        number_N_del(clone);
    }
    return target;
}

number_N_p number_N_pow(const number_N_p target,const number_N_p pow)
{
    if(number_N_regular(target) && number_N_valid(pow))
    {
        if(number_N_inf(pow))
        {
            if(!number_N_zero(target))
                number_N_assign(target,NUMBER_N_INF);
        }
        else if(number_N_zero(pow))
            number_N_assign(target,1);
        else if(!number_N_equal_raw(pow,1))
        {
            if(number_N_equal_raw(target,2))
                number_N_assign(target, number_N_value(target) << (number_N_value(pow) - 1));
            else
            {

                number_N_p base = number_N_clone(target);
                number_N_p clone = number_N_clone(pow);
                number_N_p one = number_N_new(1);
                while(number_N_mayor(clone,one))
                {
                    number_N_prod(target,base);
                    number_N_diff(clone,one);
                }
                number_N_del(base);
                number_N_del(clone);
                number_N_del(one);
            }
        }
    }
    return target;
}

number_N_p number_N_sum_raw(const number_N_p target,const TYPE_NUMBER_N add)
{
    if(number_N_regular(target))
        number_N_assign(target,number_N_value(target) + add);
    return target;
}

number_N_p number_N_diff_raw(const number_N_p target,const TYPE_NUMBER_N sub)
{
    if(number_N_regular(target))
    {
        if (number_N_mayor_raw(target, sub))
            number_N_assign(target, number_N_value(target) - sub);
        else
            number_N_assign(target, sub - number_N_value(target));
    }
    return target;
}

number_N_p number_N_prod_raw(const number_N_p target,const TYPE_NUMBER_N prod)
{
    if(number_N_valid(target))
    {
        if(prod == MIN_NUMBER_N)
            number_N_assign(target,MIN_NUMBER_N);
        else if(!number_N_inf(target))
            number_N_assign(target, number_N_value(target) * prod);
    }
    return target;
}

number_N_p number_N_div_raw(const number_N_p target,const TYPE_NUMBER_N div)
{
    if(number_N_valid(target) && div != 1)
    {
        if(div == MIN_NUMBER_N)
        {
            if(number_N_zero(target))
                number_N_assign(target,NUMBER_N_INF);
            else
                number_N_assign(target,NUMBER_N_IMP);
        }
        else if(!number_N_inf(target))
        {
            number_N_assign(target, number_N_value(target) / div);
        }
    }
    return target;
}

number_N_p number_N_remainder_raw(const number_N_p target,const TYPE_NUMBER_N div)
{
    if(number_N_valid(target))
    {
        number_N_p clone = number_N_clone(target);
        number_N_div_raw(clone,div);
        number_N_prod_raw(clone,div);
        number_N_diff(target,clone);
        number_N_del(clone);
    }
    return target;
}

number_N_p number_N_pow_raw(const number_N_p target,const TYPE_NUMBER_N pow)
{
    if(number_N_regular(target))
    {
        if(pow == 0)
            number_N_assign(target,1);
        else if(pow != 1)
        {
            if(number_N_equal_raw(target,2))
                number_N_assign(target, number_N_value(target) << (pow - 1));
            else
            {
                TYPE_NUMBER_N base = number_N_value(target);
                TYPE_NUMBER_N clone = pow;
                while(clone > 1)
                {
                    number_N_prod_raw(target,base);
                    clone--;
                }
            }
        }
    }
    return target;
}