//
// Created by Ico on 26/5/2022.
//

#ifndef MATH2_BOOL8_H
#define MATH2_BOOL8_H

#include <stdint.h>

#define TRUE    1
#define FALSE   0

typedef uint_least8_t bool8_t;
typedef bool8_t* bool8_p;

uint8_t bool8_get(const bool8_t bool,const uint8_t index);
bool8_p bool8_check(const bool8_p bool,const uint8_t index);
bool8_p bool8_uncheck(const bool8_p bool,const uint8_t index);
bool8_p bool8_set(const bool8_p bool,const uint8_t index,const uint8_t bit);

#endif //MATH2_BOOL8_H
