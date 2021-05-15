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
    throwIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER, __func__);
    ArrayList newArray = saferMalloc(sizeof(arrayList));
    newArray->type = spec;
    newArray->size = 0;
    return newArray;
}

ArrayList newALFromAL(const ArrayList arr) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    ArrayList copy = newAL(copyOf(arr->type));
    copy->size = arr->size;
    copy->type = copyOf(arr->type);
    unsigned int bytesToBeCopied = getTypeSize(arr->type) * arr->size;
    copy->body = saferMalloc(bytesToBeCopied);
    memcpy(copy->body, arr->body, bytesToBeCopied);
    return copy;
}

ArrayList chooseNewALFromArray(const spec_t spec, const void *arr, unsigned int size) {
    throwIf(!arr || !spec, NULL_POINTER_GIVEN, __func__);
    if (strcmp(spec, "%c") == 0)
        return newALFromCharArray(arr, size);
    if (strcmp(spec, "%i") == 0)
        return newALFromIntArray(arr, size);
    if (strcmp(spec, "%f") == 0)
        return newALFromFloatArray(arr, size);
    if (strcmp(spec, "%lf") == 0)
        return newALFromDoubleArray(arr, size);
    if (strcmp(spec, "%p") == 0)
        return newALFromPtrArray(arr, size);
    throwIf(TRUE, UNSUPPORTED_SPECIFIER, __func__);
}

void mergeAL(ArrayList arr1, const ArrayList arr2) {
    throwIf(!arr1 || !arr2, NULL_AL_GIVEN, __func__);
    throwIf(!arr1->type || !arr2->type, NULL_AL_TYPE, __func__);
    throwIf(!arr1->body || !arr2->body, NULL_AL_BODY, __func__);
    throwIf(strcmp(arr1->type, arr2->type) != 0, DIFFERENT_AL_TYPES, __func__);
    byte typeSize = getTypeSize(arr1->type);
    unsigned int bytesToBeCopied = arr2->size * typeSize;
    arr1->body = saferRealloc(arr1->body, (arr1->size + arr2->size) * typeSize);
    memcpy(arr1->body + arr1->size * typeSize, arr2->body, bytesToBeCopied);
    arr1->size = arr1->size + arr2->size;
}

void sliceAL(ArrayList arr, unsigned int begin, unsigned int end) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    throwIf(begin < 0 || end > arr->size, OUT_OF_AL_BOUNDS, __func__);
    throwIf(begin > end, WRONG_INDEX_ORDER, __func__);
    byte typeSize = getTypeSize(arr->type);
    arr->size = end - begin;
    void *newBody = saferMalloc(arr->size * typeSize);
    memcpy(newBody, arr->body + begin * typeSize, arr->size * typeSize);
    free(arr->body);
    arr->body = newBody;
}

void printAL(const spec_t spec, const ArrayList arr) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!spec, NULL_POINTER_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    if (arr->size == 0 || !arr->body) {
        printf("Empty\n");
        return;
    }
    if (strcmp(arr->type, "%c") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((char *)arr->body + i));
    else if (strcmp(arr->type, "%i") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((int *)arr->body + i));
    else if (strcmp(arr->type, "%f") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((float *)arr->body + i));
    else if (strcmp(arr->type, "%lf") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((double *)arr->body + i));
    else if (strcmp(arr->type, "%p") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((int **)arr->body + i));
    else
        throwIf(TRUE, UNSUPPORTED_SPECIFIER, __func__);
}

void removeFromAL(ArrayList arr, unsigned int index) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    throwIf(index >= arr->size, OUT_OF_AL_BOUNDS, __func__);
    if (arr->size == 1) {
        free(arr->body);
        arr->size--;
        return;
    }
    byte typeSize = getTypeSize(arr->type);
    memcpy(arr->body + index * typeSize, arr->body + (index + 1) * typeSize, (arr->size - index) * typeSize);
    arr->body = saferRealloc(arr->body, --arr->size * typeSize);
}

void getFromAL(const ArrayList arr, unsigned int index, void *dest) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    throwIf(!dest, NULL_DESTINATION_GIVEN, __func__);
    throwIf(index >= arr->size, OUT_OF_AL_BOUNDS, __func__);
    byte typeSize = getTypeSize(arr->type);
    memcpy(dest, arr->body + index * typeSize, typeSize);
}

byte areALEqual(const ArrayList arr1, const ArrayList arr2) {
    throwIf(!arr1 || !arr2, NULL_AL_GIVEN, __func__);
    throwIf(!arr1->type || !arr2->type, NULL_AL_TYPE, __func__);
    throwIf(!arr2->body || !arr2->body, NULL_AL_BODY, __func__);
    if (strcmp(arr1->type, arr2->type) != 0 || arr1->size != arr2->size)
        return FALSE;
    byte typeSize = getTypeSize(arr1->type);
    if (memcmp(arr1->body, arr2->body, arr1->size * typeSize) == 0)
        return TRUE;
    return FALSE;
}

void deleteAL(ArrayList arr) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    if(arr->body)
        free(arr->body);
    free(arr);
}

void reverseAL(ArrayList arr) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    byte typeSize = getTypeSize(arr->type);
    void *newBody = saferMalloc(arr->size * typeSize);
    for (unsigned int i = 0; i < arr->size; i++)
        getFromAL(arr, i, newBody + (arr->size - i - 1) * typeSize);
    free(arr->body);
    arr->body = newBody;
}

void bubbleSortAL(ArrayList arr) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    chooseBubbleSortArr(arr->type, arr->body, arr->size);
}

void quickSortAL(ArrayList arr) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    chooseQuickSortArr(arr->type, arr->body, arr->size);
}

void appendToAL(ArrayList arr, ...) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_GIVEN, __func__);
    byte typeSize = getTypeSize(arr->type);
    if (arr->size == 0)
        arr->body = saferMalloc(typeSize);
    else
        arr->body = saferRealloc(arr->body, (arr->size + 1) * typeSize);
    va_list argList;
    va_start(argList, arr);
    VarData data = getData(arr->type, argList);
    memcpy(arr->body + arr->size * typeSize, data, typeSize);
    free(data);
    va_end(argList);
    arr->size++;
}

void insertToAL(ArrayList arr, unsigned int index, ...) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(index >= arr->size, OUT_OF_AL_BOUNDS, __func__);
    byte typeSize = getTypeSize(arr->type);
    void *newBody = saferMalloc((arr->size + 1) * typeSize);
    memcpy(newBody, arr->body, index * typeSize);
    va_list argList;
    va_start(argList, index);
    VarData data = getData(arr->type, argList);
    memcpy(newBody + index * typeSize, data, typeSize);
    memcpy(newBody + (index + 1) * typeSize, arr->body + index * typeSize, (arr->size - index) * typeSize);
    free(arr->body);
    free(data);
    arr->size++;
    arr->body = newBody;
}

void setALItem(ArrayList arr, unsigned int index, ...) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->body, NULL_AL_BODY, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(index >= arr->size, OUT_OF_AL_BOUNDS, __func__);
    byte typeSize = getTypeSize(arr->type);
    va_list argList;
    va_start(argList, index);
    VarData data = getData(arr->type, argList);
    memcpy(arr->body + index * typeSize, data, typeSize);
    free(data);
}

ArrayList newALFromCharArray(const char arr[], unsigned int size) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(arrayList));
    newArray->type = "%c";
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(char);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, arr, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromByteArray(const char arr[], unsigned int size) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    return newALFromCharArray(arr, size);
}

ArrayList newALFromIntArray(const int arr[], unsigned int size) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(arrayList));
    newArray->type = "%i";
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(int);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, arr, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromFloatArray(const float arr[], unsigned int size) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(arrayList));
    newArray->type = "%f";
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(float);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, arr, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromDoubleArray(const double arr[], unsigned int size) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(arrayList));
    newArray->type = "%lf";
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(double);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, arr, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromPtrArray(const void *arr, unsigned int size) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(arrayList));
    newArray->type = "%p";
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(void *);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, arr, bytesToBeCopied);
    return newArray;
}

byte isInAL(ArrayList arr, ...) {
    throwIf(!arr, NULL_AL_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_GIVEN, __func__);
    byte typeSize = getTypeSize(arr->type);
    va_list argList;
    va_start(argList, arr);
    VarData data = getData(arr->type, argList);
    for (unsigned i = 0; i < arr->size; i++) 
        if (memcmp(arr->body + i * typeSize, data, typeSize) == 0) {
            free(data);
            return TRUE;
        }
    free(data);
    return FALSE;
}

int linearSearchAL(ArrayList arr, ...) {
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
    throwIf(!arr->type, NULL_AL_TYPE, __func__);
    throwIf(endsWith(arr->type, "f"), UNSUPPORTED_SPECIFIER, __func__);
    va_list argList;
    va_start(argList, arr);
    VarData key = getData(arr->type, argList);
    va_end(argList);
    int index = chooseLinearSearch(arr->type, arr->body, arr->size, *key);
    free(key);
    return index;
}
