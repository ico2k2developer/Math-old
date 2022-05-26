#include "array.h"

/**
 * Instantiates a new array_t struct of defined size.
 * @param bytes Size in bytes of the array_t
 * @return A pointer to the newly instantiated array_t struct or NULL if allocation fails
 */
array_p array_new(TYPE_ARRAY_SIZE bytes);

/**
 * Instantiates a new array_t struct of defined size and writes 0 in it.
 * @param bytes Size in bytes of the array_t
 * @return A pointer to the newly instantiated array_t struct or NULL if allocation fails
 */
array_p array_new0(TYPE_ARRAY_SIZE bytes);

/**
 * Instantiates a new array_t struct from the data contained in the given string but if the given length value is smaller
 * than string length, a substring of given string will be used, otherwise if the given value is greater than string
 * length, an array_t capable of containing a string of that length will be instantiated.
 * @param string The string to be represented into the newly created array_t
 * @param length The length value which influences how the array_t is created
 * @return A pointer to the newly instantiated array_t struct or NULL if allocation fails
 */
array_p array_news(char* string, TYPE_ARRAY_SIZE length);

/**
 * Creates a new array_t of different size and copies as many elements as possible.
 * @param source Array containing the elements to be copied
 * @param bytes Size in bytes of the new array_t
 * @return A pointer to the newly instantiated array_t struct or source array_t if the process fails
 */
array_p resize(array_p source, TYPE_ARRAY_SIZE bytes);

/**
 * Calculates the total size of the array_t and its internal components
 * @param a Array to be investigated
 * @return A size_t value representing the amount of bytes
 */
size_t array_sizeof(array_p a);