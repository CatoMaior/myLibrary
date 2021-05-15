/**
 * @file types.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Collection of useful types
 */

#ifndef __SEEN_TYPES
#define __SEEN_TYPES

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

/**
 * @brief ::arrayList type
 * @note All the parameters in this structure must be intended as read-only. Manually modifying them can cause unknown and unwanted behavior
 */
typedef struct {
    /**
     * @brief The type of the elements contained by the ::arrayList. Refer to ::spec_t
     */
    spec_t type;

    /**
     * @brief Void pointer to the first element of the ::arrayList
     */
    void *body;

    /**
     * @brief The number of elements contained by the ::arrayList
     */
    unsigned int size;
} arrayList;

/**
 * @brief ::ArrayList type
 * @details Pointer to ::arrayList
 */
typedef arrayList *ArrayList;

#endif