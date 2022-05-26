#include "main.h"

int main(void)
{
    array_p string = array_new(SIZE_BUFFER + 1);
    if(!string)
        return 1;
    array_p variables = array_new(sizeof(variable) * SIZE_VARIABLES);
    if(!variables)
        return 2;
    array_p matrices = array_new(sizeof(matrix) * SIZE_MATRICES);
    if(!matrices)
        return 3;

    fgets(atos(string), (int)string->bytes,stdin);
    string->used = strnlen_s(atos(string), string->bytes) - 1;
    atos(string)[string->used] = '\0';
    puts("\nElaborating data...\n");
    parseEntities(&variables,&matrices,atos(string),string->used);

    if(matrices->used > 0)
    {
        TYPE_ARRAY_SIZE i;
        foreach(matrices->used - 1,i)
            summ(geta(matrices,0),geta(matrices,i + 1));
    }


    printe(variables);
    printma(matrices);
    for(; variables->used > 0; variables->used--)
    {
        delv((variablep)geta(variables, variables->used - 1));
    }
    for(; matrices->used > 0; matrices->used--)
    {
        delm((matrixp)geta(matrices, matrices->used - 1));
    }
    array_del(variables);
    array_del(matrices);
    array_del(string);
    fputc('\n',stdout);
    return 0;
}