#include "../constants.h"
#include "../strings.h"
#include "../types.h"
#include "../utility.h"
#include "../arrayList.h"
#include "../arrays.h"
#include "errors.h"
#include "utilityInternal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

ArrayList newAL(const spec_t spec) {
    ArrayList newArray = saferMalloc(sizeof(ArrayList));
    newArray->type = spec;
    newArray->size = 0;
    return newArray;
}

ArrayList newALFromAL(const ArrayList arr) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    __checkCondition(!arr->body, NULL_AL_BODY);
    ArrayList copy = newAL(copyOf(arr->type));
    copy->size = arr->size;
    copy->type = copyOf(arr->type);
    unsigned int bytesToBeCopied = __getTypeSize(arr->type) * arr->size;
    copy->body = saferMalloc(bytesToBeCopied);
    memcpy(copy->body, arr->body, bytesToBeCopied);
    return copy;
}

ArrayList chooseNewALFromArray(const spec_t spec, const void *arr, unsigned int size) {
    __checkCondition(!arr || !spec, NULL_POINTER_GIVEN);
    if (strcmp(spec, "%c") == 0)
        return newALFromCharArray(arr, size);
    __checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
}

void mergeAL(ArrayList arr1, const ArrayList arr2) {
    __checkCondition(!arr1 || !arr2, NULL_AL_GIVEN);
    __checkCondition(!arr1->type || !arr2->type, NULL_AL_TYPE);
    __checkCondition(!arr1->body || !arr2->body, NULL_AL_BODY);
    __checkCondition(strcmp(arr1->type, arr2->type) != 0, DIFFERENT_AL_TYPES);
    byte typeSize = __getTypeSize(arr1->type);
    unsigned int bytesToBeCopied = arr2->size * typeSize;
    arr1->body = saferRealloc(arr1->body, (arr1->size + arr2->size) * typeSize);
    memcpy(arr1->body + arr1->size * typeSize, arr2->body, bytesToBeCopied);
    arr1->size = arr1->size + arr2->size;
}

void sliceAL(ArrayList arr, unsigned int begin, unsigned int end) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    __checkCondition(!arr->body, NULL_AL_BODY);
    __checkCondition(begin < 0 || end > arr->size, OUT_OF_AL_BOUNDS);
    __checkCondition(begin > end, WRONG_INDEX_ORDER);
    byte typeSize;
    void *newBody;
    if (strcmp(arr->type, "%c") == 0)
        typeSize = sizeof(char);
    arr->size = end - begin;
    newBody = saferMalloc(arr->size * typeSize);
    memcpy(newBody, arr->body + begin * typeSize, arr->size * typeSize);
    free(arr->body);
    arr->body = newBody;
}

void printAL(const spec_t spec, const ArrayList arr) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!spec, NULL_POINTER_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    if (arr->size == 0 || !arr->body) {
        printf("Empty\n");
        return;
    }
    if (strcmp(arr->type, "%c") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((char *)arr->body + i * sizeof(char)));
    else if (strcmp(arr->type, "%i") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((int *)arr->body + i * sizeof(int)));
    else if (strcmp(arr->type, "%f") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((float *)arr->body + i * sizeof(float)));
    else if (strcmp(arr->type, "%lf") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((double *)arr->body + i * sizeof(double)));
    else if (strcmp(arr->type, "%p") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((int *)arr->body + i * sizeof(int *)));
    else
        __checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
}

void removeFromAL(ArrayList arr, unsigned int index) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    __checkCondition(!arr->body, NULL_AL_BODY);
    __checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    if (arr->size == 1) {
        free(arr->body);
        arr->size--;
        return;
    }
    byte typeSize = __getTypeSize(arr->type);
    memcpy(arr->body + index * typeSize, arr->body + (index + 1) * typeSize, (arr->size - index) * typeSize);
    arr->body = saferRealloc(arr->body, --arr->size * typeSize);
}

void getFromAL(const ArrayList arr, unsigned int index, void *dest) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    __checkCondition(!arr->body, NULL_AL_BODY);
    __checkCondition(!dest, NULL_DESTINATION_GIVEN);
    __checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    byte typeSize = __getTypeSize(arr->type);
    memcpy(dest, arr->body + index * typeSize, typeSize);
}

byte areALEqual(ArrayList arr1, ArrayList arr2) {
    __checkCondition(!arr1 || !arr2, NULL_AL_GIVEN);
    __checkCondition(!arr1->type || !arr2->type, NULL_AL_TYPE);
    __checkCondition(!arr2->body || !arr2->body, NULL_AL_BODY);
    if (strcmp(arr1->type, arr2->type) != 0 || arr1->size != arr2->size)
        return FALSE;
    byte typeSize = __getTypeSize(arr1->type);
    if (memcmp(arr1->body, arr2->body, arr1->size * typeSize) == 0)
        return TRUE;
    return FALSE;
}

void deleteAL(ArrayList arr) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    if(arr->body)
        free(arr->body);
    free(arr);
}

void reverseAL(ArrayList arr) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    __checkCondition(!arr->body, NULL_AL_BODY);
    byte typeSize = __getTypeSize(arr->type);
    void *newBody = saferMalloc(arr->size * typeSize);
    for (unsigned int i = 0; i < arr->size; i++)
        getFromAL(arr, i, newBody + (arr->size - i - 1) * typeSize);
    free(arr->body);
    arr->body = newBody;
}

void bubbleSortAL(ArrayList arr) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    __checkCondition(!arr->body, NULL_AL_BODY);
    chooseBubbleSortArr(arr->type, arr->body, __getTypeSize(arr->type) * arr->size);
}

void quickSortAL(ArrayList arr) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_TYPE);
    __checkCondition(!arr->body, NULL_AL_BODY);
    chooseQuickSortArr(arr->type, arr->body, __getTypeSize(arr->type) * arr->size);
}

void appendToAL(ArrayList arr, ...) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->type, NULL_AL_GIVEN);
    byte typeSize = __getTypeSize(arr->type);
    if (arr->size == 0)
        arr->body = saferMalloc(typeSize);
    else
        arr->body = saferRealloc(arr->body, typeSize);
    va_list argList;
    va_start(argList, arr);
    void *address;
    if (strcmp(arr->type, "%c") == 0) {
        char element = va_arg(argList, int);
        address = &element;
    }
    else if (strcmp(arr->type, "%i") == 0) {
        int element = va_arg(argList, int);
        address = &element;
    }
    else if (strcmp(arr->type, "%f") == 0) {
        float element = va_arg(argList, double);
        address = &element;
    }
    else if (strcmp(arr->type, "%lf") == 0) {
        double element = va_arg(argList, double);
        address = &element;
    }
    else if (strcmp(arr->type, "%p") == 0) {
        void *element = va_arg(argList, void *);
        address = &element;
    }
    memcpy(arr->body + arr->size * typeSize, address, typeSize);
    va_end(argList);
    arr->size++;
}