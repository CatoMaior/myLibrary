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
#include <string.h>

/**
 * @brief Compare two values
 * @param a Pointer to the first value to be compared
 * @param b Pointer to the second value to be compared
 * @return The return code of the function called
 * @retval GREATER First element is grater than the second
 * @retval EQUAL First element is equal to the second
 * @retval SMALLER First element is smaller than the second
 */
#define cmpVal(a, b) _Generic((a, b), char *       \
                              : charCmp, int *     \
                              : intCmp, float *    \
                              : floatCmp, double * \
                              : doubleCmp, void ** \
                              : ptrCmp)(a, b)

/**
 * @brief BubbleSort for arrays
 * @return The return code of the function called
 * @param arr Pointer to the array to be sorted
 * @param size Number of elements in the array to be sorted
 */
#define bubbleSortArr(arr, size) _Generic(arr, char *                 \
                                          : charBubbleSort, int *     \
                                          : intBubbleSort, float *    \
                                          : floatBubbleSort, double * \
                                          : doubleBubbleSort, void ** \
                                          : ptrBubbleSort)(arr, size)

/**
 * @brief Quicksort for arrays
 * @return The return code of the function called
 * @param arr Pointer to the array to be sorted
 * @param size Number of elements in the array to be sorted
 */
#define quickSortArr(arr, size) _Generic(arr, char *                \
                                         : charQuickSort, int *     \
                                         : intQuickSort, float *    \
                                         : floatQuickSort, double * \
                                         : doubleQuickSort, void ** \
                                         : ptrQuickSort)(arr, size)

/**
 * @brief Create an ::ArrayList from a static array
 * @param arr The array you want to create an ::ArrayList from
 * @param size The size of `arr`
 * @return An ::ArrayList containing all the elements of `arr`
 */
#define newALFromArray(arr, size) _Generic(arr, char *                     \
                                           : newALFromCharArray, int *     \
                                           : newALFromIntArray, float *    \
                                           : newALFromFloatArray, double * \
                                           : newALFromDoubleArray, void ** \
                                           : newALFromPtrArray)(arr, size)

/**
 * @brief Create a ::LinkedList from a static array
 * @param arr The array you want to create a ::LinkedList from
 * @param size The size of `arr`
 * @return A ::LinkedList containing all the elements of `arr` in the same order
 */
#define newLLFromArray(arr, size) _Generic(arr, char *                     \
                                           : newLLFromCharArray, int *     \
                                           : newLLFromIntArray, float *    \
                                           : newLLFromFloatArray, double * \
                                           : newLLFromDoubleArray, void ** \
                                           : newLLFromPtrArray)(arr, size)

/**
 * @brief Create a ::Stack from a static array
 * @param arr The array you want to create a ::Stack from
 * @param size The size of `arr`
 * @return A ::Stack containing all the elements of `arr` with the last element of `arr` as head
 */
#define newStackFromArray(arr, size) _Generic(arr, char *                        \
                                              : newStackFromCharArray, int *     \
                                              : newStackFromIntArray, float *    \
                                              : newStackFromFloatArray, double * \
                                              : newStackFromDoubleArray, void ** \
                                              : newStackFromPtrArray)(arr, size)

/**
 * @brief Create a ::Queue from a static array
 * @param arr The array you want to create a ::Queue from
 * @param size The size of `arr`
 * @return A ::Queue containing all the elements of `arr` with the first element of `arr` as head
 */
#define newQueueFromArray(arr, size) _Generic(arr, char *                        \
                                              : newQueueFromCharArray, int *     \
                                              : newQueueFromIntArray, float *    \
                                              : newQueueFromFloatArray, double * \
                                              : newQueueFromDoubleArray, void ** \
                                              : newQueueFromPtrArray)(arr, size)

/**
 * @brief Create a ::Stack from a static array
 * @param arr The array you want to create a ::Stack from
 * @param size The size of `arr`
 * @return A ::Stack containing all the elements of `arr` with the first element of `arr` as head
 */
#define newStackFromArray(arr, size) _Generic(arr, char *                        \
                                              : newStackFromCharArray, int *     \
                                              : newStackFromIntArray, float *    \
                                              : newStackFromFloatArray, double * \
                                              : newStackFromDoubleArray, void ** \
                                              : newStackFromPtrArray)(arr, size)

/**
 * @brief Print contents from an ::ArrayList, ::LinkedList, ::Stack or ::Queue
 * @param spec The type and format specifier you want to use to print the single element. Use the `printf()` conventions
 * @param collection The ::ArrayList, ::LinkedList, ::Stack or ::Queue you want to print
 */
#define print(spec, collection) _Generic(collection, ArrayList       \
                                   : printAL, LinkedList \
                                   : printLL, Stack      \
                                   : printStack, Queue   \
                                   : printQueue)(spec, collection)

/**
 * @brief Compare two ::ArrayList, ::LinkedList, ::Stack or ::Queue
 * @param collection1 The first ::ArrayList, ::LinkedList, ::Stack or ::Queue you want to compare
 * @param collection2 The second ::ArrayList, ::LinkedList, ::Stack or ::Queue you want to compare
 * @note Passing two different types (for example, an ::ArrayList and a ::Stack) does not throw errors but does not work and the result can be unpredictable
 */
#define areEqual(collection1, collection2) _Generic(collection1, ArrayList         \
                                        : areALEqual, LinkedList \
                                        : areLLEqual, Stack      \
                                        : areStacksEqual, Queue  \
                                        : areQueuesEqual)(collection1, collection2)

/**
 * @brief Insert an item at the end of an ::ArrayList or ::LinkedList
 * @param list The list you want to append an item to
 * @param item The item you want to append to `list`
 */
#define append(list, item) _Generic(list, ArrayList          \
                                    : appendToAL, LinkedList \
                                    : appendToLL)(list, item)

/**
 * @brief Insert an element at a specified position of an ::ArrayList or ::LinkedList
 * @param list The list you want to insert an element into
 * @param index The position you want to insert an item at
 * @param item The item you want to insert into `list`
 */
#define insert(list, index, item) _Generic(list, ArrayList          \
                                           : insertToAL, LinkedList \
                                           : insertToLL)(list, index, item)

/**
 * @brief Set value of an element of an ::ArrayList or ::LinkedList
 * @param list The list you want to edit
 * @param index The index of the item you want to change
 * @param newItem The item you want to set the index-th element of `list` to
 */
#define set(list, index, newItem) _Generic(list, ArrayList         \
                                           : setALItem, LinkedList \
                                           : setLLItem)(list, index, newItem)

/**
 * @brief Merge two ::ArrayList or ::LinkedList
 * @param list1 The first list to be merged, where the merged list is saved
 * @param list2 The second list to be merged
 * @note Passing an ::ArrayList and a ::LinkedList does not throw errors but does not work and `list1` is messed up
 */
#define merge(list1, list2) _Generic(list1, ArrayList      \
                                     : mergeAL, LinkedList \
                                     : mergeLL)(list1, list2)

/**
 * @brief Slice an ::ArrayList or ::LinkedList
 * @param list The list you want to slice, where the sliced list is saved
 * @param begin The index of the beginning of the slice
 * @param end The index of the end of the slice
 */
#define slice(list, begin, end) _Generic(list, ArrayList       \
                                         : sliceAL, LinkedList \
                                         : sliceLL)(list, begin, end)

/**
 * @brief Remove an item from an ::ArrayList or ::LinkedList
 * @param list The list you want to delete an item from
 * @param index The index of the item you want to delete
 */
#define removeItem(list, index) _Generic(list, ArrayList            \
                                         : removeFromAL, LinkedList \
                                         : removeFromLL)(list, index)

/**
 * @brief Get an item from an ::ArrayList or ::LinkedList
 * @param list The list you want to get an item from
 * @param index The index of the item you want to get
 * @param dest The address of the variable you want to store the item in
 */
#define getItem(list, index, dest) _Generic(list, ArrayList         \
                                            : getFromAL, LinkedList \
                                            : getFromLL)(list, index, dest)

/**
 * @brief Delete an ::ArrayList, ::LinkedList, ::Stack or ::Queue
 * @param collection The ::ArrayList, ::LinkedList, ::Stack or ::Queue you want to delete
 */
#define delete(collection) _Generic(collection, ArrayList         \
                               : deleteAL, LinkedList \
                               : deleteLL, Stack      \
                               : deleteStack, Queue   \
                               : deleteQueue)(collection)

/**
 * @brief Detect if an item is inside an ::ArrayList, ::LinkedList, ::Stack or ::Queue
 * @param collection The ::ArrayList, ::LinkedList, ::Stack or ::Queue you want search in
 * @param item The item you want to search
 * @note Passing float or double ::ArrayList, ::LinkedList, ::Stack or ::Queue is not supported
 * @retval TRUE Given item is contained in `collection`
 * @retval FALSE Given item is not contained in `collection`
 */
#define isIn(collection, item) _Generic(collection, ArrayList      \
                                  : isInAL, LinkedList \
                                  : isInLL, Stack      \
                                  : isInStack, Queue   \
                                  : isInQueue)(collection, item)

/**
 * @brief Get the number of elements in an ::ArrayList, ::LinkedList, ::Stack, ::Queue or ::string
 * @param collection The ::ArrayList, ::LinkedList, ::Stack, ::Queue or ::string you want to evaluate
 * @return The number of elements in `collection`
 */
#define getLength(collection) _Generic(collection, ArrayList           \
                                 : getALLength, LinkedList \
                                 : getLLLength, Stack      \
                                 : getStackLength, Queue   \
                                 : getQueueLength, string  \
                                 : strlen)(collection)

/**
 * @brief Linear search for an ::ArrayList or ::LinkedList
 * @param list The ::ArrayList or ::LinkedList to be inspected
 * @param ley The key to be searched
 * @note This function does not support float and double ::LinkedList or ::ArrayList types
 * @return The index of the first occurence of the key in the list or the return code of the function called
 * @retval KEY_NOT_FOUND The key was not found
 */
#define linearSearch(list, key) _Generic(list, ArrayList              \
                                         : linearSearchAL, LinkedList \
                                         : linearSearchLL)(list, key)

/**
 * @brief Delete current ::Stack or ::Queue head
 * @param stack The ::Stack or ::Queue you want to delete the head from
 */
#define deleteHead(collection) _Generic(list, Stack                  \
                                  : deleteHeadFromStack, Queue \
                                  : deleteHeadFromQueue)(collection)

/**
 * @brief Check if an ::ArrayList, ::LinkedList, ::Stack or ::Queue is empty
 * @param collection The ::ArrayList, ::LinkedList, ::Stack or ::Queue to be checked
 * @retval TRUE `collection` is empty
 * @retval FALSE `collection` is not empty
 */
#define isEmpty(collection) _Generic(collection, ArrayList         \
                               : isALEmpty, LinkedList \
                               : isLLEmpty, Stack      \
                               : isStackEmpty, Queue   \
                               : isQueueEmpty)(collection, item)

/**
 * @brief Get the item at the head of a ::Stack or ::Queue without popping/dequeueing it
 * @param collection The ::Stack or ::Queue you want to get the item from
 * @param dest The address of the variable you want to store the item in
 */
#define getHeadData(collection, dest) _Generic(list, Stack                   \
                                         : getHeadDataFromStack, Queue \
                                         : getHeadDataFromQueue)(collection)
#endif