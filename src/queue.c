#include "../constants.h"
#include "../strings.h"
#include "../types.h"
#include "../utility.h"
#include "errors.h"
#include "utilityInternal.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

Queue newQueue(const spec_t spec) {
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    Queue queue = saferMalloc(sizeof(*queue));
    queue->type = copyOf(spec);
    return queue;
}

void enqueue(Queue queue, ...) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    Node newNode = saferMalloc(sizeof(*newNode));
    byte typeSize = getTypeSize(queue->type);
    newNode->data = saferMalloc(typeSize);
    va_list argList;
    va_start(argList, queue);
    varData data;
    getDataFromArgList(queue->type, argList, &data);
    va_end(argList);
    memcpy(newNode->data, &data, typeSize);
    if (queue->tail)
        queue->tail->linked = newNode;
    queue->tail = newNode;
    if (!queue->head)
        queue->head = newNode;
}

void printQueue(const spec_t spec, const Queue queue) {
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    printLinked(spec, queue);
}

unsigned int getQueueLength(const Queue queue) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    return getLinkedSize(queue);
}

void deleteHeadFromQueue(Queue queue) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    funcThrowIf(!queue->head, NULL_QUEUE_HEAD);
    Node newHead = queue->head->linked;
    free(queue->head->data);
    free(queue->head);
    queue->head = newHead;
}

void getHeadDataFromQueue(const Queue queue, void *dest) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    funcThrowIf(!queue->head, NULL_QUEUE_HEAD);
    memcpy(dest, queue->head->data, getTypeSize(queue->type));
}

void dequeue(Queue queue, void *dest) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    funcThrowIf(!queue->head, NULL_QUEUE_HEAD);
    getHeadDataFromQueue(queue, dest);
    deleteHeadFromQueue(queue);
}

void deleteQueue(Queue queue) {
    while (getQueueLength(queue) != 0)
        deleteHeadFromQueue(queue);
    free(queue);
}

byte isInQueue(Queue queue, ...) {
    funcThrowIf(!queue, NULL_POINTER_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    funcThrowIf(endsWith(queue->type, "f"), UNSUPPORTED_SPECIFIER);
    va_list argList;
    va_start(argList, queue);
    varData key;
    getDataFromArgList(queue->type, argList, &key);
    va_end(argList);
    byte typeSize = getTypeSize(queue->type);
    for (Node currNode = queue->head; currNode; currNode = currNode->linked)
        if (memcmp(currNode->data, &key, typeSize) == 0)
            return TRUE;
    return FALSE;
}

Queue chooseNewQueueFromArray(const spec_t spec, const void *arr, unsigned int size) {
    funcThrowIf(!spec || !arr, NULL_POINTER_GIVEN);
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    Queue queue = newQueue(spec);
    byte typeSize = getTypeSize(spec);
    for (unsigned int i = 0; i < size; i++)
        enqueueFromPtr(queue, arr + i * typeSize);
    return queue;
}

void enqueueFromPtr(Queue queue, const void *element) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    Node newNode = saferMalloc(sizeof(*newNode));
    byte typeSize = getTypeSize(queue->type);
    newNode->data = saferMalloc(typeSize);
    memcpy(newNode->data, element, typeSize);
    if (queue->tail)
        queue->tail->linked = newNode;
    queue->tail = newNode;
    if (!queue->head)
        queue->head = newNode;
}

byte isQueueEmpty(Queue queue) {
    funcThrowIf(!queue, NULL_STACK_GIVEN);
    return queue->head ? FALSE : TRUE;
}

Queue newQueueFromCharArray(const char arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewQueueFromArray("%c", arr, size);
}

Queue newQueueFromIntArray(const int arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewQueueFromArray("%i", arr, size);
}

Queue newQueueFromFloatArray(const float arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewQueueFromArray("%f", arr, size);
}

Queue newQueueFromDoubleArray(const double arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewQueueFromArray("%lf", arr, size);
}

Queue newQueueFromPtrArray(const void **arr, unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewQueueFromArray("%p", arr, size);
}

byte areQueuesEqual(const Queue queue1, const Queue queue2) {
    funcThrowIf(!queue1 || !queue2, NULL_STACK_GIVEN);
    funcThrowIf(!queue1->type || !queue2->type, NULL_STACK_TYPE);
    if (strcmp(queue1->type, queue2->type) != 0)
        return FALSE;
    Node head1 = queue1->head, head2 = queue2->head;
    byte typeSize = getTypeSize(queue1->type);
    while (head1 && head2) {
        if (memcmp(head1->data, head2->data, typeSize) != 0)
            return FALSE;
        head1 = head1->linked;
        head2 = head2->linked;
    }
    if (head1 == head2)
        return TRUE;
    return FALSE;
}