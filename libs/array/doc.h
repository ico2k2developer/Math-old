#include "array.h"

/**
 * Instantiates a new array struct of defined size.
 * @param bytes Size in bytes of the array
 * @return A pointer to the newly instantiated array struct or NULL if allocation fails
 */
arrayp newa(TYPE_ARRAY_SIZE bytes);

/**
 * Instantiates a new array struct of defined size and writes 0 in it.
 * @param bytes Size in bytes of the array
 * @return A pointer to the newly instantiated array struct or NULL if allocation fails
 */
arrayp newa0(TYPE_ARRAY_SIZE bytes);

/**
 * Instantiates a new array struct from the data contained in the given string but if the given length value is smaller
 * than string length, a substring of given string will be used, otherwise if the given value is greater than string
 * length, an array capable of containing a string of that length will be instantiated.
 * @param string The string to be represented into the newly created array
 * @param length The length value which influences how the array is created
 * @return A pointer to the newly instantiated array struct or NULL if allocation fails
 */
arrayp newas(char* string,TYPE_ARRAY_SIZE length);

/**
 * Creates a new array of different size and copies as many elements as possible.
 * @param source Array containing the elements to be copied
 * @param bytes Size in bytes of the new array
 * @return A pointer to the newly instantiated array struct or source array if the process fails
 */
arrayp resize(arrayp source,TYPE_ARRAY_SIZE bytes);

/**
 * Calculates the total size of the array and its internal components
 * @param a Array to be investigated
 * @return A size_t value representing the amount of bytes
 */
size_t sizeofa(arrayp a);