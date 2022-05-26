//
// Created by Ico on 21/4/2022.
//
#include "array.h"

array_p array_new(TYPE_ARRAY_SIZE bytes)
{
    array_p a = (array_p)malloc(sizeof(array_t));
    if(!a)
        return NULL;
    a->a = (void*)malloc(bytes);
    if(!a->a)
    {
        free(a);
        return NULL;
    }
    a->bytes = bytes;
    a->used = 0;
    return a;
}

array_p array_new0(TYPE_ARRAY_SIZE bytes)
{
    array_p a = array_new(bytes);
    if(a)
    {
        memset(a->a,0,bytes);
    }
    else
        return NULL;
    return a;
}

array_p array_news(char* string, TYPE_ARRAY_SIZE length)
{
    if(!string)
        return NULL;
    array_p a = array_new((strnlen_s(string,length) + 1) * sizeof(char));
    if(!a)
        return NULL;
    if(length == 0)
        seta(a,0,0);
    else
        array_strncpy2(a,length,string);
    return a;
}

array_p array_resize(array_p* source, TYPE_ARRAY_SIZE bytes)
{
    if(!source)
        return NULL;
    if(!*source)
        return NULL;
    if(bytes != (*source)->bytes)
    {
        (*source)->a = realloc((*source)->a,bytes);
        if(!(*source)->a && bytes != 0)
            return NULL;
        (*source)->bytes = bytes;
        if((*source)->used > bytes)
            (*source)->used = bytes;
    }
    return *source;
}

array_p array_ensuresize(array_p* source, TYPE_ARRAY_SIZE bytes)
{
    if(!source)
        return NULL;
    if(!*source)
        return NULL;
    if(bytes > (*source)->bytes)
        array_resize(source, bytes);
    return *source;
}

array_p array_copy(array_p source)
{
    if(!source)
        return NULL;
    array_p destination = (array_p)malloc(sizeof(array_t));
    if(!destination)
        return NULL;
    destination->bytes = source->bytes;
    if(source->a)
    {
        destination->a = (char*) malloc(source->bytes);
        foreachau(source,destination->used)
            seta(destination,destination->used,geta(source,destination->used));
    }
    else
    {
        destination->a = NULL;
        destination->used = source->used;
    }
    return destination;
}

size_t array_sizeof(array_p a)
{
    if(!a)
        return 0;
    return a->bytes + sizeof(array_t);
}

unsigned char array_issim(array_p a, array_p b)
{
    if(!a)
        return !b;
    if(!b)
        return !a;
    return a->bytes == b->bytes;
}

unsigned char array_iseq(array_p a, array_p b)
{
    if(!a && !b)
        return 1;
    if(!array_issim(a, b))
        return 0;
    if(a->used != b->used)
        return 0;
    TYPE_ARRAY_SIZE i;
    foreachau(a,i)
    {
        if(geta(a, i) != geta(b, i))
            return 0;
    }
    return 1;
}

void array_del(array_p a)
{
    free(a->a);
    free(a);
}

array_p array_strcpy(array_p destination, array_p source)
{
    if(!destination)
        return NULL;
    if(!source)
    {
        memset(atos(destination),0,destination->bytes);
        destination->used = 0;
    }
    else
    {
        strcpy_s(atos(destination), destination->bytes, atos(source));
        destination->used = source->used;
    }
    return destination;
}

array_p array_strncpy(array_p destination, TYPE_ARRAY_SIZE count, array_p source)
{
    if(count == 0)
        return destination;
    if(!destination)
        return NULL;
    if(!source)
    {
        memset(atos(destination),0,count);
        destination->used = 0;
    }
    else
    {
        strncpy_s(atos(destination), destination->bytes, atos(source), count);
        destination->used = strnlen_s(atos(destination),destination->bytes);
    }
    return destination;
}

array_p array_strcpy2(array_p destination, const char* source)
{
    if(!destination)
        return NULL;
    if(!source)
    {
        memset(atos(destination),0,destination->bytes);
        destination->used = 0;
    }
    else
    {
        strcpy_s(atos(destination), destination->bytes, source);
        destination->used = strnlen_s(atos(destination),destination->bytes);
    }
    return destination;
}

array_p array_strncpy2(array_p destination, TYPE_ARRAY_SIZE count, const char* source)
{
    if(count == 0)
        return destination;
    if(!destination)
        return NULL;
    if(!source)
    {
        memset(atos(destination),0,count);
        destination->used = 0;
    }
    else
    {
        strncpy_s(atos(destination), destination->bytes, source, count);
        destination->used = strnlen_s(atos(destination),destination->bytes);
    }
    return destination;
}