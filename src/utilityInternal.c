#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utility.h"
#include "../types.h"
#include "../constants.h"
#include "errors.h"

void __checkCondition(byte condition, string errorString) {
    if (condition) {
        printf("\n%s\nExiting\n", errorString);
        exit(1);
    }
}

void *__getCmp(const spec_t spec) {
    __checkCondition(!spec, NULL_POINTER_GIVEN);
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
    __checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
}

byte __getTypeSize(const spec_t spec) {
    __checkCondition(!spec, NULL_POINTER_GIVEN);
    if (strcmp(spec, "%c") == 0)
        return sizeof(char);
    if (strcmp(spec, "%i") == 0)
        return sizeof(int);
    if (strcmp(spec, "%f") == 0)
        return sizeof(float);
    if (strcmp(spec, "%lf") == 0)
        return sizeof(double);
    if (strcmp(spec, "%p") == 0)
        return sizeof(void);
    __checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
}
