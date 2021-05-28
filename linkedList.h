/**
 * @file linkedList.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Functions for working with ::LinkedList type
 */

#ifndef __SEEN_LINKEDLIST
#define __SEEN_LINKEDLIST

#include "types.h"

/**
 * @brief Allocate a new ::LinkedList of specified type
 * @param spec Type specifier of the ::LinkedList you want to create. Refer to ::spec_t for supported types
 * @return An empty ::LinkedList
 */
LinkedList newLL(const spec_t spec);

/**
 * @brief Create a ::LinkedList from an array
 * @param spec The type specifier of the array passed. Refer to ::spec_t for supported types
 * @param arr The array you want to create the ::LinkedList from
 * @param size The number of items of `list`
 * @return A ::LinkedList containing the elements in `list` in the same order
 */
LinkedList chooseNewLLFromArray(const spec_t spec, const void *arr, unsigned int size);

/**
 * @brief Print contents from a ::LinkedList
 * @param spec The type and format specifier you want to use to print the single element of the ::LinkedList. Use the `printf()` conventions
 * @param list The ::LinkedList you want to print
 */
void printLL(const spec_t spec, const LinkedList list);

/**
 * @brief Insert an item at the end of a ::LinkedList
 * @param list The ::LinkedList you want to append an item to
 * @param ... The item you want to append to `list`
 * @note Even though appending more than one item for single call does not throw a compiler nor runtime error, only appending one item is supported. Other items are ignored and are not appended to `list`. If you don't specify any item to be appended, still no errors occur but the content of your ::LinkedList can be messed up
 */
void appendToLL(LinkedList list, ...);

/**
 * @brief Insert an item at the end of a ::LinkedList
 * @param list The ::LinkedList you want to append an item to
 * @param element Pointer to the item you want to append to `list`
 */
void appendToLLFromPtr(LinkedList list, const void *element);

/**
 * @brief Insert an element at a specified position of a ::LinkedList
 * @param list The ::LinkedList you want to insert an element into
 * @param index The position you want to insert an element at
 * @param ... The item you want to insert into `list`
 * @note Even though inserting more than one item for single call does not throw a compiler nor runtime error, only inserting one item is supported. Other items are ignored and are not inserted into `list`. If you don't specify any item to be inserted, still no errors occur but the content of your ::LinkedList can be messed up
 */
void insertToLL(LinkedList list, unsigned int index, ...);

/**
 * @brief Delete a ::LinkedList
 * @param list The ::LinkedList you want to delete
 */
void deleteLL(LinkedList list);

/**
 * @brief Get an item from a ::LinkedList
 * @param list The ::LinkedList you want to get an item from
 * @param index The index of the item you want to get
 * @param dest The address of the variable you want to store the item in
 */
void getFromLL(LinkedList list, unsigned int index, void *dest);

/**
 * @brief Set value of an element of a ::LinkedList
 * @param list The ::LinkedList you want to edit
 * @param index The index of the element you want to change
 * @param ... The item you want to insert into `list`
 * @note Even though changing more than one item for single call does not throw a compiler nor runtime error, only setting one item is supported. Other items are ignored. If you don't specify any item to be inserted, still no errors occur but the content of your ::LinkedList can be messed up
 */
void setLLItem(LinkedList list, unsigned int index, ...);

/**
 * @brief Remove an item from a ::LinkedList
 * @param list The ::LinkedList you want to delete an item from
 * @param index The index of the item you want to delete
 */
void removeFromLL(LinkedList list, unsigned int index);

/**
 * @brief Merge two ::LinkedList
 * @param list1 The first ::LinkedList to be merged, where the merged ::LinkedList is saved
 * @param list2 The second ::LinkedList to be merged
 */
void mergeLL(LinkedList list1, const LinkedList list2);

/**
 * @brief Get a copy of a ::LinkedList
 * @param list The ::LinkedList you want to copy
 * @return A copy of `list`
 */
LinkedList newLLFromLL(const LinkedList list);

/**
 * @brief Slice a ::LinkedList
 * @param list The ::LinkedList you want to slice, where the sliced ::LinkedList is saved
 * @param begin The index of the beginning of the slice
 * @param end The index of the end of the slice
 */
void sliceLL(LinkedList list, unsigned int begin, unsigned int end);

/**
 * @brief Linear search for ::LinkedList
 * @param list The ::LinkedList to be inspected
 * @param ... The key to be searched
 * @note This function does not support float and double ::LinkedList types
 * @note Even though passing more than one key does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @return The index of the first occurence of the key in the list or the return code of the function
 * @retval KEY_NOT_FOUND The key was not found
 */
int linearSearchLL(LinkedList list, ...);

/**
 * @brief Linear search for ::LinkedList
 * @param list The ::LinkedList to be inspected
 * @param ... The key to be searched
 * @note This function does not support float and double ::LinkedList types
 * @note Even though passing more than one key does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @return A void pointer of the first occurence of the key in the list or the return code of the function
 * @retval NULL The key was not found
 */
void *linearSearchLLPtr(LinkedList list, ...);

/**
 * @brief Compare two ::LinkedList
 * @param list1 The first ::LinkedList you want to compare
 * @param list2 The second ::LinkedList you want to compare
 * @return The result of the comparison
 * @retval TRUE `list1` and `list2` have equal type, equal length and equal contents
 * @retval FALSE `list1` and `list2` do not have equal type, equal length or equal contents
 */
byte areLLEqual(const LinkedList list1, const LinkedList list2);

/**
 * @brief Detect if an element is inside a ::LinkedList
 * @param list The ::LinkedList you want search in
 * @param ... The element you want to search
 * @note Even though checking more than one item for single call does not throw a compiler nor runtime error, only checking one item is supported. Other items are ignored. If you don't specify any item to be checked, still no errors occur but the return value of the function can be unpredictable
 * @retval TRUE Given element is contained in `list`
 * @retval FALSE Given element is not contained in `list`
 */
byte isInLL(LinkedList list, ...);

// TODO Sorting algorithms, currently available only for ArrayList

#endif