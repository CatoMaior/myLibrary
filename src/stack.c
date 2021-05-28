#include "../types.h"
#include "../utility.h"
#include "../strings.h"
#include "../constants.h"
#include "utilityInternal.h"
#include "errors.h"
#include <stdarg.h>
#include <string.h>

Stack newStack(const spec_t spec) {
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    Stack stack = saferMalloc(sizeof(*stack));
    stack->type = copyOf(spec);
    return stack;
}

void printStack(const spec_t spec, const Stack stack) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    funcThrowIf(!stack->type, NULL_STACK_TYPE);
    printLinked(spec, stack);
}

void pushToStack(Stack stack, ...) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    funcThrowIf(!stack->type, NULL_STACK_TYPE);
    Node newNode = saferMalloc(sizeof(*newNode));
    byte typeSize = getTypeSize(stack->type);
    newNode->data = saferMalloc(typeSize);
    va_list argList;
    va_start(argList, stack);
    varData data;
    getDataFromArgList(stack->type, argList, &data);
    va_end(argList);
    memcpy(newNode->data, &data, typeSize);
    Node prevHead = stack->head;
    newNode->linked = prevHead;
    stack->head = newNode;
}

void getHeadDataFromStack(Stack stack, void *dest) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    funcThrowIf(!stack->type, NULL_STACK_TYPE);
    funcThrowIf(!stack->head, NULL_STACK_HEAD);
    memcpy(dest, stack->head->data, getTypeSize(stack->type));
}

void popFromStack(Stack stack, void *dest) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    funcThrowIf(!stack->type, NULL_STACK_TYPE);
    funcThrowIf(!stack->head, NULL_STACK_HEAD);
    getHeadDataFromStack(stack, dest);
    deleteHeadFromStack(stack);
}

void deleteHeadFromStack(Stack stack) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    funcThrowIf(!stack->type, NULL_STACK_TYPE);
    funcThrowIf(!stack->head, NULL_STACK_HEAD);
    Node newHead = stack->head->linked;
    free(stack->head->data);
    free(stack->head);
    stack->head = newHead;
}

byte isStackEmpty(Stack stack) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    return stack->head ? FALSE : TRUE;
}

void deleteStack(Stack stack) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    while (!isStackEmpty(stack))
        deleteHeadFromStack(stack);
    free(stack->type);
    free(stack);
}

byte isInStack(Stack stack, ...) {
    funcThrowIf(!stack, NULL_POINTER_GIVEN);
    funcThrowIf(!stack->type, NULL_STACK_TYPE);
    funcThrowIf(endsWith(stack->type, "f"), UNSUPPORTED_SPECIFIER);
    va_list argList;
    va_start(argList, stack);
    varData key;
    getDataFromArgList(stack->type, argList, &key);
    va_end(argList);
    byte typeSize = getTypeSize(stack->type);
    for (Node currNode = stack->head; currNode; currNode = currNode->linked)
        if (memcmp(currNode->data, &key, typeSize) == 0)
            return TRUE;
    return FALSE;
}

Stack chooseNewStackFromArray(const spec_t spec, const void *arr, unsigned int size) {
    funcThrowIf(!spec || !arr, NULL_POINTER_GIVEN);
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    Stack stack = newStack(spec);
    for (unsigned int i = 0; i < size; i++)
        pushToStackFromPtr(stack, arr + i * getTypeSize(spec));
    return stack;
}

void pushToStackFromPtr(Stack stack, const void *element) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    funcThrowIf(!stack->type, NULL_STACK_TYPE);
    Node newNode = saferMalloc(sizeof(*newNode));
    byte typeSize = getTypeSize(stack->type);
    newNode->data = saferMalloc(typeSize);
    memcpy(newNode->data, element, typeSize);
    Node prevHead = stack->head;
    newNode->linked = prevHead;
    stack->head = newNode;
}

unsigned int getStackSize(const Stack stack) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    unsigned int length = 0;
    for (Node currNode = stack->head; currNode; currNode = currNode->linked)
        length++;
    return length;
}