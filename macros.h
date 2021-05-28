/**
 * @file macros.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Macros for emulated overloading
 * @note Many of these macros work on C11 or newer compilers only. If they are not supported by your compiler you have to use the function the macro expands to in your case. For example, if you want to bubblesort an array of floats and the macro bubbleSort() is not supported by your compiler, you have to call floatBubbleSort() or chooseBubbleSortArr()
 * @note In some development environments, for example Vscode, calls to these macros can be reported as errors even if they are correct. If you use Vscode you have to set `"C_Cpp.default.cStandard": "c17"` in your `settings.json` file in order to avoid these error reportings
 */

#ifndef SEEN_MACROS
#define SEEN_MACROS

#include "types.h"

/**
 * @brief Compare two values. Calls the right <i>type</i>Cmp() function
 * @note This macro must be called on variables. For example, `cmpVal(2, 3)` is not supported
 * @param a First value to be compared
 * @param b Second value to be compared
 * @return The return code of the function called
 * @retval GREATER First element is grater than the second
 * @retval EQUAL First element is equal to the second
 * @retval SMALLER First element is smaller than the second
 */
#define cmpVal(a, b) _Generic((a, b), char: charCmp, int: intCmp, float: floatCmp, double: doubleCmp, void *: ptrCmp)(&a, &b) 

/**
 * @brief BubbleSort for arrays
 * @return The return code of the function called
 * @param arr Pointer to the array to be sorted
 * @param size Number of elements in the array to be sorted
 */
#define bubbleSortArr(arr, size) _Generic(arr, char *: charBubbleSort, int *: intBubbleSort, float *:floatBubbleSort, double *: doubleBubbleSort, void **: ptrBubbleSort)(arr, size)

/**
 * @brief Quicksort for arrays
 * @return The return code of the function called
 * @param arr Pointer to the array to be sorted
 * @param size Number of elements in the array to be sorted
 */
#define quickSortArr(arr, size) _Generic(arr, char *: charQuickSort, int *: intQuickSort, float *:floatQuickSort, double *: doubleQuickSort, void **: ptrQuickSort)(arr, size)

#endif                            