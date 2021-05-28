/**
 * @file arrays.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Common tasks with arrays: sorting, searching, printing etc
 */

#ifndef __SEEN_ARRAYS
#define __SEEN_ARRAYS

#include "types.h"

/**
 * @brief Bubble sort for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be sorted
 * @param size Number of elements of the array to be sorted
 */
void chooseBubbleSortArr(const spec_t spec, void *arr, unsigned int size);

/**
 * @brief Quick sort for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be sorted
 * @param size Number of elements of the array to be sorted
 */
void chooseQuickSortArr(const spec_t spec, void *arr, int size);

/**
 * @brief Linear search for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be inspected
 * @param size Number of elements of the array to be inspected
 * @param ... The key to be searched
 * @note Even though passing more than one key does not throw a compiler nor runtime error, only searching one key is supported. Other items are ignored. If you don't specify any key to be searched, still no errors occur but the return value of the function can be unpredictable
 * @return The index of the first occurence of the key in the array or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int chooseLinearSearch(const spec_t spec, void *arr, int size, ...);

/**
 * @brief Print a matrix of specified size with specified formatting
 * @param spec Type and format specifier used to print a cell. The printf() identifier and formatting convention is supported. See ::spec_t for details. Additional supported specifiers: `"%hi"` (numerical output for char)
 * @note The format specifier must end with the letter of the type specifier. For example, `"%5.3lf"` is supported, `"%5.3lf\n"` or `"%5.3lfTest"` is not supported and nothing is printed
 * @param matrix Pointer to the first element of the matrix
 * @param nRows Number of rows of the matrix
 * @param nColumns Number of rows of the matrix
 */
void printMatrix(const spec_t spec, const void *matrix, const unsigned int nRows, const unsigned int nColumns);

/**
 * @brief Bubblesort for arrays of chars
 * @details Equivalent to `chooseBubbleSortArr("%c", arr, size)`. Refer to chooseBubbleSortArr()
 */
void charBubbleSort(char *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of ints
 * @details Equivalent to `chooseBubbleSortArr("%i", arr, size)`. Refer to chooseBubbleSortArr()
 */
void intBubbleSort(int *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of floats
 * @details Equivalent to `chooseBubbleSortArr("%f", arr, size)`. Refer to chooseBubbleSortArr()
 */
void floatBubbleSort(float *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of doubles
 * @details Equivalent to `chooseBubbleSortArr("%lf", arr, size)`. Refer to chooseBubbleSortArr()
 */
void doubleBubbleSort(double *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of pointers
 * @details Equivalent to `chooseBubbleSortArr("%p", arr, size)`. Refer to chooseBubbleSortArr()
 */
void ptrBubbleSort(void **arr, unsigned int size);

/**
 * @brief Quicksort for arrays of chars
 * @details Equivalent to `chooseQuickSortArr("%c", arr, size)`. Refer to chooseQuickSortArr()
 */
void charQuickSort(char *arr, int size);

/**
 * @brief Quicksort for arrays of ints
 * @details Equivalent to `chooseQuickSortArr("%i", arr, size)`. Refer to chooseQuickSortArr()
 */
void intQuickSort(int *arr, int size);

/**
 * @brief Quicksort for arrays of floats
 * @details Equivalent to `chooseQuickSortArr("%f", arr, size)`. Refer to chooseQuickSortArr()
 */
void floatQuickSort(float *arr, int size);

/**
 * @brief Quicksort for arrays of doubles
 * @details Equivalent to `chooseQuickSortArr("%lf", arr, size)`. Refer to chooseQuickSortArr()
 */
void doubleQuickSort(double *arr, int size);

/**
 * @brief Quicksort for arrays of pointers
 * @details Equivalent to `chooseQuickSortArr("%p", arr, size)`. Refer to chooseQuickSortArr()
 */
void ptrQuickSort(void **arr, int size);

#endif