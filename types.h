/**
 * @file types.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Collection of useful types
 */

#ifndef _SEEN_TYPES
#define _SEEN_TYPES

/**
 * @brief Alias for char, just to avoid confusion with 8 bit numbers and ASCII characters
 */
typedef char byte;

/**
 * @brief Used to specify type of argument passed in functions that require a type specifier
 * @details Supported specifiers: `"%c"` (char), `"%i"` (int), `"%f"` (float), `"%lf"` (double), `"%p"` (pointer)
 * @note Some functions may not support some identifiers or may support additional identifiers. In those cases refer to that function documentation
 */
typedef char *spec_t;

/**
 * @brief Alias for char *, used when an array of char is actually used as a string
 */
typedef char *string;

typedef struct {
    spec_t type;
    void *body;
    unsigned int size;
} * ArrayList;

#endif