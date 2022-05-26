//
// Created by ico2k2 on 5/5/2022.
//

#include "literal-old.h"

char ismatrx(char matrx)
{
    switch(matrx)
    {
        case SIGN_MATRIX_OPEN:
        case SIGN_MATRIX_CLOSE:
            return 1;
        default:
            return 0;
    }
}

matrixp newme(TYPE_MATRIX_DIM_COUNT rows, TYPE_MATRIX_DIM_COUNT cols)
{
    matrixp m = (matrixp)malloc(sizeof(matrix_t));
    if(!m)
        return NULL;
    m->rows = rows;
    m->cols = cols;
    m->data = (array_p**)malloc(sizeof(array_p*) * rows);
    if(!m->data)
    {
        free(m);
        return NULL;
    }
    TYPE_MATRIX_DIM_COUNT row;
    foreach(rows,row)
    {
        m->data[row] = (array_p*)malloc(sizeof(array_p) * cols);
        if(!m->data[row])
        {
            for(; row >= 0; --row)
            {
                free(m->data[row]);
            }
            free(m->data);
            free(m);
            return NULL;
        }
    }
    return m;
}

matrixp newm(array_p string)
{
    TYPE_ARRAY_SIZE i,start,end,s;
    TYPE_MATRIX_DIM_COUNT rows = 0,cols = 0,row,col = 0;
    unsigned char finish = 0;
    for(i = 0; i < string->used; i++)
    {
        if(atos(string)[i] == SIGN_MATRIX_OPEN)
        {
            start = i + 1;
            break;
        }
    }
    if(atos(string)[i] != SIGN_MATRIX_OPEN)
        return NULL;
    for(; i < string->used && !finish; i++)
    {
        switch(atos(string)[i])
        {
            case SIGN_MATRIX_COMMA:
            {
                if(rows == 0)
                    cols++;
                col++;
                break;
            }
            case SIGN_MATRIX_CLOSE:
            {
                end = i;
                finish = 1;
            }
            case SIGN_MATRIX_NL:
            {
                if(rows == 0)
                    cols++;
                rows++;
                col++;
                if(col != cols)
                {
                    fprintf(stderr,"Given string is not correctly representing a matrix_t:"
                                   " multiple row lengths. Using shortest row as reference.\n");
                    if(cols > col)
                        cols = col;
                }
                col = 0;
                break;
            }
        }
    }
    if(!finish || start >= end)
        return NULL;
    //printf("Creating matrix_t with rows %u and cols %u.\n",rows,cols);
    matrixp m = newme(rows,cols);
    if(!m)
        return NULL;
    row = col = 0;
    for(i = s = start; i <= end; i++)
    {
        switch (atos(string)[i])
        {
            case SIGN_MATRIX_NL:
            case SIGN_MATRIX_CLOSE:
            case SIGN_MATRIX_COMMA:
            {
                if(col < cols)
                {
                    if(parseExpression(m->data[row] + col, atos(string) + s, i - s))
                    {
                        //printf("Assigned matrix_t cell in row %u and col %u with ",row + 1,col + 1);
                        //printe(m->data[row][col]);
                        //fputc('\n',stdout);
                        col++;
                    }
                    else
                    {
                        fprintf(stderr,"Error in parsing expression at row %u and col %u \"%s\".\n",
                                row + 1,col + 1,atos(string) + s);
                        return NULL;
                    }
                }
                else
                    col++;
                if(atos(string)[i] == SIGN_MATRIX_NL)
                {
                    row++;
                    col = 0;
                }
                s = i + 1;
                break;
            }
        }
    }
    return m;
}

matrixp newml(char* name,TYPE_ARRAY_SIZE length)
{
    array_p s = array_news(name, length);
    if(!s)
        return NULL;
    matrixp result = newm(s);
    array_del(s);
    return result;
}


size_t sizeofm(matrixp m)
{
    TYPE_MATRIX_DIM_COUNT row,col;
    TYPE_ARRAY_SIZE i;
    size_t size = sizeof(matrix_t);
    foreach(m->rows,row)
    {
        foreach(m->cols,col)
        {
            size += array_sizeof(m->data[row][col]);
            foreach(m->data[row][col]->used,i)
                size += sizeofv(geta(m->data[row][col], i));
        }
    }
    return size;
}

matrixp copym(matrixp source)
{
    matrixp destination = newme(source->rows,source->cols);
    if(destination)
    {
        destination->rows = source->rows;
        destination->cols = source->cols;
        TYPE_MATRIX_DIM_COUNT row,col;
        TYPE_ARRAY_SIZE i;
        foreach(destination->rows,row)
        {
            foreach(destination->cols,col)
            {
                foreachau(getm(source,row,col),i)
                {
                    geta(getm(destination,row,col),i) = copyv(geta(getm(source,row,col),i));
                }
            }
        }
    }
    else
        return NULL;
    return destination;
}

void delm(matrixp m)
{
    for(; m->rows > 0; m->rows--)
    {
        for(; m->cols > 0; m->cols--)
        {
            for(; m->data[m->rows - 1][m->cols - 1]->used > 0; m->data[m->rows - 1][m->cols - 1]->used--)
                delv(geta(m->data[m->rows - 1][m->cols - 1], m->data[m->rows - 1][m->cols - 1]->used - 1));
            array_del(m->data[m->rows - 1][m->cols - 1]);
        }
        free(m->data[m->rows - 1]);
    }
    free(m->data);
    free(m);
}

unsigned char issimm(matrixp m1,matrixp m2)
{
    return m1->rows == m2->rows && m1->cols == m2->cols;
}

unsigned char iseqm(matrixp m1,matrixp m2)
{
    if(!issimm(m1,m2))
        return 0;
    TYPE_MATRIX_DIM_COUNT row,col;
    TYPE_ARRAY_SIZE i;
    foreach(m1->rows,row)
    {
        foreach(m1->cols,col)
        {
            if(m1->data[row][col]->used != m2->data[row][col]->used)
                return 0;
            foreachau(m1->data[row][col],i)
            {
                if(!iseqv(geta(m1->data[row][col], i), geta(m2->data[row][col], i)))
                    return 0;
            }
        }
    }
    return 1;
}

int_least64_t findm(array_p entities, matrixp m)
{
    int_least64_t i;
    foreachau(entities,i)
    {
        if(iseqm(geta(entities, i), m))
            return i;
    }
    return -1;
}

void printm(matrixp m)
{
    TYPE_MATRIX_DIM_COUNT row,col;
    fputc(SIGN_MATRIX_OPEN,stdout);
    foreach(m->rows, row)
    {
        foreach(m->cols, col)
        {
            printe(m->data[row][col]);
            fputc(SIGN_MATRIX_COMMA,stdout);
        }
        fputc('\b',stdout);
        fputc(SIGN_MATRIX_NL,stdout);
    }
    fputc('\b',stdout);
    fputc(SIGN_MATRIX_CLOSE,stdout);
}

void printma(array_p matrices)
{
    TYPE_ARRAY_SIZE i;
    foreachau(matrices,i)
        printm((matrixp)geta(matrices,i));
}

unsigned char summ(matrixp target, matrixp offset)
{
    if(issimm(target,offset))
    {
        TYPE_ARRAY_SIZE i;
        TYPE_MATRIX_DIM_COUNT row,col;
        foreach(target->rows,row)
        {
            foreach(target->cols,col)
            {
                foreach(getm(offset,row,col)->used,i)
                    sumvv(getm(target,row,col),geta(getm(offset,row,col),i));
            }
        }
        return 1;
    }
    else
    {
        fprintf(stderr,"Cannot sum a %ux%u matrix_t to a %ux%u.\n",
                target->rows,target->cols,
                offset->rows,offset->cols);
        return 0;
    }
}