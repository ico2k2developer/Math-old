//
// Created by Ico on 21/4/2022.
//
#include "array.h"

array_p array_new(const TYPE_ARRAY_SIZE bytes)
{
    array_p a = (array_p)malloc(sizeof(array_t));
    if(!a)
        return NULL;
    a->data = (void*)malloc(bytes);
    if(!a->data)
    {
        free(a);
        return NULL;
    }
    a->bytes = bytes;
    a->used = 0;
    return a;
}

array_p array_new0(const TYPE_ARRAY_SIZE bytes)
{
    array_p a = array_new(bytes);
    if(a)
    {
        memset(a->data,0,bytes);
    }
    else
        return NULL;
    return a;
}

array_p array_news(const char* string,const TYPE_ARRAY_SIZE length)
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

array_p array_resize(const array_p* source,const TYPE_ARRAY_SIZE bytes)
{
    if(!source)
        return NULL;
    if(!*source)
        return NULL;
    if(bytes != (*source)->bytes)
    {
        (*source)->data = realloc((*source)->data,bytes);
        if(!(*source)->data && bytes != 0)
            return NULL;
        (*source)->bytes = bytes;
        if((*source)->used > bytes)
            (*source)->used = bytes;
    }
    return *source;
}

array_p array_ensuresize(const array_p* source,TYPE_ARRAY_SIZE bytes)
{
    if(!source)
        return NULL;
    if(!*source)
        return NULL;
    if(bytes > (*source)->bytes)
        array_resize(source, bytes);
    return *source;
}

array_p array_copy(const array_p source)
{
    if(!source)
        return NULL;
    array_p destination = (array_p)malloc(sizeof(array_t));
    if(!destination)
        return NULL;
    destination->bytes = source->bytes;
    if(source->data)
    {
        destination->data = (char*) malloc(source->bytes);
        foreachau(source,destination->used)
            seta(destination,destination->used,geta(source,destination->used));
    }
    else
    {
        destination->data = NULL;
        destination->used = source->used;
    }
    return destination;
}

size_t array_sizeof(const array_p a)
{
    if(!a)
        return 0;
    return a->bytes + sizeof(array_t);
}

bool8_t array_issim(const array_p a,const array_p b)
{
    if(!a)
        return !b;
    if(!b)
        return !a;
    return a->bytes == b->bytes;
}

bool8_t array_iseq(const array_p a,const array_p b)
{
    if(!a && !b)
        return TRUE;
    if(!array_issim(a, b))
        return FALSE;
    if(a->used != b->used)
        return FALSE;
    TYPE_ARRAY_SIZE i;
    foreachau(a,i)
    {
        if(geta(a, i) != geta(b, i))
            return FALSE;
    }
    return TRUE;
}

void array_del(const array_p a)
{
    free(a->data);
    free(a);
}

array_p array_strcpy(const array_p destination,const array_p source)
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

array_p array_strncpy(const array_p destination,const TYPE_ARRAY_SIZE count,const array_p source)
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

array_p array_strcpy2(const array_p destination, const char* source)
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

array_p array_strncpy2(const array_p destination, const TYPE_ARRAY_SIZE count, const char* source)
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