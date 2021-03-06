/**
 * @file arrayList.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Functions for working with ::ArrayList type
 */

#ifndef SEEN_ARRAYLIST
#define SEEN_ARRAYLIST

#include "types.h"

// TYPE INDEPENDENT FUNCTIONS
/**
 * @brief Allocate a new ::ArrayList of specified type
 * @param spec Type specifier of the ::ArrayList you want to create
 * @return An empty ::ArrayList
 */
ArrayList newAL(const spec_t spec);

/**
 * @brief Get a copy of an ::ArrayList
 * @param list The ::ArrayList you want to copy
 * @note When creating an ::ArrayList from a pointer ::ArrayList type the pointers in `list` are inserted into the ::ArrayList, not what they point to
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
 * @brief Insert an item at a specified position of an ::ArrayList
 * @param list The ::ArrayList you want to insert an item into
 * @param index The position you want to insert an item at
 * @param ... The item you want to insert into `list`
 * @note Even though inserting more than one item for single call does not throw a compiler nor runtime error, only inserting one item is supported. Other items are ignored and are not inserted into `list`. If you don't specify any item to be inserted, still no errors occur but the content of your ::ArrayList can be messed up
 */
void insertToAL(ArrayList list, unsigned int index, ...);

/**
 * @brief Set value of an item of an ::ArrayList
 * @param list The ::ArrayList you want to edit
 * @param index The index of the item you want to change
 * @param ... The item you want to set the index-th item of `list` to
 * @note Even though changing more than one item for single call does not throw a compiler nor runtime error, only setting one item is supported. Other items are ignored. If you don't specify any item to be inserted, still no errors occur but the content of your ::ArrayList can be messed up
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
 * @param spec The type and format specifier you want to use to print the single item of the ::ArrayList. Use the `printf()` conventions
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
 * @param ... The function used to free memory pointed by every pointer of the ::ArrayList. Must be a function that takes a pointer as argument. Necessary only for pointer ::ArrayList type, ignored otherwise. When deleting a pointer ::ArrayList type if no free function is passed no compiler errors are thrown but you may cause severe memory leaks
 */
void deleteAL(ArrayList list, ...);

/**
 * @brief Compare two ::ArrayList
 * @param list1 The first ::ArrayList you want to compare
 * @param list2 The second ::ArrayList you want to compare
 * @param ... The comparison function needed to compare items inside given lists. This parameter is necessary only for pointer ::ArrayList type and is ignored otherwise. Must be a function that takes two pointers as argument and returns a positive int if the item pointed by the first argument is greater than the item pointed by the second argument, a negative int if the item pointed by the first argument is is smaller than the item pointed by second, a zero int if the item pointed by first and second arguments are equal
 * @note If comparing two pointer ::ArrayList type and the comparing function is not given a compiler nor runtime error is given, but the result of the comparison is unpredictable
 * @return The result of the comparison
 * @retval TRUE `list1` and `list2` have equal type, equal length and equal contents
 * @retval FALSE `list1` and `list2` do not have equal type, equal length or equal contents
 */
byte areALEqual(const ArrayList list1, const ArrayList list2, ...);

/**
 * @brief Reverse an ::ArrayList
 * @param list The ::ArrayList you want to reverse
 */
void reverseAL(ArrayList list);

/**
 * @brief Bubble sort for ::ArrayList
 * @param list The ::ArrayList you want to bubble sort
 * @param ... The comparison function needed to compare items inside given lists. This parameter is necessary only for pointer ::ArrayList type and is ignored otherwise. Must be a function that takes two pointers as argument and returns a positive int if the item pointed by the first argument is greater than the item pointed by the second argument, a negative int if the item pointed by the first argument is is smaller than the item pointed by second, a zero int if the item pointed by first and second arguments are equal
 * @note If sorting an ::ArrayList type and the comparing function is not passed a compiler error is not given, but the ::ArrayList will be messed up
 */
void bubbleSortAL(ArrayList list, ...);

/**
 * @brief Quicksort for ::ArrayList
 * @param list The ::ArrayList you want to quicksort
 * @param ... The comparison function needed to compare items inside given lists. This parameter is necessary only for pointer ::ArrayList type and is ignored otherwise. Must be a function that takes two pointers as argument and returns a positive int if the item pointed by the first argument is greater than the item pointed by the second argument, a negative int if the item pointed by the first argument is is smaller than the item pointed by second, a zero int if the item pointed by first and second arguments are equal
 * @note If sorting a pointer ::ArrayList type and the comparing function is not passed a compiler error is not given, but the ::ArrayList will be messed up
 */
void quickSortAL(ArrayList list, ...);

/**
 * @brief Detect if an item is inside an ::ArrayList
 * @param list The ::ArrayList you want search in
 * @param ... The item you want to search. If searaching in a pointer ::ArrayList type, after the item you want so search, you must provide the comparison function needed to compare the item you want to search and the items in the ::ArrayList. Must be a function that takes two pointers as argument and returns a zero int only if the item pointed by first and second arguments are equal
 * @note Even though searching more than one item for single call does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable. If searching in a pointer ::ArrayList type and the comparing function is not passed a compiler error is not given either, but the return value of the function can be unpredictable
 * @retval TRUE Given item is contained in `list`
 * @retval FALSE Given item is not contained in `list`
 */
byte isInAL(ArrayList list, ...);

/**
 * @brief Linear search for ::ArrayList
 * @param list The ::ArrayList to be inspected
 * @param ... The key to be searched. If searaching in a pointer ::ArrayList type, after the item you want so search, you must provide the comparison function needed to compare the item you want to search and the items in the ::ArrayList. Must be a function that takes two pointers as argument and returns a zero int only if the item pointed by first and second arguments are equal
 * @note Even though passing more than one key does not throw a compiler nor runtime error, only searching one key is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable. If searching in a pointer ::ArrayList type and the comparing function is not passed a compiler or runtime error is not given either, but the return value of the function can be unpredictable
 * @return The index of the first occurence of the key in the list or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int linearSearchAL(ArrayList list, ...);

/**
 * @brief Create an ::ArrayList from a static array
 * @param spec The type specifier of the array passed. Refer to spec_t
 * @param list The list you want to create the ::ArrayList from
 * @param size The number of items in `list`
 * @note When creating an ::ArrayList from a pointer array the pointers are inserted into the ::ArrayList, not what they point to
 * @return An ::ArrayList containing the items in `list` in the same order
 */
ArrayList chooseNewALFromArray(const spec_t spec, const void *list, unsigned int size);

// TYPE DEPENDENT FUNCTIONS
/**
 * @brief Create ::ArrayList from a list of chars
 * @details Equivalent to `chooseNewALFromArray("%c", list, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromCharArray(const char list[], unsigned int size);

/**
 * @brief Create ::ArrayList from a list of bytes
 * @details Alias for newALFromCharArray(). Used to create ::ArrayList from byte list. Refer to newALFromCharArray()
 */
ArrayList newALFromByteArray(const char list[], unsigned int size);

/**
 * @brief Create ::ArrayList from a list of ints
 * @details Equivalent to `chooseNewALFromArray("%i", list, size)`. Refer to chooseNewALFromArray()
 */
ArrayList newALFromIntArray(const int list[], unsigned int size);

/**
 * @brief Create ::ArrayList from a list of floats
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

/**
 * @brief Get the size of an ::ArrayList
 * @param list The ::ArrayList you want to evaluate
 * @return The number of items in `list`
 */
unsigned int getALLength(const ArrayList list);

/**
 * @brief Check if ::ArrayList is empty
 * @param list The ::ArrayList to be checked
 * @retval TRUE `list` is empty
 * @retval FALSE `list` is not empty
 */
byte isALEmpty(ArrayList list);

#endif