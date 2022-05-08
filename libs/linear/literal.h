//
// Created by Ico on 21/4/2022.
//

#ifndef MATH2_LITERAL_H
#define MATH2_LITERAL_H

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
    arrayp name;
    TYPE_VAR_COEFF coeff;
}variable;

typedef variable* variablep;

typedef struct
{
    arrayp** data;
    TYPE_MATRIX_DIM_COUNT rows,cols;
}matrix;

typedef matrix* matrixp;

#define getm(matrix,row,col) (((matrix)->data)[row][col])

typedef enum
{
    VARIABLE,
    MATRIX,
    NONE,
}entity_type;

char            isop(char op);
char            ispar(char par);
variablep       newv(TYPE_VAR_COEFF coeff,arrayp name);
variablep       newvl(TYPE_VAR_COEFF coeff, char* name, TYPE_VAR_NAME_LENGTH length);
size_t          sizeofv(variablep v);
variablep       copyv(variablep source);
void            delv(variablep v);
unsigned char   issimv(variablep v1, variablep v2);
unsigned char   iseqv(variablep v1, variablep v2);
int_least64_t   findv(arrayp entities, variablep v);
void            printe(arrayp variables);


char            ismatrx(char matrx);
matrixp         newme(TYPE_MATRIX_DIM_COUNT rows, TYPE_MATRIX_DIM_COUNT cols);
matrixp         newm(arrayp string);
matrixp         newml(char* name,TYPE_ARRAY_SIZE length);
size_t          sizeofm(matrixp m);
matrixp         copym(matrixp source);
void            delm(matrixp m);
unsigned char   issimm(matrixp m1,matrixp m2);
unsigned char   iseqm(matrixp m1,matrixp m2);
int_least64_t   findm(arrayp entities,matrixp m);
void            printm(matrixp m);
void            printma(arrayp matrices);

void            sumvv(arrayp expression, variablep var);
void            sumva(arrayp expression, arrayp string);
void            sumvl(arrayp expression, char* string, TYPE_VAR_NAME_LENGTH length);
void            subvv(arrayp expression,variablep var);
void            subva(arrayp expression,arrayp string);
void            subvl(arrayp expression,char* string,TYPE_VAR_NAME_LENGTH length);

unsigned char   summ(matrixp target, matrixp offset);

void            parseEntities(arrayp* variables,arrayp* matrices, char* string, unsigned short length);
unsigned char   parseExpression(arrayp* expression, char* string, unsigned short length);
unsigned char   loadEntity(variablep* entity,char* string,unsigned char length);


#endif //MATH2_LITERAL_H
