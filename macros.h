/**
 * @file macros.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Macros for emulated overloading
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
#define cmp(a, b) _Generic((a, b),                      \
                            char: charCmp,              \
                            int: intCmp,                \
                            float: floatCmp,            \
                            double: doubleCmp,          \
                            void *: ptrCmp)(&a, &b)