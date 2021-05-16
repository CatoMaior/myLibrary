/**
 * @file arrayList.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief ::ArrayList functions and macros
 */

#ifndef __SEEN_ARRAYLIST
#define __SEEN_ARRAYLIST

#include "types.h"

/**
 * @brief Create an ::ArrayList from a static array
 * @param arr The array you want to create an ::ArrayList from
 * @param size The size of `arr`
 * @note Passing an array of pointers is not supported
 * @return An ::ArrayList containing all the elements of `arr`
 */
#define newALFromArray(arr, size) _Generic(arr, char *                     \
                                           : newALFromCharArray, int *     \
                                           : newALFromIntArray, float *    \
                                           : newALFromFloatArray, double * \
                                           : newALFromDoubleArray)(arr, size)

// TYPE INDIPENDENT FUNCTIONS
/**
 * @brief Allocate a new ::ArrayList of specified type
 * @param spec Type specifier of the ::ArrayList you want to create
 * @return An empty ::ArrayList
 */
ArrayList newAL(const spec_t spec);

/**
 * @brief Get a copy of an ::ArrayList
 * @param arr The ::ArrayList you want to copy
 * @return A copy of `arr`
 */
ArrayList newALFromAL(const ArrayList arr);

/**
 * @brief Insert an item at the end of an ::ArrayList 
 * @param arr The ::ArrayList you want to append an item to
 * @param ... The item you want to append to `arr`
 * @note Even though appending more than one item does not throw a compiler nor runtime error, only appending one item is supported. Other items are ignored and are not appended to `arr`. If you don't specify any item to be appended, still no errors occur but the content of your ::ArrayList can be messed up
 */
void appendToAL(ArrayList arr, ...);

/**
 * @brief Insert an element at a specified position of an ::ArrayList
 * @param arr The ::ArrayList you want to insert an element into
 * @param index The position you want to insert `element` at
 * @param ... The item you want to insert into `arr`
 * @note Even though inserting more than one item does not throw a compiler nor runtime error, only inserting one item is supported. Other items are ignored and are not inserted into `arr`. If you don't specify any item to be inserted, still no errors occur but the content of your ::ArrayList can be messed up
 */
void insertToAL(ArrayList arr, unsigned int index, ...);

/**
 * @brief Set value of an element of an ::ArrayList
 * @param arr The ::ArrayList you want to edit
 * @param index The index of the element you want to change
 * @param ... The item you want to insert into `arr`
 * @note Even though inserting more than one item does not throw a compiler nor runtime error, only setting one item is supported. Other items are ignored. If you don't specify any item to be inserted, still no errors occur but the content of your ::ArrayList can be messed up
 */
void setALItem(ArrayList arr, unsigned int index, ...);

/**
 * @brief Merge two ::ArrayList
 * @param arr1 The first ::ArrayList to be merged, where the merged ::ArrayList is saved
 * @param arr2 The second ::ArrayList to be merged
 */
void mergeAL(ArrayList arr1, const ArrayList arr2);

/**
 * @brief Slice an ::ArrayList
 * @param arr The ::ArrayList you want to slice, where the sliced ::ArrayList is saved
 * @param begin The index of the beginning of the slice
 * @param end The index of the end of the slice
 */
void sliceAL(ArrayList arr, unsigned int begin, unsigned int end);

/**
 * @brief Print contents from an ::ArrayList
 * @param spec The type and format specifier you want to use to print the single element of the ::ArrayList
 * @param arr The ::ArrayList you want to print
 */
void printAL(const spec_t spec, const ArrayList arr);

/**
 * @brief Remove an item from an ::ArrayList
 * @param arr The ::ArrayList you want to delete an item from
 * @param index The index of the item you want to delete
 */
void removeFromAL(ArrayList arr, unsigned int index);

/**
 * @brief Get an item from an ::ArrayList
 * @param arr The ::ArrayList you want to get an item from
 * @param index The index of the item you want to get
 * @param dest The address of the variable you want to store the item in
 */
void getFromAL(const ArrayList arr, unsigned int index, void *dest);

/**
 * @brief Delete an ::ArrayList
 * @param arr The ::ArrayList you want to delete
 */
void deleteAL(ArrayList arr);

/**
 * @brief Compare two ::ArrayList
 * @param arr1 The first ::ArrayList you want to compare
 * @param arr2 The second ::ArrayList you want to compare
 * @return The result of the comparison
 * @retval TRUE `arr1` and `arr2` have equal type, equal length and equal contents
 * @retval FALSE `arr1` and `arr2` do not have equal type, equal length or equal contents
 */
byte areALEqual(const ArrayList arr1, const ArrayList arr2);

/**
 * @brief Reverse an ::ArrayList
 * @param arr The ::ArrayList you want to reverse
 */
void reverseAL(ArrayList arr);

/**
 * @brief Bubble sort for ::ArrayList
 * @param arr The ::ArrayList you want to bubble sort
 */
void bubbleSortAL(ArrayList arr);

/**
 * @brief Quicksort for ::ArrayList
 * @param arr The ::ArrayList you want to quicksort
 */
void quickSortAL(ArrayList arr);

/**
 * @brief Detect if an element is inside an ::ArrayList
 * @param arr The ::ArrayList you want search in
 * @param ... The element you want to search
 * @note Even though inserting zero more than one item does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @retval TRUE Given element is contained in `arr`
 * @retval FALSE Given element is not contained in `arr`
 */
byte isInAL(ArrayList arr, ...);

/**
 * @brief Linear search for ::ArrayList
 * @param arr The ::ArrayList to be inspected
 * @param ... The key to be searched
 * @note This function does not support float and double ::ArrayList
 * @note Even though passing more than one key does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @return The index of the first occurence of the key in the array or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int linearSearchAL(ArrayList arr, ...);

/**
 * @brief Create an ::ArrayList from an array
 * @param spec The type specifier of the array passed. Refer to spec_t
 * @param arr The array you want to create the ::ArrayList from
 * @param size The number of items of `arr`
 * @return An ::ArrayList containing the elements in `arr` in the same order
 */
ArrayList chooseNewALFromArray(const spec_t spec, const void *arr, unsigned int size);

// TYPE DIPENDENT FUNCTIONS
/**
 * @brief Create ::ArrayList from an array of chars
 * @details Equivalent to `chooseNewALFromArray("%c", arr, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromCharArray(const char arr[], unsigned int size);

/**
 * @brief Alias for newALFromCharArray(). Used to create ::ArrayList from byte array. Refer to newALFromCharArray()
 */
ArrayList newALFromByteArray(const char arr[], unsigned int size);

/**
 * @brief Create ::ArrayList from an array of ints
 * @details Equivalent to `chooseNewALFromArray("%i", arr, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromIntArray(const int arr[], unsigned int size);

/**
 * @brief Create ::ArrayList from an array of floats
 * @details Equivalent to `chooseNewALFromArray("%f", arr, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromFloatArray(const float arr[], unsigned int size);

/**
 * @brief Create ::ArrayList from an array of doubles
 * @details Equivalent to `chooseNewALFromArray("%lf", arr, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromDoubleArray(const double arr[], unsigned int size);

/**
 * @brief Create ::ArrayList from an array of pointers
 * @details Equivalent to `chooseNewALFromArray("%p", arr, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromPtrArray(const void *arr, unsigned int size);

#endif