#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../types.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"
#include "errors.h"
#include "utilityInternal.h"

byte chooseCmp(const spec_t spec, const void *a, const void *b) {
    throwIf(!spec || !a || !b, NULL_POINTER_GIVEN, __func__);
    char (*cmpFun)(const void *a, const void *b) = getCmp(spec);
    return (*cmpFun)(a, b);
}

byte charCmp(const void *a, const void *b) {
    throwIf(!a || !b, NULL_POINTER_GIVEN, __func__);
    byte diff = *((char *)a) - *((char *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte byteCmp(const void *a, const void *b) {
    throwIf(!a || !b, NULL_POINTER_GIVEN, __func__);
    return charCmp(a, b);
}

byte intCmp(const void *a, const void *b) {
    throwIf(!a || !b, NULL_POINTER_GIVEN, __func__);
    int diff = *((int *)a) - *((int *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte floatCmp(const void *a, const void *b) {
    throwIf(!a || !b, NULL_POINTER_GIVEN, __func__);
    float diff = *((float *)a) - *((float *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte doubleCmp(const void *a, const void *b) {
    throwIf(!a || !b, NULL_POINTER_GIVEN, __func__);
    double diff = *((double *)a) - *((double *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte ptrCmp(const void *a, const void *b) {
    throwIf(!a || !b, NULL_POINTER_GIVEN, __func__);
    if (sizeof(void *) == 8) {
        long long int diff = *((unsigned long long *)a) - *((unsigned long long *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    if (sizeof(void *) == 4) {
        int diff = *((unsigned int *)a) - *((unsigned int *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    if (sizeof(void *) == 2) {
        short diff = *((unsigned short *)a) - *((unsigned short *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    if (sizeof(void *) == 1) {
        char diff = *((unsigned char *)a) - *((unsigned char *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    throwIf(TRUE, UNSUPPORTED_ARCHITECTURE, __func__);
}

void *saferMalloc(unsigned int bytes) {
    byte i = 0;
    void *returnPointer;
    do
        returnPointer = malloc(bytes);
    while (i++ < 10 && returnPointer == NULL);
    throwIf(!returnPointer, ALLOC_ERROR, __func__);
    return returnPointer;
}

void *saferRealloc(void *pointer, unsigned int bytes) {
    throwIf(!pointer, NULL_POINTER_GIVEN, __func__);
    byte i = 0;
    void *returnPointer;
    do
        returnPointer = realloc(pointer, bytes);
    while (i++ < 10 && returnPointer == NULL);
    throwIf(!returnPointer, REALLOC_ERROR, __func__);
    return returnPointer;
}