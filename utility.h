/**
 * @file utility.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Common tasks such as comparing variables, swap bools, allocate memory
 */

#include "types.h"

/**
 * @brief Compare two values. Calls the right <i>type</i>Cmp() function
 * @note Works only on C11 or newer compilers
 * @return The return code of the function code
 * @retval GREATER First element is grater than the second
 * @retval EQUAL First element is equal to the second
 * @retval SMALLER First element is smaller than the second
 */
#define cmp(a, b) _Generic((a, b), char: charCmp, int: intCmp, float: floatCmp, double: doubleCmp, void *: ptrCmp) (&a, &b)

/**
 * @brief Compare two chars
 * @param spec Type specifier of the values to be sorted. Refer to ::spec_t for supported types.
 * @param a Pointer to the first element to be compared
 * @param b Pointer to the second element to be compared
 * @return Constant for the corresponding comparation result or the return code of the function
 * @retval GREATER First element is grater than the second
 * @retval EQUAL First element is equal to the second
 * @retval SMALLER First element is smaller than the second
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
byte valCmp(const spec_t spec, const void *a, const void *b);

/**
 * @brief Compare two chars
 * @details Equivalent to `valCmp("%c", a, b)`. Refer to valCmp()
 */
byte charCmp(const void *a, const void *b);

/**
 * @brief Compare two bytes
 * @details Equivalent to `charCmp(a, b)`. Refer to charCmp(). 
 */
byte byteCmp(const void *a, const void *b);

/**
 * @brief Compare two ints
 * @details Equivalent to `valCmp("%i", a, b)`. Refer to valCmp()
 */
byte intCmp(const void *a, const void *b);

/**
 * @brief Compare two floats
 * @details Equivalent to `valCmp("%f", a, b)`. Refer to valCmp()
 */
byte floatCmp(const void *a, const void *b);

/**
 * @brief Compare two doubles
 * @details Equivalent to `valCmp("%lf", a, b)`. Refer to valCmp()
 */
byte doubleCmp(const void *a, const void *b);

/**
 * @brief Compare two pointers
 * @details Equivalent to `valCmp("%p", a, b)`. Refer to valCmp()
 */
byte ptrCmp(const void *a, const void *b);

/**
 * @brief Choose comparison function based on given identifier
 * @param spec Specifier of the type of the data. Refer to ::spec_t 
 * @return Pointer to the right comparison function, `NULL` if identifier is not recognized or given pointer was NULL
 */
void *chooseCmp(const spec_t spec);

/**
 * @brief Set variable to `TRUE` if variable at provided address is 0
 * @param value Pointer to the value to be evaluated 
 * @return Return code of the function
 * @retval SUCCESS Function executed correctly
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
byte trueIfFalse(byte *value);

/**
 * @brief Set variable to `FALSE` if variable at provided address is not 0
 * @param value Pointer to the value to be evaluated 
 * @return Return code of the function
 * @retval SUCCESS Function executed correctly
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
byte falseIfTrue(byte *value);

/**
 * @brief Return a pointer to a space in memory of specified size
 * @details Calls `malloc(bytes)` for a maximum of 10 times until it returns a not null pointer
 * @param bytes Number of bytes to allocate
 * @return A pointer to the allocated memory or the return code of the function
 * @retval NULL Could not allocate memory
 */
void *saferMalloc(unsigned int bytes);

/**
 * @brief Reallocate a space in memory
 * @details Calls `realloc(pointer, bytes)` for a maximum of 10 times until it returns a not null pointer
 * @param pointer Pointer to the memory to be reallocated
 * @param bytes Number of bytes to allocate
 * @return A pointer to the allocated memory or the return code of the function
 * @retval NULL Could not allocate memory
 */
void *saferRealloc(void *pointer, unsigned int bytes);