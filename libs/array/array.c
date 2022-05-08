//
// Created by Ico on 21/4/2022.
//
#include "array.h"

arrayp newa(TYPE_ARRAY_SIZE bytes)
{
    arrayp a = (arrayp)malloc(sizeof(array));
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

arrayp newa0(TYPE_ARRAY_SIZE bytes)
{
    arrayp a = newa(bytes);
    if(a)
    {
        memset(a->a,0,bytes);
    }
    else
        return NULL;
    return a;
}

arrayp newas(char* string,TYPE_ARRAY_SIZE length)
{
    if(!string)
        return NULL;
    arrayp a = newa((strnlen_s(string,length) + 1) * sizeof(char));
    strancpy2(a,length,string);
    return a;
}

arrayp resize(arrayp* source,TYPE_ARRAY_SIZE bytes)
{
    if(!source)
        return NULL;
    arrayp a = *source;
    if(!a)
        return NULL;
    if(bytes != a->bytes)
    {
        arrayp new = newa(bytes);
        if(!new)
            return NULL;
        TYPE_ARRAY_SIZE i,limit;
        limit = a->used > bytes ? bytes : a->used;
        foreach(limit,i)
        {
            seta(new,i,geta(a, i));
            new->used++;
        }
        dela(a);
        *source = new;
    }
    return *source;
}

arrayp ensuresize(arrayp* source,TYPE_ARRAY_SIZE bytes)
{
    if(!source)
        return NULL;
    if(!*source)
        return NULL;
    if(bytes > (*source)->bytes)
        resize(source,bytes);
    return *source;
}

arrayp copya(arrayp source)
{
    if(!source)
        return NULL;
    arrayp destination = (arrayp)malloc(sizeof(array));
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

size_t sizeofa(arrayp a)
{
    return a->bytes + sizeof(array);
}

unsigned char issima(arrayp a,arrayp b)
{
    return a->bytes == b->bytes && a->used == b->used;
}

unsigned char iseqa(arrayp a,arrayp b)
{
    if(!issima(a,b))
        return 0;
    TYPE_ARRAY_SIZE i;
    foreachau(a,i)
    {
        if(geta(a, i) != geta(b, i))
            return 0;
    }
    return 1;
}

void dela(arrayp a)
{
    free(a->a);
    free(a);
}

arrayp stracpy(arrayp destination, arrayp source)
{
    strcpy_s(atos(destination), destination->bytes, atos(source));
    destination->used = source->used;
    return destination;
}

arrayp strancpy(arrayp destination, TYPE_ARRAY_SIZE count, arrayp source)
{
    strncpy_s(atos(destination), destination->bytes, atos(source), count);
    destination->used = strnlen_s(atos(destination),destination->bytes);
    return destination;
}

arrayp stracpy2(arrayp destination,const char* source)
{
    strcpy_s(atos(destination), destination->bytes, source);
    destination->used = strnlen_s(atos(destination),destination->bytes);
    return destination;
}

arrayp strancpy2(arrayp destination, TYPE_ARRAY_SIZE count,const char* source)
{
    strncpy_s(atos(destination), destination->bytes, source, count);
    destination->used = strnlen_s(atos(destination),destination->bytes);
    return destination;
}