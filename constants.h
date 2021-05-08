/**
 * @file constants.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Definition of symbolic constants used by the library
 */

#ifndef _SEEN_CONSTANTS
#define _SEEN_CONSTANTS

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
 * @brief Returned when a function of the library ended successfully
 */
#define SUCCESS 0

/**
 * @brief Returned when an unknown specifier was provided
 */
#define UNKNOWN_SPEC 101

/**
 * @brief Returned by search functions of the library when key was not found
 */
#define KEY_NOT_FOUND -1

/**
 * @brief Returned when a null pointer was given
 */
#define NULL_POINTER_GIVEN -64

/**
 * @brief Returned when a function of the library could not allocate memory
 */
#define ALLOC_ERROR 37

/**
 * @brief Returned when given dynArrays have different types
 */
#define DIFFERENT_TYPES -13

/**
 * @brief Returned when a ::ArrayList was accessed out of its bounds
 */
#define OUT_OF_BOUNDS -2

#endif