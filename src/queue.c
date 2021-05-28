#include "../constants.h"
#include "../strings.h"
#include "../types.h"
#include "../utility.h"
#include "errors.h"
#include "utilityInternal.h"
#include <stdarg.h>
#include <string.h>

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

void dequeue(Queue queue, void *dest) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    funcThrowIf(!queue->head, NULL_QUEUE_HEAD);
    getHeadDataFromQueue(queue, dest);
    deleteHeadFromQueue(queue);
}

void getHeadDataFromQueue(const Queue queue, void *dest) {
    funcThrowIf(!queue, NULL_QUEUE_GIVEN);
    funcThrowIf(!queue->type, NULL_QUEUE_TYPE);
    funcThrowIf(!queue->head, NULL_QUEUE_HEAD);
    memcpy(dest, queue->head->data, getTypeSize(queue->type));
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