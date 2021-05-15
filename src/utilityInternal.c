#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../utility.h"
#include "../types.h"
#include "../constants.h"
#include "errors.h"
#include "utilityInternal.h"

void throwIf(const byte condition, const string errorString, const char* funcName) {
    if (condition) {
        printf("\n%s in function %s.\nExiting\n", errorString, funcName);
        exit(1);
    }
}

void *getCmp(const spec_t spec) {
    throwIf(!spec, NULL_POINTER_GIVEN, __func__);
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
    throwIf(TRUE, UNSUPPORTED_SPECIFIER, __func__);
}

byte getTypeSize(const spec_t spec) {
    throwIf(!spec, NULL_POINTER_GIVEN, __func__);
    if (strcmp(spec, "%c") == 0)
        return sizeof(char);
    if (strcmp(spec, "%i") == 0)
        return sizeof(int);
    if (strcmp(spec, "%f") == 0)
        return sizeof(float);
    if (strcmp(spec, "%lf") == 0)
        return sizeof(double);
    if (strcmp(spec, "%p") == 0)
        return sizeof(void *);
    throwIf(TRUE, UNSUPPORTED_SPECIFIER, __func__);
}

byte isTypeSupported(const spec_t spec) {
    spec_t knownSpecs[] = {"%c", "%i", "%f", "%lf", "%p"};
    for (byte i = 0; i < 5; i++) 
        if (strcmp(spec, knownSpecs[i]) == 0)
            return TRUE;
    return FALSE;
}

varData getData(const spec_t spec, va_list argList) {
    throwIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER, __func__);
    varData data = saferMalloc(sizeof(varData));
    if (strcmp(spec, "%c") == 0)
        data->charData = va_arg(argList, int);
    else if (strcmp(spec, "%i") == 0)
        data->intData = va_arg(argList, int);
    else if (strcmp(spec, "%f") == 0)
        data->floatData = va_arg(argList, double);
    else if (strcmp(spec, "%lf") == 0)
        data->doubleData = va_arg(argList, double);
    else if (strcmp(spec, "%p") == 0)
        data->ptrData = va_arg(argList, void *);
    return data;
}
