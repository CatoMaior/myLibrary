#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../types.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"
#include "errors.h"

void checkCondition(byte condition, string errorString) {
    if (condition) {
        printf("\n%s\nExiting\n", errorString);
        exit(1);
    }
}

byte chooseCmp(const spec_t spec, const void *a, const void *b) {
    checkCondition(!spec || !a || !b, NULL_POINTER_GIVEN);
    char (*cmpFun)(const void *a, const void *b) = __getCmp(spec);
    return (*cmpFun)(a, b);
}

void *__getCmp(const spec_t spec) {
    checkCondition(!spec, NULL_POINTER_GIVEN);
    if (strcmp("%c", spec) == 0)
        return charCmp;
    if (strcmp("%i", spec) == 0)
        return intCmp;
    if (strcmp("%f", spec) == 0)
        return floatCmp;
    if (strcmp("%lf", spec) == 0)
        return doubleCmp;
    if (strcmp("%p", spec) == 0)
        return ptrCmp;
    checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
}

byte charCmp(const void *a, const void *b) {
    checkCondition(!a || !b, NULL_POINTER_GIVEN);
    byte diff = *((char *)a) - *((char *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte byteCmp(const void *a, const void *b) {
    checkCondition(!a || !b, NULL_POINTER_GIVEN);
    return charCmp(a, b);
}

byte intCmp(const void *a, const void *b) {
    checkCondition(!a || !b, NULL_POINTER_GIVEN);
    int diff = *((int *)a) - *((int *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte floatCmp(const void *a, const void *b) {
    checkCondition(!a || !b, NULL_POINTER_GIVEN);
    float diff = *((float *)a) - *((float *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte doubleCmp(const void *a, const void *b) {
    checkCondition(!a || !b, NULL_POINTER_GIVEN);
    double diff = *((double *)a) - *((double *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte ptrCmp(const void *a, const void *b) {
    checkCondition(!a || !b, NULL_POINTER_GIVEN);
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
    checkCondition(TRUE, UNSUPPORTED_ARCHITECTURE);
}

void *saferMalloc(unsigned int bytes) {
    byte i = 0;
    void *returnPointer;
    do
        returnPointer = malloc(bytes);
    while (i++ < 10 && returnPointer == NULL);
    checkCondition(!returnPointer, ALLOC_ERROR);
    return returnPointer;
}

void *saferRealloc(void *pointer, unsigned int bytes) {
    checkCondition(!pointer, NULL_POINTER_GIVEN);
    byte i = 0;
    void *returnPointer;
    do
        returnPointer = realloc(pointer, bytes);
    while (i++ < 10 && returnPointer == NULL);
    checkCondition(!returnPointer, REALLOC_ERROR);
    return returnPointer;
}