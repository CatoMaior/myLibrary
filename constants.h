/**
 * @file constants.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Definition of symbolic constants used by the library
 */

/**
 * @brief Returned by <i>type</i>Cmp() functions when first argument is grater than the second
 */
#define GREATER 1

/**
 * @brief Returned by <i>type</i>Cmp() functions when first argument is equal to the second
 */
#define EQUAL 0

/**
 * @brief Returned by <i>type</i>Cmp() functions when first argument is smaller than the second
 */
#define SMALLER -1

/**
 * @brief Returned when pointers have unsupported size
 */
#define UNSUPPORTED_ARCHITECTURE 64

/**
 * @brief Bool value definition
 */
#define TRUE 0xFF

/**
 * @brief Bool value definition
 */
#define FALSE 0

/**
 * @brief Returned when a function ended successfully
 */
#define SUCCESS 0

/**
 * @brief Returned when an unknown specifier was provided
 */
#define UNKNOWN_SPEC 101

/**
 * @brief Returned by search algorithms when key was not found
 */
#define KEY_NOT_FOUND -1

#define NULL_POINTER_GIVEN -64