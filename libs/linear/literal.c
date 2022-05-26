//
// Created by Ico on 21/4/2022.
//
#include "literal.h"

char isop(char op)
{
    switch(op)
    {
        case SIGN_PLUS:
        case SIGN_MINUS:
            return 1;
        default:
            return 0;
    }
}

char ispar(char par)
{
    switch(par)
    {
        case SIGN_PARENTHESIS_OPEN:
        case SIGN_PARENTHESIS_CLOSE:
            return 1;
        default:
            return 0;
    }
}

void parseEntities(array_p* variables, array_p* matrices, char* string, unsigned short length)
{
    /*{
        char tmp[MAX_VAR_NAME_LENGTH];
        strncpy_s(tmp,MAX_VAR_NAME_LENGTH,string,length);
        printf("\nParsing entities \"%s\".\n",tmp);
    }*/
    TYPE_ARRAY_SIZE s = 0,i,count = 0;
    entity_type type = VARIABLE;
    foreach(length,i)
    {
        switch (string[i])
        {
            case SIGN_MATRIX_CLOSE:
            {
                matrixp m = newml(string + s,i - s + 1);
                if(m)
                    seta(*matrices, (*matrices)->used++, m);
                else
                    fprintf(stderr,"Error occurred while loading matrix.\n");
                type = NONE;
                break;
            }
            case SIGN_MATRIX_OPEN:
            {
                if(i != 0)
                    parseExpression(variables, string + s, i - s - 1);
                type = MATRIX;
                s = i;
                count = 0;
                break;
            }
            default:
            {
                if(type == NONE)
                {
                    type = VARIABLE;
                    count = 0;
                    s = i;
                }
                count++;
            }
        }
    }
    if(type == VARIABLE && i - s > 0)
        parseExpression(variables, string + s, i - s - 1);
}

unsigned char parseExpression(array_p* expression, char* string, unsigned short length)
{
    /*{
        char tmp[MAX_VAR_NAME_LENGTH];
        strncpy_s(tmp,MAX_VAR_NAME_LENGTH,string,length);
        printf("\nParsing variables \"%s\".\n",tmp);
    }*/
    TYPE_ARRAY_SIZE s = 0,i,count = 0;
    foreach(length,i)
    {
        if(isop(string[i]) || (isalnum(string[i]) && count == 0))
            count++;
    }
    *expression = array_new(sizeof(variable) * count);
    if(!*expression)
        return 0;
    count = 0;
    foreach(length,i)
    {
        if(isop(string[i]) || (isalnum(string[i]) && count == 0))
        {
            sumvl(*expression, string + s, i - s);
            /*while(i < string->used && !isalnum(atos(string)[i]))
                i++;*/
            s = i;
            count++;
        }
        if(i == length - 1)
        {
            sumvl(*expression, string + s, i - s + 1);
        }
    }
    return 1;
}

unsigned char loadEntity(variablep* entity,char* string,unsigned char length)
{
    short i;
    unsigned char next = 1,valid = 0;
    TYPE_VAR_COEFF coeff = 1;
    for(i = 0; i < length && next; i++)
    {
        switch (string[i])
        {
            case SIGN_PLUS:
            {
                coeff = 1;
                //printf("Found positive sign %c.\n",SIGN_PLUS);
                break;
            }
            case SIGN_MINUS:
            {
                coeff = -1;
                //printf("Found negative sign %c.\n",SIGN_MINUS);
                break;
            }
            default:
            {
                if(isdigit(string[i]))
                {
                    TYPE_VAR_COEFF tmp,count;
                    sscanf_s(string + i,"%i%n",&tmp,&count);
                    //printf("Found value %i.\n",tmp);
                    i += count - 1;
                    coeff *= tmp;
                    if(coeff)
                        valid = 1;
                    else
                        next = 0;
                }
                else if(isalpha(string[i]))
                {
                    valid = 1;
                    i--;
                    next = 0;
                }
            }
        }
    }
    if(valid)
    {
        *entity = newvl(coeff,string + i,length - i);
        if(!(*entity))
            return 0;
        return 1;
    }
    return 0;
}