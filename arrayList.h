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
 * @return An ::ArrayList containing all the elements of `arr`void
 */
#define newALFromArray(arr, size) _Generic(arr, char*: newALFromCharArray)(arr, size)

// TYPE INDIPENDENT FUNCTIONS
/**
 * @brief Allocate a new ::ArrayList
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
 * @param ... The item you want to append to `arr`. Even though appending more than one item does not throw a compiler nor runtime error, only appending one item is supported. Other items are ignored and are not appended to `arr`
 */
void appendToAL(ArrayList arr, ...);

/**
 * @brief Insert an element at a specified position of an ::ArrayList
 * @param arr The ::ArrayList you want to insert an element into
 * @param index The position you want to insert `element` at
 * @param ... The item you want to insert into `arr`. Even though inserting more than one item does not throw a compiler nor runtime error, only inserting one item is supported. Other items are ignored and are not inserted into `arr`
 */
void insertToAL(ArrayList arr, unsigned int index, ...);

/**
 * @brief Set value of an element of an ::ArrayList
 * @param arr The ::ArrayList you want to edit
 * @param index The index of the element you want to change
 * @param ... The item you want to insert into `arr`. Even though inserting more than one item does not throw a compiler nor runtime error, only setting one item is supported. Other items are ignored
 */
void setALElement(ArrayList arr, unsigned int index, ...);

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
 * @brief Print an ::ArrayList content
 * @param spec The type and format specifier you want to use to print the single element of the ::ArrayList
 * @param arr The ::ArrayList you want to print
 */
void printAL(const spec_t spec, const ArrayList arr);

/**
 * @brief Remove an element from an ::ArrayList
 * @param arr The ::ArrayList you want to delete an element from
 * @param index The index of the element you want to delete
 */
void removeFromAL(ArrayList arr, unsigned int index);

/**
 * @brief Get an element from an ::ArrayList
 * @param arr The ::ArrayList you want to get the item from
 * @param index The index of the element you want to get
 * @param dest The address of the variable you want to store the result in
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
byte areALEqual(ArrayList arr1, ArrayList arr2);

/**
 * @brief Reverse an ::ArrayList
 * @param arr The array you want to reverse
 */
void reverseAL(ArrayList arr);

/**
 * @brief Bubble sort for ::ArrayList
 * @param arr The ::ArrayList you want to bubble sort
 */
void bubbleSortAL(ArrayList arr);

/**
 * @brief Quicksort for ::ArrayList
 * @param arr The ::ArrayList you want to quickort
 */
void quickSortAL(ArrayList arr);

/**
 * @brief Create an ::ArrayList from an array
 * @param spec The type specifier of the array passed. Refer to spec_t
 * @param arr The array you want to create the ::ArrayList from
 * @param size The size of `arr`
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

#endif