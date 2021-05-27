/**
 * @file arrayList.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Functions and macros for working with ::ArrayList type
 */

#ifndef __SEEN_ARRAYLIST
#define __SEEN_ARRAYLIST

#include "types.h"

/**
 * @brief Create an ::ArrayList from a static list
 * @param list The list you want to create an ::ArrayList from
 * @param size The size of `list`
 * @note Passing an list of pointers is not supported
 * @return An ::ArrayList containing all the elements of `list`
 */
#define newALFromArray(list, size) _Generic(list, char *                     \
                                           : newALFromCharArray, int *     \
                                           : newALFromIntArray, float *    \
                                           : newALFromFloatArray, double * \
                                           : newALFromDoubleArray)(list, size)

// TYPE INDIPENDENT FUNCTIONS
/**
 * @brief Allocate a new ::ArrayList of specified type
 * @param spec Type specifier of the ::ArrayList you want to create
 * @return An empty ::ArrayList
 */
ArrayList newAL(const spec_t spec);

/**
 * @brief Get a copy of an ::ArrayList
 * @param list The ::ArrayList you want to copy
 * @return A copy of `list`
 */
ArrayList newALFromAL(const ArrayList list);

/**
 * @brief Insert an item at the end of an ::ArrayList 
 * @param list The ::ArrayList you want to append an item to
 * @param ... The item you want to append to `list`
 * @note Even though appending more than one item for single call does not throw a compiler nor runtime error, only appending one item is supported. Other items are ignored and are not appended to `list`. If you don't specify any item to be appended, still no errors occur but the content of your ::ArrayList can be messed up
 */
void appendToAL(ArrayList list, ...);

/**
 * @brief Insert an element at a specified position of an ::ArrayList
 * @param list The ::ArrayList you want to insert an element into
 * @param index The position you want to insert an item at
 * @param ... The item you want to insert into `list`
 * @note Even though inserting more than one item for single call does not throw a compiler nor runtime error, only inserting one item is supported. Other items are ignored and are not inserted into `list`. If you don't specify any item to be inserted, still no errors occur but the content of your ::ArrayList can be messed up
 */
void insertToAL(ArrayList list, unsigned int index, ...);

/**
 * @brief Set value of an element of an ::ArrayList
 * @param list The ::ArrayList you want to edit
 * @param index The index of the element you want to change
 * @param ... The item you want to insert into `list`
 * @note Even though inserting more than one item for single call does not throw a compiler nor runtime error, only setting one item is supported. Other items are ignored. If you don't specify any item to be inserted, still no errors occur but the content of your ::ArrayList can be messed up
 */
void setALItem(ArrayList list, unsigned int index, ...);

/**
 * @brief Merge two ::ArrayList
 * @param list1 The first ::ArrayList to be merged, where the merged ::ArrayList is saved
 * @param list2 The second ::ArrayList to be merged
 */
void mergeAL(ArrayList list1, const ArrayList list2);

/**
 * @brief Slice an ::ArrayList
 * @param list The ::ArrayList you want to slice, where the sliced ::ArrayList is saved
 * @param begin The index of the beginning of the slice
 * @param end The index of the end of the slice
 */
void sliceAL(ArrayList list, unsigned int begin, unsigned int end);

/**
 * @brief Print contents from an ::ArrayList
 * @param spec The type and format specifier you want to use to print the single element of the ::ArrayList
 * @param list The ::ArrayList you want to print
 */
void printAL(const spec_t spec, const ArrayList list);

/**
 * @brief Remove an item from an ::ArrayList
 * @param list The ::ArrayList you want to delete an item from
 * @param index The index of the item you want to delete
 */
void removeFromAL(ArrayList list, unsigned int index);

/**
 * @brief Get an item from an ::ArrayList
 * @param list The ::ArrayList you want to get an item from
 * @param index The index of the item you want to get
 * @param dest The address of the variable you want to store the item in
 */
void getFromAL(const ArrayList list, unsigned int index, void *dest);

/**
 * @brief Delete an ::ArrayList
 * @param list The ::ArrayList you want to delete
 */
void deleteAL(ArrayList list);

/**
 * @brief Compare two ::ArrayList
 * @param list1 The first ::ArrayList you want to compare
 * @param list2 The second ::ArrayList you want to compare
 * @return The result of the comparison
 * @retval TRUE `list1` and `list2` have equal type, equal length and equal contents
 * @retval FALSE `list1` and `list2` do not have equal type, equal length or equal contents
 */
byte areALEqual(const ArrayList list1, const ArrayList list2);

/**
 * @brief Reverse an ::ArrayList
 * @param list The ::ArrayList you want to reverse
 */
void reverseAL(ArrayList list);

/**
 * @brief Bubble sort for ::ArrayList
 * @param list The ::ArrayList you want to bubble sort
 */
void bubbleSortAL(ArrayList list);

/**
 * @brief Quicksort for ::ArrayList
 * @param list The ::ArrayList you want to quicksort
 */
void quickSortAL(ArrayList list);

/**
 * @brief Detect if an element is inside an ::ArrayList
 * @param list The ::ArrayList you want search in
 * @param ... The element you want to search
 * @note Even though inserting zero more than one item for single call does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @retval TRUE Given element is contained in `list`
 * @retval FALSE Given element is not contained in `list`
 */
byte isInAL(ArrayList list, ...);

/**
 * @brief Linear search for ::ArrayList
 * @param list The ::ArrayList to be inspected
 * @param ... The key to be searched
 * @note This function does not support float and double ::ArrayList
 * @note Even though passing more than one key does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @return The index of the first occurence of the key in the list or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int linearSearchAL(ArrayList list, ...);

/**
 * @brief Create an ::ArrayList from an list
 * @param spec The type specifier of the list passed. Refer to spec_t
 * @param list The list you want to create the ::ArrayList from
 * @param size The number of items of `list`
 * @return An ::ArrayList containing the elements in `list` in the same order
 */
ArrayList chooseNewALFromArray(const spec_t spec, const void *list, unsigned int size);

// TYPE DIPENDENT FUNCTIONS
/**
 * @brief Create ::ArrayList from an list of chars
 * @details Equivalent to `chooseNewALFromArray("%c", list, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromCharArray(const char list[], unsigned int size);

/**
 * @brief Alias for newALFromCharArray(). Used to create ::ArrayList from byte list. Refer to newALFromCharArray()
 */
ArrayList newALFromByteArray(const char list[], unsigned int size);

/**
 * @brief Create ::ArrayList from an list of ints
 * @details Equivalent to `chooseNewALFromArray("%i", list, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromIntArray(const int list[], unsigned int size);

/**
 * @brief Create ::ArrayList from an list of floats
 * @details Equivalent to `chooseNewALFromArray("%f", list, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromFloatArray(const float list[], unsigned int size);

/**
 * @brief Create ::ArrayList from an list of doubles
 * @details Equivalent to `chooseNewALFromArray("%lf", list, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromDoubleArray(const double list[], unsigned int size);

/**
 * @brief Create ::ArrayList from an list of pointers
 * @details Equivalent to `chooseNewALFromArray("%p", list, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromPtrArray(const void *list, unsigned int size);

#endif