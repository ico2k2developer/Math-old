#include "literal.h"

/**
 * Checks whether a character is a known operator.
 * @param op The character to be checked
 * @return 1 if true, 0 if false
 */
char isop(char op);

/**
 * Checks whether a character is a known parenthesis.
 * @param par The character to be checked
 * @return 1 if true, 0 if false
 */
char ispar(char par);

/**
 * Instantiates a new variable struct from given coefficient and name.
 * @param coeff The coefficient of the variable
 * @param name The array string containing the name of the variable
 * @return A pointer to the the newly created variable struct or {@link NULL} if the creation fails
 */
variablep newv(TYPE_VAR_COEFF coeff,arrayp name);

/**
 * Instantiates a new variable struct from given coefficient and name just like {@link newv} but the variable name is
 * given as char array and length count.
 * @param coeff The coefficient of the variable
 * @param name The char array containing the name of the variable
 * @param length The length of the char array
 * @return A pointer to the the newly created variable struct or {@link NULL} if the creation fails
 */
variablep newvl(TYPE_VAR_COEFF coeff, char* name, TYPE_VAR_NAME_LENGTH length);

/**
 * Calculates the size in bytes of the given variable struct.
 * @param v A pointer to the variable struct to be investigated
 * @return A size_t variable containing the calculated size in bytes
 */
size_t sizeofv(variablep v);

/**
 * Releases all of the resources used by the given variable struct.
 * @param v A pointer to the variable struct to be deleted
 */
void delv(variablep v);

/**
 * Checks whether a character is the beginnning or the ending of a matrix.
 * @param par The character to be checked
 * @return 1 if true, 0 if false
 */
char ismatrx(char matrx);