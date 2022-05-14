//
// Created by Ico on 21/4/2022.
//

#ifndef MATH2_ARRAY_H
#define MATH2_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define geta(array,index) (((array)->a)[index])
#define seta(array,index,value) geta(array,index) = (value)
#define atos(array) ((char*)array->a)
#define foreach(count,i) for(i = 0; i < count; i++)
#define foreachR(count,i) for(i = count; i > 0; i--)
#define foreachv(vector,i) foreach(vector,sizeof(vector) / sizeof(vector[0]),i)
#define foreacha(array,elementsize,i) foreach(array->bytes / elementsize,i)
#define foreachau(array,i) foreach(array->used,i)

#define MAX_ARRAY_LENGTH    UINT_LEAST32_MAX

#define TYPE_ARRAY_SIZE   uint_least32_t

typedef struct
{
    char* a;
    TYPE_ARRAY_SIZE bytes,used;
}array;

typedef array* arrayp;

arrayp          newa(TYPE_ARRAY_SIZE bytes);
arrayp          newa0(TYPE_ARRAY_SIZE bytes);
arrayp          newas(char* string,TYPE_ARRAY_SIZE length);
arrayp          resize(arrayp* source,TYPE_ARRAY_SIZE bytes);
arrayp          ensuresize(arrayp* source,TYPE_ARRAY_SIZE bytes);
arrayp          copya(arrayp source);
size_t          sizeofa(arrayp a);
unsigned char   issima(arrayp a,arrayp b);
unsigned char   iseqa(arrayp a,arrayp b);
void            dela(arrayp a);

arrayp          stracpy(arrayp destination,arrayp source);
arrayp          strancpy(arrayp destination,TYPE_ARRAY_SIZE count,arrayp source);
arrayp          stracpy2(arrayp destination,const char* source);
arrayp          strancpy2(arrayp destination, TYPE_ARRAY_SIZE count,const char* source);

#endif //MATH2_ARRAY_H
