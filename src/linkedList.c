#include "../types.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"
#include "utilityInternal.h"
#include "errors.h"
#include <stdarg.h>
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

LinkedList newLL(const spec_t spec) {
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    LinkedList newList = saferMalloc(sizeof(*newList));
    newList->type = copyOf(spec);
    newList->size = 0;
    return newList;
}

void printLL(const spec_t spec, const LinkedList list) {
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    printLinked(spec, list);
}

void appendToLL(LinkedList list, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_GIVEN);
    Node newNode = saferMalloc(sizeof(*newNode));
    byte typeSize = getTypeSize(list->type);
    newNode->data = saferMalloc(typeSize);
    va_list argList;
    va_start(argList, list);
    varData data;
    getDataFromArgList(list->type, argList, &data);
    va_end(argList);
    memcpy(newNode->data, &data, typeSize);
    if (list->size == 0)
        list->head = newNode;
    else
        list->tail->linked = newNode;
    list->tail = newNode;
    list->size++;
}

void appendToLLFromPtr(LinkedList list, const void *element) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_GIVEN);
    Node newNode = saferMalloc(sizeof(*newNode));
    byte typeSize = getTypeSize(list->type);
    newNode->data = saferMalloc(typeSize);
    newNode->linked = NULL;
    memcpy(newNode->data, element, typeSize);
    if (list->size == 0)
        list->head = newNode;
    else
        list->tail->linked = newNode;
    list->tail = newNode;
    list->size++;
}

LinkedList chooseNewLLFromArray(const spec_t spec, const void *arr, unsigned int size) {
    funcThrowIf(!spec || !arr, NULL_POINTER_GIVEN);
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    LinkedList list = newLL(spec);
    for (unsigned int i = 0; i < size; i++)
        appendToLLFromPtr(list, arr + i * getTypeSize(spec));
    return list;
}

void deleteLL(LinkedList list) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    if (list->size != 0) {
        funcThrowIf(!list->head, NULL_LL_HEAD);
        Node linked = list->head->linked;
        for (Node currentNode = list->head; currentNode; currentNode = linked) {
            linked = currentNode->linked;
            free(currentNode->data);
            free(currentNode);
        }
    }
    free(list->type);
    free(list);
}

void insertToLL(LinkedList list, unsigned int index, ...) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(index >= list->size, OUT_OF_LL_BOUNDS);
    Node newNode = saferMalloc(sizeof(*newNode));
    byte typeSize = getTypeSize(list->type);
    newNode->data = saferMalloc(typeSize);
    va_list argList;
    va_start(argList, index);
    varData data;
    getDataFromArgList(list->type, argList, &data);
    va_end(argList);
    memcpy(newNode->data, &data, typeSize);
    list->size++;
    Node currentNode = list->head;
    Node previousNode;
    for (unsigned int i = 0; i < index; i++) {
        previousNode = currentNode;
        currentNode = currentNode->linked;
    }
    newNode->linked = currentNode;
    currentNode = newNode;
    if (index == 0)
        list->head = currentNode;
    else
        previousNode->linked = newNode;
}

void getFromLL(LinkedList list, unsigned int index, void *dest) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(!list->head, NULL_LL_HEAD);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    funcThrowIf(!dest, NULL_DESTINATION_GIVEN);
    funcThrowIf(index >= list->size, OUT_OF_LL_BOUNDS);
    Node srcNode = list->head;
    for (unsigned int i = 0; i < index; i++)
        srcNode = srcNode->linked;
    memcpy(dest, srcNode->data, getTypeSize(list->type));
}

void setLLItem(LinkedList list, unsigned int index, ...) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(!list->head, NULL_LL_HEAD);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(index >= list->size, OUT_OF_LL_BOUNDS);
    va_list argList;
    va_start(argList, index);
    varData data;
    getDataFromArgList(list->type, argList, &data);
    va_end(argList);
    Node currentNode = list->head;
    for (unsigned int i = 0; i < index; i++)
        currentNode = currentNode->linked;
    memcpy(currentNode->data, &data, getTypeSize(list->type));
}

void removeFromLL(LinkedList list, unsigned int index) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(!list->head, NULL_LL_HEAD);
    funcThrowIf(index >= list->size, OUT_OF_LL_BOUNDS);
    Node nodeToDel = list->head;
    Node previous;
    for (unsigned int i = 0; i < index; i++) {
        previous = nodeToDel;
        nodeToDel = nodeToDel->linked;
    }
    if (nodeToDel == list->head)
        list->head = nodeToDel->linked;
    else if (nodeToDel == list->tail) {
        list->tail = previous;
        list->tail->linked = NULL;
    } else
        previous->linked = nodeToDel->linked;
    free(nodeToDel->data);
    free(nodeToDel);
    list->size--;
}

LinkedList newLLFromLL(const LinkedList list) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(!list->head, NULL_LL_HEAD);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    LinkedList copy = newLL(list->type);
    for (Node nodeToCopy = list->head; nodeToCopy; nodeToCopy = nodeToCopy->linked)
        appendToLLFromPtr(copy, nodeToCopy->data);
    return copy;
}

void mergeLL(LinkedList list1, const LinkedList list2) {
    funcThrowIf(!list1 || !list2, NULL_LL_GIVEN);
    funcThrowIf(!list1->head || !list2->head, NULL_LL_HEAD);
    funcThrowIf(!list1->type || !list2->type, NULL_LL_TYPE);
    funcThrowIf(strcmp(list1->type, list2->type) != 0, DIFFERENT_LL_TYPES);
    LinkedList toAppend = newLLFromLL(list2);
    for (Node nodeToCopy = toAppend->head; nodeToCopy; nodeToCopy = nodeToCopy->linked)
        appendToLLFromPtr(list1, nodeToCopy->data);
    deleteLL(toAppend);
}

void sliceLL(LinkedList list, unsigned int begin, unsigned int end) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(!list->head, NULL_LL_HEAD);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    funcThrowIf(begin < 0 || end > list->size, OUT_OF_LL_BOUNDS);
    funcThrowIf(begin > end, WRONG_INDEX_ORDER);
    LinkedList newList = newLL(list->type);
    Node currNode = list->head;
    for (unsigned int i = 0; i < list->size; i++) {
        if (i >= begin && i < end)
            appendToLLFromPtr(newList, currNode->data);
        currNode = currNode->linked;
    }
    if (list->size != 0) {
        funcThrowIf(!list->head, NULL_LL_HEAD);
        Node linked = list->head->linked;
        for (Node currentNode = list->head; currentNode; currentNode = linked) {
            linked = currentNode->linked;
            free(currentNode->data);
            free(currentNode);
        }
    }
    free(list->type);
    list->head = newList->head;
    list->size = end - begin;
    list->tail = newList->tail;
    list->type = newList->type;
}

int linearSearchLL(LinkedList list, ...) {
    funcThrowIf(!list, NULL_POINTER_GIVEN);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    funcThrowIf(endsWith(list->type, "f"), UNSUPPORTED_SPECIFIER);
    va_list argList;
    va_start(argList, list);
    varData key;
    getDataFromArgList(list->type, argList, &key);
    va_end(argList);
    int index;
    Node currNode = list->head;
    byte typeSize = getTypeSize(list->type);
    for (unsigned int i = 0; i < list->size; i++) {
        if (memcmp(currNode->data, &key, typeSize) == 0)
            return i;
        currNode = currNode->linked;
    }
    return KEY_NOT_FOUND;
}

void *linearSearchLLPtr(LinkedList list, ...) {
    funcThrowIf(!list, NULL_POINTER_GIVEN);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    funcThrowIf(endsWith(list->type, "f"), UNSUPPORTED_SPECIFIER);
    va_list argList;
    va_start(argList, list);
    varData key;
    getDataFromArgList(list->type, argList, &key);
    va_end(argList);
    int index;
    Node currNode = list->head;
    byte typeSize = getTypeSize(list->type);
    for (Node currNode = list->head; currNode; currNode = currNode->linked)
        if (memcmp(currNode->data, &key, typeSize) == 0)
            return currNode->data;
    return NULL;
}

byte areLLEqual(const LinkedList list1, const LinkedList list2) {
    funcThrowIf(!list1 || !list2, NULL_LL_GIVEN);
    funcThrowIf(!list1->type || !list2->type, NULL_LL_TYPE);
    funcThrowIf(!list1->head || !list2->head, NULL_LL_HEAD);
    if (strcmp(list1->type, list2->type) != 0 || list1->size != list2->size)
        return FALSE;
    byte typeSize = getTypeSize(list1->type);
    Node currNode1 = list1->head, currNode2 = list2->head;
    for (unsigned i = 0; i < list1->size; i++) {
        if (memcmp(currNode1->data, currNode2->data, typeSize) != 0)
            return FALSE;
        currNode1 = currNode1->linked;
        currNode2 = currNode2->linked;
    }
    return TRUE;
}

byte isInLL(LinkedList list, ...) {
    funcThrowIf(!list, NULL_POINTER_GIVEN);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    funcThrowIf(endsWith(list->type, "f"), UNSUPPORTED_SPECIFIER);
    va_list argList;
    va_start(argList, list);
    varData key;
    getDataFromArgList(list->type, argList, &key);
    va_end(argList);
    Node currNode = list->head;
    byte typeSize = getTypeSize(list->type);
    for (unsigned int i = 0; i < list->size; i++) {
        if (memcmp(currNode->data, &key, typeSize) == 0)
            return TRUE;
        currNode = currNode->linked;
    }
    return FALSE;
}

unsigned int getLLSize(const LinkedList list) {
    funcThrowIf(!list, NULL_LL_GIVEN);
    return list->size;
}