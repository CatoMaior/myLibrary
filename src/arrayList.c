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
    ArrayList newArray = saferMalloc(sizeof(*newArray));
    newArray->type = copyOf(spec);
    newArray->size = 0;
    return newArray;
}

ArrayList newALFromAL(const ArrayList list) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(!list->body, NULL_AL_BODY);
    ArrayList copy = newAL(copyOf(list->type));
    copy->size = list->size;
    copy->type = copyOf(list->type);
    unsigned int bytesToBeCopied = getTypeSize(list->type) * list->size;
    copy->body = saferMalloc(bytesToBeCopied);
    memcpy(copy->body, list->body, bytesToBeCopied);
    return copy;
}

ArrayList chooseNewALFromArray(const spec_t spec, const void *list, unsigned int size) {
    funcThrowIf(!list || !spec, NULL_POINTER_GIVEN);
    if (strcmp(spec, "%c") == 0)
        return newALFromCharArray(list, size);
    if (strcmp(spec, "%i") == 0)
        return newALFromIntArray(list, size);
    if (strcmp(spec, "%f") == 0)
        return newALFromFloatArray(list, size);
    if (strcmp(spec, "%lf") == 0)
        return newALFromDoubleArray(list, size);
    if (strcmp(spec, "%p") == 0)
        return newALFromPtrArray(list, size);
    funcThrowIf(TRUE, UNSUPPORTED_SPECIFIER);
}

void mergeAL(ArrayList list1, const ArrayList list2) {
    funcThrowIf(!list1 || !list2, NULL_AL_GIVEN);
    funcThrowIf(!list1->type || !list2->type, NULL_AL_TYPE);
    funcThrowIf(!list1->body || !list2->body, NULL_AL_BODY);
    funcThrowIf(strcmp(list1->type, list2->type) != 0, DIFFERENT_AL_TYPES);
    byte typeSize = getTypeSize(list1->type);
    unsigned int bytesToBeCopied = list2->size * typeSize;
    list1->body = saferRealloc(list1->body, (list1->size + list2->size) * typeSize);
    memcpy(list1->body + list1->size * typeSize, list2->body, bytesToBeCopied);
    list1->size = list1->size + list2->size;
}

void sliceAL(ArrayList list, unsigned int begin, unsigned int end) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(!list->body, NULL_AL_BODY);
    funcThrowIf(begin < 0 || end > list->size, OUT_OF_AL_BOUNDS);
    funcThrowIf(begin > end, WRONG_INDEX_ORDER);
    byte typeSize = getTypeSize(list->type);
    list->size = end - begin;
    void *newBody = saferMalloc(list->size * typeSize);
    memcpy(newBody, list->body + begin * typeSize, list->size * typeSize);
    free(list->body);
    list->body = newBody;
}

void printAL(const spec_t spec, const ArrayList list) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!spec, NULL_POINTER_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    if (list->size == 0 || !list->body) {
        printf("Empty\n");
        return;
    }
    if (strcmp(list->type, "%c") == 0)
        for (unsigned int i = 0; i < list->size; i++)
            printf(spec, *((char *)list->body + i));
    else if (strcmp(list->type, "%i") == 0)
        for (unsigned int i = 0; i < list->size; i++)
            printf(spec, *((int *)list->body + i));
    else if (strcmp(list->type, "%f") == 0)
        for (unsigned int i = 0; i < list->size; i++)
            printf(spec, *((float *)list->body + i));
    else if (strcmp(list->type, "%lf") == 0)
        for (unsigned int i = 0; i < list->size; i++)
            printf(spec, *((double *)list->body + i));
    else if (strcmp(list->type, "%p") == 0)
        for (unsigned int i = 0; i < list->size; i++)
            printf(spec, *((int **)list->body + i));
    else
        funcThrowIf(TRUE, UNSUPPORTED_SPECIFIER);
}

void removeFromAL(ArrayList list, unsigned int index) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(!list->body, NULL_AL_BODY);
    funcThrowIf(index >= list->size, OUT_OF_AL_BOUNDS);
    if (list->size == 1) {
        free(list->body);
        list->size--;
        return;
    }
    byte typeSize = getTypeSize(list->type);
    memcpy(list->body + index * typeSize, list->body + (index + 1) * typeSize, (list->size - index) * typeSize);
    list->body = saferRealloc(list->body, --list->size * typeSize);
}

void getFromAL(const ArrayList list, unsigned int index, void *dest) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(!list->body, NULL_AL_BODY);
    funcThrowIf(!dest, NULL_DESTINATION_GIVEN);
    funcThrowIf(index >= list->size, OUT_OF_AL_BOUNDS);
    byte typeSize = getTypeSize(list->type);
    memcpy(dest, list->body + index * typeSize, typeSize);
}

byte areALEqual(const ArrayList list1, const ArrayList list2, ...) {
    funcThrowIf(!list1 || !list2, NULL_AL_GIVEN);
    funcThrowIf(!list1->type || !list2->type, NULL_AL_TYPE);
    funcThrowIf(!list2->body || !list2->body, NULL_AL_BODY);
    if (strcmp(list1->type, list2->type) != 0 || list1->size != list2->size)
        return FALSE;
    if (strcmp(list1->type, "%p") == 0) {
        va_list argList;
        va_start(argList, list2);
        int (*cmpFunc)(const void *a, const void *b) = va_arg(argList, void *);
        va_end(argList);
        void **body1 = list1->body;
        void **body2 = list2->body;
        for (unsigned int i = 0; i < list1->size; i++)
            if (cmpFunc(body1[i], body2[i]) != EQUAL)
                return FALSE;
    } else {
        byte typeSize = getTypeSize(list1->type);
        if (memcmp(list1->body, list2->body, list1->size * typeSize) != 0)
            return FALSE;
    }
    return TRUE;
}

void deleteAL(ArrayList list, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    if (strcmp(list->type, "%p") == 0) {
        va_list argList;
        va_start(argList, list);
        int (*freeFunc)(void *a) = va_arg(argList, void *);
        va_end(argList);
        void **castedBody = list->body;
        for (unsigned int i = 0; i < list->size; i++) 
            freeFunc(castedBody[i]);
    }
    if (list->body)
        free(list->body);
    free(list->type);
    free(list);
}

void reverseAL(ArrayList list) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(!list->body, NULL_AL_BODY);
    byte typeSize = getTypeSize(list->type);
    void *newBody = saferMalloc(list->size * typeSize);
    for (unsigned int i = 0; i < list->size; i++)
        getFromAL(list, i, newBody + (list->size - i - 1) * typeSize);
    free(list->body);
    list->body = newBody;
}

void bubbleSortAL(ArrayList list, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(!list->body, NULL_AL_BODY);
    int (*cmpFunc)(const void *a, const void *b);
    if (strcmp(list->type, "%p") == 0) {
        va_list argList;
        va_start(argList, list);
        cmpFunc = va_arg(argList, void *);
        va_end(argList);
    } else
        chooseBubbleSortArr(list->type, list->body, list->size, cmpFunc);
}

void quickSortAL(ArrayList list, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(!list->body, NULL_AL_BODY);
    int (*cmpFunc)(const void *a, const void *b);
    if (strcmp(list->type, "%p") == 0) {
        va_list argList;
        va_start(argList, list);
        cmpFunc = va_arg(argList, void *);
        va_end(argList);
    }
    chooseQuickSortArr(list->type, list->body, list->size, cmpFunc);
}

void appendToAL(ArrayList list, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_GIVEN);
    byte typeSize = getTypeSize(list->type);
    if (list->size == 0)
        list->body = saferMalloc(typeSize);
    else
        list->body = saferRealloc(list->body, (list->size + 1) * typeSize);
    va_list argList;
    va_start(argList, list);
    varData data;
    getDataFromArgList(list->type, argList, &data);
    va_end(argList);
    memcpy(list->body + list->size * typeSize, &data, typeSize);
    list->size++;
}

void insertToAL(ArrayList list, unsigned int index, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->body, NULL_AL_BODY);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(index >= list->size, OUT_OF_AL_BOUNDS);
    byte typeSize = getTypeSize(list->type);
    void *newBody = saferMalloc((list->size + 1) * typeSize);
    memcpy(newBody, list->body, index * typeSize);
    va_list argList;
    va_start(argList, index);
    varData data;
    getDataFromArgList(list->type, argList, &data);
    va_end(argList);
    memcpy(newBody + index * typeSize, &data, typeSize);
    memcpy(newBody + (index + 1) * typeSize, list->body + index * typeSize, (list->size - index) * typeSize);
    free(list->body);
    list->size++;
    list->body = newBody;
}

void setALItem(ArrayList list, unsigned int index, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->body, NULL_AL_BODY);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    funcThrowIf(index >= list->size, OUT_OF_AL_BOUNDS);
    byte typeSize = getTypeSize(list->type);
    va_list argList;
    va_start(argList, index);
    varData data;
    getDataFromArgList(list->type, argList, &data);
    va_end(argList);
    memcpy(list->body + index * typeSize, &data, typeSize);
}

ArrayList newALFromCharArray(const char list[], unsigned int size) {
    throwIf(!list, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(*newArray));
    spec_t spec = "%c";
    newArray->type = copyOf(spec);
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(char);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, list, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromByteArray(const char list[], unsigned int size) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    return newALFromCharArray(list, size);
}

ArrayList newALFromIntArray(const int list[], unsigned int size) {
    throwIf(!list, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(*newArray));
    spec_t spec = "%i";
    newArray->type = copyOf(spec);
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(int);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, list, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromFloatArray(const float list[], unsigned int size) {
    throwIf(!list, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(*newArray));
    spec_t spec = "%f";
    newArray->type = copyOf(spec);
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(float);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, list, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromDoubleArray(const double list[], unsigned int size) {
    throwIf(!list, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(*newArray));
    spec_t spec = "%lf";
    newArray->type = copyOf(spec);
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(double);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, list, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromPtrArray(const void *list, unsigned int size) {
    throwIf(!list, NULL_AL_GIVEN, __func__);
    ArrayList newArray = saferMalloc(sizeof(*newArray));
    spec_t spec = "%p";
    newArray->type = copyOf(spec);
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(void *);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, list, bytesToBeCopied);
    return newArray;
}

byte isInAL(ArrayList list, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_GIVEN);
    byte typeSize = getTypeSize(list->type);
    va_list argList;
    va_start(argList, list);
    varData data;
    getDataFromArgList(list->type, argList, &data);
    if (strcmp(list->type, "%p") == 0) {
        int (*cmpFunc)(const void *a, const void *b) = va_arg(argList, void *);
        va_end(argList);
        for (unsigned i = 0; i < list->size; i++)
            if (cmpFunc(&data, list->body + i * typeSize) == 0)
                return TRUE;
        return FALSE;
    }
    va_end(argList);
    for (unsigned i = 0; i < list->size; i++) 
        if (memcmp(list->body + i * typeSize, &data, typeSize) == 0)
            return TRUE;
    return FALSE;
}

int linearSearchAL(ArrayList list, ...) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    funcThrowIf(!list->type, NULL_AL_TYPE);
    va_list argList;
    va_start(argList, list);
    varData key;
    int index;
    int (*cmpFunc)(const void *a, const void *b);
    getDataFromArgList(list->type, argList, &key);
    if (strcmp(list->type, "%p") == 0)
        cmpFunc = va_arg(argList, void *);
    va_end(argList);
    index = chooseLinearSearchArr(list->type, list->body, list->size, key, cmpFunc);
    return index;
}

unsigned int getALLength(const ArrayList list) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    return list->size;
}

byte isALEmpty(ArrayList list) {
    funcThrowIf(!list, NULL_AL_GIVEN);
    return list->size == 0 ? TRUE : FALSE;
}