#ifndef SEEN_UTILITY_INTERNAL
#define SEEN_UTILITY_INTERNAL

#include <stdarg.h>
#include "../types.h"

#define funcThrowIf(condition, errorString) throwIf(condition, errorString, __func__)

typedef union {
    char charData;
    int intData;
    float floatData;
    double doubleData;
    void *ptrData;
} varData;

typedef varData *VarData;

void *getCmp(const spec_t spec);

byte getTypeSize(const spec_t spec);

void throwIf(const byte condition, const string errorString, const char* funcName);

byte isTypeSupported(const spec_t spec);

void getDataFromArgList(const spec_t spec, va_list argList, VarData data);

void printLinked(const spec_t spec, void *linkedEl);

unsigned int getLinkedSize(const void *linkedEl);

#endif