#ifndef __SEEN_UTILITY_INTERNAL
#define __SEEN_UTILITY_INTERNAL

#include <stdarg.h>
#include "../types.h"

typedef union {
    char charData;
    int intData;
    float floatData;
    double doubleData;
    void *ptrData;
} * varData;

void *getCmp(const spec_t spec);

byte getTypeSize(const spec_t spec);

void throwIf(const byte condition, const string errorString, const char* funcName);

byte isTypeSupported(const spec_t spec);

varData getData(const spec_t spec, va_list argList);

#endif