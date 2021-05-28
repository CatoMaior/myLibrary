/**
 * @file queue.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Functions for working with ::Queue type
 */

#ifndef __SEEN_QUEUE
#define __SEEN_QUEUE

#include "types.h"

/**
 * @brief Allocate a new ::Queue of specified type
 * @param spec Type specifier of the ::Queue you want to create
 * @return An empty ::Queue
 */
Queue newQueue(const spec_t spec);

/**
 * @brief Enqueue an item to a ::Queue
 * @param queue The ::Queue you want to enqueue to
 * @param ... The item you want to append to `queue`
 * @note Even though enqueueing more than one item for single call call does not throw a compiler nor runtime error, only enqueueing one item is supported. Other items are ignored and are not enqueued to `queue`. If you don't specify any item to be enqueued, still no errors occur but the content of your ::queue can be messed up
 */
void enqueue(Queue queue, ...);

/**
 * @brief Dequeue an item from a ::Queue
 * @param queue The ::Queue you want to dequeue from
 * @param dest The address of the variable you want to store the dequeued item in
 */
void dequeue(Queue queue, void *dest);

/**
 * @brief Print contents from a ::Queue
 * @param spec The type and format specifier you want to use to print the single element of the ::Queue
 * @param queue The ::Queue you want to print
 */
void printQueue(const spec_t spec, const Queue queue);

/**
 * @brief Get the size of a ::Queue
 * @param queue The ::Queue you want to evaluate
 * @return The size of `queue`
 */
unsigned int getQueueSize(const Queue queue);

/**
 * @brief Delete current ::Queue head
 * @param queue The ::Queue you want to delete the head from
 */
void deleteHeadFromQueue(Queue queue);

/**
 * @brief Get the item at the head of a ::Queue without dequeueing it
 * @param queue The ::Queue you want to get the item
 * @param dest The address of the variable you want to store the item in
 */
void getHeadDataFromQueue(const Queue queue, void *dest);

/**
 * @brief Delete a ::Queue
 * @param queue The ::Queue you want to delete
 */
void deleteQueue(Queue queue);

/**
 * @brief Detect if an item is inside a ::Queue
 * @param queue The ::Queue you want search in
 * @param ... The element you want to search
 * @note This function does not support float and double ::Queue types
 * @note Even though specifying zero or more than one item for single call does not throw a compiler nor runtime error, only searching one item is supported. Other items are ignored. If you don't specify any item to be searched, still no errors occur but the return value of the function can be unpredictable
 * @retval TRUE Given element is contained in `queue`
 * @retval FALSE Given element is not contained in `queue`
 */
byte isInQueue(Queue queue, ...);

/**
 * @brief Create a ::Queue from an array
 * @param spec The type specifier of the array passed. Refer to spec_t
 * @param arr The array you want to create the ::Queue from
 * @param size The number of items of `arr`
 * @return A ::Queue containing the elements in `arr`, having the first element of `arr` as head
 */
Queue chooseNewQueueFromArray(const spec_t spec, const void *arr, unsigned int size);

/**
 * @brief Push an item to a ::Queue
 * @param queue The ::Queue you want to append an item to
 * @param element Pointer to the item you want to push to `queue`
 */
void enqueueFromPtr(Queue queue, const void *element);

#endif