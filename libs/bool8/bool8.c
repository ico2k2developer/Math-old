//
// Created by Ico on 26/5/2022.
//
#include "bool8.h"

uint8_t bool8_get(const bool8_t bool,const uint8_t index)
{
    return (bool & (1 << index)) ? TRUE : FALSE;
}

bool8_p bool8_check(const bool8_p bool,const uint8_t index)
{
    (*bool) |= (1 << index);
    return bool;
}

bool8_p bool8_uncheck(const bool8_p bool,const uint8_t index)
{
    (*bool) &= ~(1 << index);
    return bool;
}

bool8_p bool8_set(const bool8_p bool,const uint8_t index,const uint8_t bit)
{
    if(bit)
        return bool8_check(bool,index);
    else
        return bool8_uncheck(bool,index);
}