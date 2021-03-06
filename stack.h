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
void push(Stack stack, ...);

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
void pop(Stack stack, void *dest);

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
void peekStack(Stack stack, void *dest);

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
void pushFromPtr(Stack stack, const void *element);

/**
 * @brief Get the size of a ::Stack
 * @param stack The ::Stack you want to evaluate
 * @return The number of elements in `stack`
 */
unsigned int getStackLength(const Stack stack);

/**
 * @brief Create a ::Stack from an array of chars
 * @details Equivalent to `chooseNewStackFromArray("%c", arr, size)`. Refer to chooseNewStackFromArray()
 */
Stack newStackFromCharArray(const char arr[], unsigned int size);

/**
 * @brief Create a ::Stack from an array of integers
 * @details Equivalent to `chooseNewStackFromArray("%i", arr, size)`. Refer to chooseNewStackFromArray()
 */
Stack newStackFromIntArray(const int arr[], unsigned int size);

/**
 * @brief Create a ::Stack from an array of floats
 * @details Equivalent to `chooseNewStackFromArray("%f", arr, size)`. Refer to chooseNewStackFromArray()
 */
Stack newStackFromFloatArray(const float arr[], unsigned int size);

/**
 * @brief Create a ::Stack from an array of doubles
 * @details Equivalent to `chooseNewStackFromArray("%lf", arr, size)`. Refer to chooseNewStackFromArray()
 */
Stack newStackFromDoubleArray(const double arr[], unsigned int size);

/**
 * @brief Create a ::Stack from an array of pointers
 * @details Equivalent to `chooseNewStackFromArray("%p", arr, size)`. Refer to chooseNewStackFromArray()
 */
Stack newStackFromPtrArray(const void *arr, unsigned int size);

/**
 * @brief Compare two ::Stack
 * @param stack1 The first ::Stack you want to compare
 * @param stack2 The second ::Stack you want to compare
 * @return The result of the comparison
 * @retval TRUE `stack1` and `stack2` have equal type and equal contents
 * @retval FALSE `stack1` and `stack2` do not have equal type or equal contents
 */
byte areStacksEqual(const Stack stack1, const Stack stack2);

#endif