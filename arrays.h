/**
 * @file arrays.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Common tasks with arrays: sorting, searching, printing etc
 */

#ifndef SEEN_ARRAYS
#define SEEN_ARRAYS

#include "types.h"

// Do the pointer version for ArrayLists, LinkedLists, Stacks, Queues

/**
 * @brief Bubble sort for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be sorted
 * @param size Number of elements of the array to be sorted
 * @param ... The comparison function needed to compare items inside given lists. This parameter is necessary only for pointer ::ArrayList type and is ignored otherwise. Must be a function that takes two pointers as argument and returns a positive int if the item pointed by the first argument is greater than the item pointed by the second argument, a negative int if the item pointed by the first argument is is smaller than the item pointed by second, a zero int if the item pointed by first and second arguments are equal
 */
void chooseBubbleSortArr(const spec_t spec, void *arr, unsigned int size, ...);

/**
 * @brief Quick sort for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be sorted
 * @param size Number of elements of the array to be sorted
 * @param ... The comparison function needed to compare items inside given lists. This parameter is necessary only for pointer ::ArrayList type and is ignored otherwise. Must be a function that takes two pointers as argument and returns a positive int if the item pointed by the first argument is greater than the item pointed by the second argument, a negative int if the item pointed by the first argument is is smaller than the item pointed by second, a zero int if the item pointed by first and second arguments are equal
 */
void chooseQuickSortArr(const spec_t spec, void *arr, int size, ...);

/**
 * @brief Linear search for arrays
 * @param spec Type specifier of the array to be sorted. Refer to ::spec_t for supported types
 * @param arr Pointer to the first element of the array to be inspected
 * @param size Number of elements of the array to be inspected
 * @param ... The key to be searched. If searaching in a pointer array, after the item you want so search, you must provide the comparison function needed to compare the item you want to search and the items in the array. Must be a function that takes two pointers as argument and returns a zero int only if the item pointed by first and second arguments are equal
 * @note Even though passing more than one key does not throw a compiler nor runtime error, only searching one key is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable. If searching in a pointer array and the comparing function is not passed a compiler or runtime error is not given either, but the return value of the function can be unpredictable
 * @return The index of the first occurence of the key in the array or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int chooseLinearSearchArr(const spec_t spec, const void *arr, int size, ...);

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
void charBubbleSortArr(char *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of ints
 * @details Equivalent to `chooseBubbleSortArr("%i", arr, size)`. Refer to chooseBubbleSortArr()
 */
void intBubbleSortArr(int *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of floats
 * @details Equivalent to `chooseBubbleSortArr("%f", arr, size)`. Refer to chooseBubbleSortArr()
 */
void floatBubbleSortArr(float *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of doubles
 * @details Equivalent to `chooseBubbleSortArr("%lf", arr, size)`. Refer to chooseBubbleSortArr()
 */
void doubleBubbleSortArr(double *arr, unsigned int size);

/**
 * @brief Bubblesort for arrays of pointers
 * @param arr The array to be sorted
 * @param size The number of items contained in arr
 * @param cmpFunc The comparison function needed to compare items inside given lists. Must be a function that takes two pointers as argument and returns a positive int if the item pointed by the first argument is greater than the item pointed by the second argument, a negative int if the item pointed by the first argument is is smaller than the item pointed by second, a zero int if the item pointed by first and second arguments are equal
 */
void ptrBubbleSortArr(void **arr, unsigned int size, int (*cmpFunc)(const void *a, const void *b));

/**
 * @brief Quicksort for arrays of chars
 * @details Equivalent to `chooseQuickSortArr("%c", arr, size)`. Refer to chooseQuickSortArr()
 */
void charQuickSortArr(char *arr, int size);

/**
 * @brief Quicksort for arrays of ints
 * @details Equivalent to `chooseQuickSortArr("%i", arr, size)`. Refer to chooseQuickSortArr()
 */
void intQuickSortArr(int *arr, int size);

/**
 * @brief Quicksort for arrays of floats
 * @details Equivalent to `chooseQuickSortArr("%f", arr, size)`. Refer to chooseQuickSortArr()
 */
void floatQuickSortArr(float *arr, int size);

/**
 * @brief Quicksort for arrays of doubles
 * @details Equivalent to `chooseQuickSortArr("%lf", arr, size)`. Refer to chooseQuickSortArr()
 */
void doubleQuickSortArr(double *arr, int size);

/**
 * @brief Quicksort for arrays of pointers
 * @param arr The array to be sorted
 * @param size The number of items contained in arr
 * @param cmpFunc The comparison function to be used. Must be a function that returns a positive int if first argument is greater than the second, a negative byte if first argument is smaller than the second, a zero byte if first and second arguments are equal
 */
void ptrQuickSortArr(void *arr, int size, int (*cmpFunc)(const void *a, const void *b));

/**
 * @brief Linear search for arrays of chars
 * @details Equivalent to `chooseLinearSearchArr("%c", arr, size, key)`. Refer to chooseQuickSortArr()
 */
int charLinearSearchArr(const char *arr, int size, char key);

/**
 * @brief Linear search for arrays of integers
 * @details Equivalent to `chooseLinearSearchArr("%i", arr, size, key)`. Refer to chooseLinearSearchArr()
 */
int intLinearSearchArr(const char *arr, int size, int key);

/**
 * @brief Linear search for arrays of floats
 * @details Equivalent to `chooseLinearSearchArr("%f", arr, size, key)`. Refer to chooseLinearSearchArr()
 */
int floatLinearSearchArr(const char *arr, int size, float key);

/**
 * @brief Linear search for arrays of doubles
 * @details Equivalent to `chooseLinearSearchArr("%lf", arr, size, key)`. Refer to chooseLinearSearchArr()
 */
int doubleLinearSearchArr(const char *arr, int size, double key);

/**
 * @brief Linear search for arrays of pointers
 * @param arr Pointer to the first element of the array to be inspected
 * @param size Number of elements of the array to be inspected
 * @param key The key to be searched
 * @param cmpFunc The comparison function to be used. Must be a function that returns a positive int if first argument is greater than the second, a negative byte if first argument is smaller than the second, a zero byte if first and second arguments are equal
 * @return The index of the first occurence of the key in the array or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int ptrLinearSearchArr(const void *arr, int size, void *key, int (*cmpFunc)(const void *a, const void *b));

#endif