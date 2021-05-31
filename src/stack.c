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

void push(Stack stack, ...) {
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

void pop(Stack stack, void *dest) {
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
        pushFromPtr(stack, arr + i * getTypeSize(spec));
    return stack;
}

void pushFromPtr(Stack stack, const void *element) {
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

unsigned int getStackLength(const Stack stack) {
    funcThrowIf(!stack, NULL_STACK_GIVEN);
    unsigned int length = 0;
    for (Node currNode = stack->head; currNode; currNode = currNode->linked)
        length++;
    return length;
}

Stack newStackFromCharArray(const char arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewStackFromArray("%c", arr, size);
}

Stack newStackFromIntArray(const int arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewStackFromArray("%i", arr, size);
}

Stack newStackFromFloatArray(const float arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewStackFromArray("%f", arr, size);
}

Stack newStackFromDoubleArray(const double arr[], unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewStackFromArray("%lf", arr, size);
}

Stack newStackFromPtrArray(const void **arr, unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseNewStackFromArray("%p", arr, size);
}

byte areStacksEqual(const Stack stack1, const Stack stack2) {
    funcThrowIf(!stack1 || !stack2, NULL_STACK_GIVEN);
    funcThrowIf(!stack1->type || !stack2->type, NULL_STACK_TYPE);
    if (strcmp(stack1->type, stack2->type) != 0)
        return FALSE;
    Node head1 = stack1->head, head2 = stack2->head;
    byte typeSize = getTypeSize(stack1->type);
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