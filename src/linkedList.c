#include "../types.h"
#include "../utility.h"
#include "../constants.h"
#include "utilityInternal.h"
#include "errors.h"
#include <stdarg.h>

LinkedList newLL(const spec_t spec) {
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    LinkedList newList = saferMalloc(sizeof(*newList));
    newList->type = spec;
    newList->size = 0;
    return newList;
}

void printLL(const spec_t spec, const LinkedList list) {
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    funcThrowIf(!list, NULL_LL_GIVEN);
    funcThrowIf(!list->type, NULL_LL_TYPE);
    funcThrowIf(!list->head, NULL_LL_HEAD);
    if (list->size == 0) {
        printf("Empty\n");
        return;
    }
    if (strcmp(list->type, "%c") == 0)
        for (Node currNode = list->head; currNode; currNode = currNode->linked)
            printf(spec, *((char *)(currNode->data)));
    else if (strcmp(list->type, "%i") == 0)
        for (Node currNode = list->head; currNode; currNode = currNode->linked)
            printf(spec, *((int *)(currNode->data)));
    else if (strcmp(list->type, "%f") == 0)
        for (Node currNode = list->head; currNode; currNode = currNode->linked)
            printf(spec, *((float *)(currNode->data)));
    else if (strcmp(list->type, "%lf") == 0)
        for (Node currNode = list->head; currNode; currNode = currNode->linked)
            printf(spec, *((double *)(currNode->data)));
    else if (strcmp(list->type, "%p") == 0)
        for (Node currNode = list->head; currNode; currNode = currNode->linked)
            printf(spec, *((int **)(currNode->data)));
    else
        funcThrowIf(TRUE, UNSUPPORTED_SPECIFIER);
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