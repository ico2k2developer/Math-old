//
// Created by ico2k2 on 5/5/2022.
//

#include "literal.h"

variablep newv(TYPE_VAR_COEFF coeff, array_p name)
{
    variablep v = (variablep)malloc(sizeof(variable));
    if(!v)
        return NULL;
    v->name = array_new(name->bytes);
    if(!v->name)
    {
        free(v);
        return NULL;
    }
    array_strcpy(v->name, name);
    v->coeff = coeff;
    return v;
}

variablep newvl(TYPE_VAR_COEFF coeff, char* name,TYPE_VAR_NAME_LENGTH length)
{
    array_p s = array_news(name, length);
    if(!s)
        return NULL;
    variablep result = newv(coeff,s);
    array_del(s);
    return result;
}

variablep copyv(variablep source)
{
    return newv(source->coeff,source->name);
}

size_t sizeofv(variablep v)
{
    return array_sizeof(v->name) + sizeof(variable);
}

void delv(variablep v)
{
    array_del(v->name);
    free(v);
}

unsigned char issimv(variablep v1, variablep v2)
{
    return strcmp(atos(v1->name),atos(v2->name)) == 0;
}

unsigned char iseqv(variablep v1, variablep v2)
{
    return issimv(v1, v2) && v1->coeff == v2->coeff;
}

int_least64_t findv(array_p entities, variablep v)
{
    int_least64_t i;
    foreachau(entities,i)
    {
        if(issimv(geta(entities, i), v))
            return i;
    }
    return -1;
}

void printe(array_p variables)
{
    TYPE_ARRAY_SIZE i,i2;
    size_t size1,size2;
    variablep tmp;
    foreachau(variables, i)
    {
        foreachau(variables, i2)
        {
            size1 = strnlen_s(atos(((variablep)geta(variables, i))->name), MAX_VAR_NAME_LENGTH);
            size2 = strnlen_s(atos(((variablep)geta(variables, i2))->name), MAX_VAR_NAME_LENGTH);
            if((size1 > 0 && size2 == 0) ||
               (size1 > 0 && size2 > 0 && strcmp(atos(((variablep)geta(variables, i2))->name),
                                                 atos(((variablep)geta(variables, i))->name)) > 0))
            {
                tmp = geta(variables, i);
                seta(variables, i, geta(variables, i2));
                seta(variables, i2, tmp);
            }
        }
    }
    foreachau(variables, i)
    {
        tmp = geta(variables, i);
        if(tmp->coeff > 0)
        {
            if(i != 0)
                putc(SIGN_PLUS,stdout);
            if(tmp->coeff != 1 || tmp->name->used == 0)
                printf("%i",tmp->coeff);
        }
        else if(tmp->coeff < 0)
        {
            putc(SIGN_MINUS,stdout);
            if(tmp->coeff != -1)
                printf("%i",tmp->coeff * -1);
        }
        printf("%s",atos(tmp->name));
    }
}

void sumvv(array_p expression, variablep var)
{
    int_least64_t pos = findv(expression, var);
    if(pos < 0)
    {
        size_t size = (expression->used + 1) * sizeof(variable);
        if(size > expression->bytes)
            array_resize(expression, size);
        seta(expression, expression->used++, var);
    }
    else
    {
        ((variablep)geta(expression, pos))->coeff += var->coeff;
    }
}

void sumva(array_p expression, array_p string)
{
    variablep new;
    if(loadEntity(&new,atos(string),string->used) == 1)
        sumvv(expression,new);
}

void sumvl(array_p expression, char* string, TYPE_VAR_NAME_LENGTH length)
{
    array_p a = array_news(string, length);
    sumva(expression,a);
    array_del(a);
}

void subvv(array_p expression, variablep var)
{
    variable tmp;
    tmp.coeff = -var->coeff;
    tmp.name = var->name;
    sumvv(expression,&tmp);
}

void subva(array_p expression, array_p string)
{
    variablep new;
    if(loadEntity(&new,atos(string),string->used) == 1)
        subvv(expression,new);
}

void subvl(array_p expression, char* string, TYPE_VAR_NAME_LENGTH length)
{
    array_p a = array_news(string, length);
    subva(expression,a);
    array_del(a);
}