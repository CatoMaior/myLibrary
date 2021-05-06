/**
 * @file arrays.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Common tasks with arrays: sorting, searching, printing etc
 */

#ifndef _SEEN_ARRAYS
#define _SEEN_ARRAYS

#include "types.h"

/**
 * @brief Bubble sort for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types.
 * @param arr Pointer to the first element of the array to be sorted
 * @param size Number of elements of the array to be sorted
 * @return The return code of the function
 * @retval SUCCESS The array was correctly sorted
 * @retval UNKNOWN_SPEC Unknown id provided. The array has not been changed
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
byte chooseBubbleSort(const spec_t spec, void *arr, unsigned int size);

/**
 * @brief Quick sort for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be sorted
 * @param size Number of elements of the array to be sorted
 * @return The return code of the function
 * @retval SUCCESS The array was correctly sorted
 * @retval UNKNOWN_SPEC Unknown id provided. The array has not been changed
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
byte quickSort(const spec_t spec, void *arr, int size);

/**
 * @brief Linear search for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be inspected
 * @param key Pointer to the key
 * @param size Number of elements of the array to be inspected
 * @return The index of the first occurence of the key in the array or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
int linearSearch(const spec_t spec, const void *arr, const void *key, int size);

/**
 * @brief Print matrix of specified size with specified formatting
 * @param spec Type and format specifier used to print a cell. The printf() identifier formatting convention is supported. See ::spec_t for details. Additional supported specifiers: `"%hi"` (numerical output for char)
 * @note The format specifier must end with the letter of the type specifier. For example, `"%5.3lf"` is supported, `"%5.3lf\n"` or `"%5.3lfTest"` is not supported and nothing is printed
 * @param matrix Pointer to the first element of the matrix
 * @param nRows Number of rows of the matrix
 * @param nColumns Number of rows of the matrix
 * @return The return code of the function
 * @retval SUCCESS The matrix was correctly printed
 * @retval UNKNOWN_SPEC Give type specifier was not recognised
 * @retval NULL_POINTER_GIVEN At least one among given pointer was NULL
 */
byte printMatrix(const spec_t spec, const void *matrix, const unsigned int nRows, const unsigned int nColumns);

/**
 * @brief Bubble sort for arrays of chars
 * @details Equivalent to `chooseBubbleSort("%c", arr, size)`. Refer to chooseBubbleSort()
 */
byte charBubbleSort(char *arr, unsigned int size);

/**
 * @brief Bubble sort for arrays of ints
 * @details Equivalent to `chooseBubbleSort("%i", arr, size)`. Refer to chooseBubbleSort()
 */
byte intBubbleSort(int *arr, unsigned int size);

/**
 * @brief Bubble sort for arrays of floats
 * @details Equivalent to `chooseBubbleSort("%f", arr, size)`. Refer to chooseBubbleSort()
 */
byte floatBubbleSort(float *arr, unsigned int size);

/**
 * @brief Bubble sort for arrays of doubles
 * @details Equivalent to `chooseBubbleSort("%lf", arr, size)`. Refer to chooseBubbleSort()
 */
byte doubleBubbleSort(double *arr, unsigned int size);

/**
 * @brief Bubble sort for arrays of pointers
 * @details Equivalent to `chooseBubbleSort("%p", arr, size)`. Refer to chooseBubbleSort()
 */
byte ptrBubbleSort(int **arr, unsigned int size);

#endif