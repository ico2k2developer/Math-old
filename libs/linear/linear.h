//
// Created by Ico on 26/5/2022.
//

#ifndef MATH2_LINEAR_H
#define MATH2_LINEAR_H

#include "array.h"
#include "bool8.h"

#define TYPE_VAR_COEFF  uint_fast64_t

typedef struct
{
    TYPE_VAR_COEFF coeff;
    array_p name;
}var_t;

#endif //MATH2_LINEAR_H
