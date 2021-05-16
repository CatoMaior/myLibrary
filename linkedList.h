#ifndef __SEEN_LINKEDLIST
#define __SEEN_LINKEDLIST

#include "types.h"

/**
 * @brief Allocate a new ::LinkedList of specified type
 * @param spec Type specifier of the ::LinkedList you want to create
 * @return An empty ::LinkedList
 */
LinkedList newLL(const spec_t spec);

/**
 * @brief Print contents from an ::LinkedList
 * @param spec The type and format specifier you want to use to print the single element of the ::LinkedList
 * @param list The ::LinkedList you want to print
 */
void printLL(const spec_t spec, const LinkedList list);

/**
 * @brief Insert an item at the end of a ::LinkedList
 * @param list The ::LinkedList you want to append an item to
 * @param ... The item you want to append to `list`
 * @note Even though appending more than one item does not throw a compiler nor runtime error, only appending one item is supported. Other items are ignored and are not appended to `arr`. If you don't specify any item to be appended, still no errors occur but the content of your ::LinkedList can be messed up
 */
void appendToLL(LinkedList list, ...);

#endif