#include <stdlib.h>
#include <string.h>
#include "../types.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"

void *chooseCmp(const char *id) {
    if (!id)
        return NULL;
    if (strcmp("%c", id) == 0)
        return charCmp;
    if (strcmp("%i", id) == 0)
        return intCmp;
    if (strcmp("%f", id) == 0)
        return floatCmp;
    if (strcmp("%lf", id) == 0)
        return doubleCmp;
    if (strcmp("%p", id) == 0)
        return ptrCmp;
    return NULL;
}

byte charCmp(const void *a, const void *b) {
    if (!a || !b)
        NULL_POINTER_GIVEN;
    byte diff = *((char *)a) - *((char *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte byteCmp(const void *a, const void *b) {
    return charCmp(a, b);
}

byte intCmp(const void *a, const void *b) {
    int diff = *((int *)a) - *((int *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte floatCmp(const void *a, const void *b) {
    float diff = *((float *)a) - *((float *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte doubleCmp(const void *a, const void *b) {
    double diff = *((double *)a) - *((double *)b);
    return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
}

byte ptrCmp(const void *a, const void *b) {
    if (sizeof(void *) == 8) {
        long long int diff = *((unsigned long long *)a) - *((unsigned long long *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    if (sizeof(void *) == 4) {
        unsigned int diff = *((unsigned int *)a) - *((unsigned int *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    if (sizeof(void *) == 2) {
        unsigned short diff = *((unsigned short *)a) - *((unsigned short *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    if (sizeof(void *) == 1) {
        unsigned char diff = *((unsigned char *)a) - *((unsigned char *)b);
        return (diff == 0) ? EQUAL : ((diff > 0) ? GREATER : SMALLER);
    }
    return UNSUPPORTED_ARCHITECTURE;
}

byte trueIfFalse(byte *value) {
    if (!value)
        return NULL_POINTER_GIVEN;
    if (*value == FALSE)
        *value = TRUE;
    return SUCCESS;
}

byte falseIfTrue(byte *value) {
    if (!value)
        return NULL_POINTER_GIVEN;
    if (*value != FALSE)
        *value = FALSE;
    return SUCCESS;
}

void *saferMalloc(unsigned int bytes) {
    byte i = 0;
    void *returnPointer;
    do
        returnPointer = malloc(bytes);
    while (i++ < 10 && returnPointer == NULL);
    return returnPointer;
}

void *saferRealloc(void *pointer, unsigned int bytes) {
    byte i = 0;
    void *returnPointer;
    do
        returnPointer = realloc(pointer, bytes);
    while (i++ < 10 && returnPointer == NULL);
    return returnPointer;
}