#ifndef __SEEN_UTILITY_INTERNAL
#define __SEEN_UTILITY_INTERNAL

#include "../types.h"

typedef union {
    char charData;
    int intData;
    float floatData;
    double doubleData;
    void *ptrData;
} __data;

void *__getCmp(const spec_t spec);

byte __getTypeSize(const spec_t spec);

void __checkCondition(byte condition, string errorString);

#endif