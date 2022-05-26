//
// Created by Ico on 21/4/2022.
//

#ifndef MATH2_ARRAY_H
#define MATH2_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <bool8.h>

#define geta(array,index) (((array)->data)[index])
#define seta(array,index,value) geta(array,index) = (value)
#define atos(array) ((char*)array->data)
#define foreach(count,i) for(i = 0; i < count; i++)
#define foreachR(count,i) for(i = count; i > 0; i--)
#define foreachv(vector,i) foreach(vector,sizeof(vector) / sizeof(vector[0]),i)
#define foreacha(array,elementsize,i) foreach(array->bytes / elementsize,i)
#define foreachau(array,i) foreach(array->used,i)

#define TYPE_ARRAY_SIZE   uint_least64_t

typedef struct
{
    TYPE_ARRAY_SIZE bytes,used;
    char* data;
}array_t;

typedef array_t* array_p;

array_p     array_new(TYPE_ARRAY_SIZE bytes);
array_p     array_new0(TYPE_ARRAY_SIZE bytes);
array_p     array_news(const char* string, TYPE_ARRAY_SIZE length);
array_p     array_resize(const array_p* source, TYPE_ARRAY_SIZE bytes);
array_p     array_ensuresize(const array_p* source, TYPE_ARRAY_SIZE bytes);
array_p     array_copy(array_p source);
size_t      array_sizeof(array_p a);
bool8_t     array_issim(array_p a, array_p b);
bool8_t     array_iseq(array_p a, array_p b);
void        array_del(array_p a);

array_p     array_strcpy(array_p destination, array_p source);
array_p     array_strncpy(array_p destination, TYPE_ARRAY_SIZE count, array_p source);
array_p     array_strcpy2(array_p destination, const char* source);
array_p     array_strncpy2(array_p destination, TYPE_ARRAY_SIZE count, const char* source);

#endif //MATH2_ARRAY_H
