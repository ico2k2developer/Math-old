#include "literal-old.h"

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
 * Instantiates a new variable_t struct from given coefficient and name.
 * @param coeff The coefficient of the variable_t
 * @param name The array_t string containing the name of the variable_t
 * @return A pointer to the the newly created variable_t struct or {@link NULL} if the creation fails
 */
variable_p newv(TYPE_VAR_COEFF coeff, array_p name);

/**
 * Instantiates a new variable_t struct from given coefficient and name just like {@link newv} but the variable_t name is
 * given as char array_t and length count.
 * @param coeff The coefficient of the variable_t
 * @param name The char array_t containing the name of the variable_t
 * @param length The length of the char array_t
 * @return A pointer to the the newly created variable_t struct or {@link NULL} if the creation fails
 */
variable_p newvl(TYPE_VAR_COEFF coeff, char* name, TYPE_VAR_NAME_LENGTH length);

/**
 * Calculates the size in bytes of the given variable_t struct.
 * @param v A pointer to the variable_t struct to be investigated
 * @return A size_t variable_t containing the calculated size in bytes
 */
size_t sizeofv(variable_p v);

/**
 * Releases all of the resources used by the given variable_t struct.
 * @param v A pointer to the variable_t struct to be deleted
 */
void delv(variable_p v);

/**
 * Checks whether a character is the beginnning or the ending of a matrix_t.
 * @param par The character to be checked
 * @return 1 if true, 0 if false
 */
char ismatrx(char matrx);