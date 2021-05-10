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
 */
void chooseBubbleSort(const spec_t spec, void *arr, unsigned int size);

/**
 * @brief Quick sort for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be sorted
 * @param size Number of elements of the array to be sorted
 */
void chooseQuickSort(const spec_t spec, void *arr, int size);

/**
 * @brief Linear search for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be inspected
 * @param key Pointer to the key
 * @param size Number of elements of the array to be inspected
 * @return The index of the first occurence of the key in the array or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int linearSearch(const spec_t spec, const void *arr, const void *key, int size);

/**
 * @brief Print matrix of specified size with specified formatting
 * @param spec Type and format specifier used to print a cell. The printf() identifier formatting convention is supported. See ::spec_t for details. Additional supported specifiers: `"%hi"` (numerical output for char)
 * @note The format specifier must end with the letter of the type specifier. For example, `"%5.3lf"` is supported, `"%5.3lf\n"` or `"%5.3lfTest"` is not supported and nothing is printed
 * @param matrix Pointer to the first element of the matrix
 * @param nRows Number of rows of the matrix
 * @param nColumns Number of rows of the matrix
 */
void printMatrix(const spec_t spec, const void *matrix, const unsigned int nRows, const unsigned int nColumns);

/**
 * @brief Bubblesort for arrays of chars
 * @details Equivalent to `chooseBubbleSort("%c", arr, size)`. Refer to chooseBubbleSort()
 */
void charBubbleSort(char *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of ints
 * @details Equivalent to `chooseBubbleSort("%i", arr, size)`. Refer to chooseBubbleSort()
 */
void intBubbleSort(int *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of floats
 * @details Equivalent to `chooseBubbleSort("%f", arr, size)`. Refer to chooseBubbleSort()
 */
void floatBubbleSort(float *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of doubles
 * @details Equivalent to `chooseBubbleSort("%lf", arr, size)`. Refer to chooseBubbleSort()
 */
void doubleBubbleSort(double *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of pointers
 * @details Equivalent to `chooseBubbleSort("%p", arr, size)`. Refer to chooseBubbleSort()
 */
void ptrBubbleSort(void **arr, unsigned int size);

/**
 * @brief Quicksort for arrays of chars
 * @details Equivalent to `chooseQuickSort("%c", arr, size)`. Refer to chooseQuickSort()
 */
void charQuickSort(char *arr, unsigned int size);

/**
 * @brief Quicksort for arrays of ints
 * @details Equivalent to `chooseQuickSort("%i", arr, size)`. Refer to chooseQuickSort()
 */
void intQuickSort(int *arr, unsigned int size);

/**
 * @brief Quicksort for arrays of floats
 * @details Equivalent to `chooseQuickSort("%f", arr, size)`. Refer to chooseQuickSort()
 */
void floatQuickSort(float *arr, unsigned int size);

/**
 * @brief Quicksort for arrays of doubles
 * @details Equivalent to `chooseQuickSort("%lf", arr, size)`. Refer to chooseQuickSort()
 */
void doubleQuickSort(double *arr, unsigned int size);

/**
 * @brief Quicksort for arrays of pointers
 * @details Equivalent to `chooseQuickSort("%p", arr, size)`. Refer to chooseQuickSort()
 */
void ptrQuickSort(void **arr, unsigned int size);

#endif