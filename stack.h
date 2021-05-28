/**
 * @file stack.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Functions for working with ::Stack type
 */

#ifndef SEEN_STACK
#define SEEN_STACK

#include "types.h"

/**
 * @brief Allocate a new ::Stack of specified type
 * @param spec Type specifier of the ::Stack you want to create. Refer to ::spec_t for supported types
 * @return An empty ::Stack
 */
Stack newStack(const spec_t spec);

/**
 * @brief Push an item into a ::Stack
 * @param stack The ::Stack you want to push into
 * @param ... The item you want to push into `stack`
 * @note Even though pushing more than one item for single call does not throw a compiler nor runtime error, only pushing one item is supported. Other items are ignored and are not pushed into `stack`. If you don't specify any item to be pushed, still no errors occur but the content of your ::Stack can be messed up
 */
void pushToStack(Stack stack, ...);

/**
 * @brief Print contents from a ::Stack
 * @param spec The type and format specifier you want to use to print the single element of the ::Stack. Use the `printf()` conventions
 * @param stack The ::Stack you want to print
 */
void printStack(const spec_t spec, const Stack stack);

/**
 * @brief Pop an item from a ::Stack
 * @param stack The ::Stack you want to pop an item from
 * @param dest The address of the variable you want to store the popped item in
 */
void popFromStack(Stack stack, void *dest);

/**
 * @brief Delete current ::Stack head
 * @param stack The ::Stack you want to delete the head from
 */
void deleteHeadFromStack(Stack stack);

/**
 * @brief Check if ::Stack is empty
 * @param stack The ::Stack to be checked
 * @retval TRUE `stack` is empty
 * @retval FALSE `stack` is not empty
 */
byte isStackEmpty(Stack stack);

/**
 * @brief Delete a ::Stack
 * @param stack The ::Stack you want to delete
 */
void deleteStack(Stack stack);

/**
 * @brief Get the item at the head of a ::Stack without popping it
 * @param stack The ::Stack you want to get the item
 * @param dest The address of the variable you want to store the item in
 */
void getHeadDataFromStack(Stack stack, void *dest);

/**
 * @brief Detect if an item is inside a ::Stack
 * @param stack The ::Stack you want search in
 * @param ... The element you want to search
 * @note This function does not support float and double ::Stack types
 * @note Even though specifying more than one item for single call does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @retval TRUE Given element is contained in `stack`
 * @retval FALSE Given element is not contained in `stack`
 */
byte isInStack(Stack stack, ...);

/**
 * @brief Create a ::Stack from an array
 * @param spec The type specifier of the array passed. Refer to ::spec_t for supported types
 * @param arr The array you want to create the ::Stack from
 * @param size The number of items in `arr`
 * @return A ::Stack containing the elements in `arr`, having the last element of `arr` as head
 */
Stack chooseNewStackFromArray(const spec_t spec, const void *arr, unsigned int size);

/**
 * @brief Push an item into a ::Stack
 * @param stack The ::Stack you want to push an item into
 * @param element Pointer to the item you want to push into `stack`
 */
void pushToStackFromPtr(Stack stack, const void *element);

#endif