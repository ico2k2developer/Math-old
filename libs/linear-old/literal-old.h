//
// Created by Ico on 21/4/2022.
//

#ifndef MATH2_LITERAL_OLD_H
#define MATH2_LITERAL_OLD_H

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <array.h>

#define MAX_VAR_NAME_LENGTH         255
#define TYPE_VAR_NAME_LENGTH        uint_least8_t

#define TYPE_VAR_COEFF              int_least32_t

#define TYPE_MATRIX_DIM_COUNT       uint_least8_t

#define SIGN_PLUS       '+'
#define SIGN_MINUS      '-'
#define SIGN_PARENTHESIS_OPEN   '('
#define SIGN_PARENTHESIS_CLOSE  ')'

#define SIGN_MATRIX_OPEN        '['
#define SIGN_MATRIX_CLOSE       ']'
#define SIGN_MATRIX_COMMA       ','
#define SIGN_MATRIX_NL          ';'

typedef struct
{
    array_p name;
    TYPE_VAR_COEFF coeff;
}variable_t;

typedef variable_t* variable_p;

typedef struct
{
    array_p** data;
    TYPE_MATRIX_DIM_COUNT rows,cols;
}matrix_t;

typedef matrix_t* matrixp;

#define getm(matrix,row,col) (((matrix_t)->data)[row][col])

typedef enum
{
    VARIABLE,
    MATRIX,
    NONE,
}entity_type;

char            isop(char op);
char            ispar(char par);
variable_p       newv(TYPE_VAR_COEFF coeff, array_p name);
variable_p       newvl(TYPE_VAR_COEFF coeff, char* name, TYPE_VAR_NAME_LENGTH length);
size_t          sizeofv(variable_p v);
variable_p       copyv(variable_p source);
void            delv(variable_p v);
unsigned char   issimv(variable_p v1, variable_p v2);
unsigned char   iseqv(variable_p v1, variable_p v2);
int_least64_t   findv(array_p entities, variable_p v);
void            printe(array_p variables);


char            ismatrx(char matrx);
matrixp         newme(TYPE_MATRIX_DIM_COUNT rows, TYPE_MATRIX_DIM_COUNT cols);
matrixp         newm(array_p string);
matrixp         newml(char* name,TYPE_ARRAY_SIZE length);
size_t          sizeofm(matrixp m);
matrixp         copym(matrixp source);
void            delm(matrixp m);
unsigned char   issimm(matrixp m1,matrixp m2);
unsigned char   iseqm(matrixp m1,matrixp m2);
int_least64_t   findm(array_p entities, matrixp m);
void            printm(matrixp m);
void            printma(array_p matrices);

void            sumvv(array_p expression, variable_p var);
void            sumva(array_p expression, array_p string);
void            sumvl(array_p expression, char* string, TYPE_VAR_NAME_LENGTH length);
void            subvv(array_p expression, variable_p var);
void            subva(array_p expression, array_p string);
void            subvl(array_p expression, char* string, TYPE_VAR_NAME_LENGTH length);

unsigned char   summ(matrixp target, matrixp offset);

void            parseEntities(array_p* variables, array_p* matrices, char* string, unsigned short length);
unsigned char   parseExpression(array_p* expression, char* string, unsigned short length);
unsigned char   loadEntity(variable_p* entity, char* string, unsigned char length);


#endif //MATH2_LITERAL_OLD_H
