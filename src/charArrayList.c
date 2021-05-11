#include "../strings.h"
#include "../types.h"
#include "../utility.h"
#include "errors.h"
#include "utilityInternal.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

ArrayList newALFromCharArray(const char arr[], unsigned int size) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    ArrayList newArray = saferMalloc(sizeof(ArrayList));
    newArray->type = "%c";
    newArray->size = size;
    unsigned int bytesToBeCopied = size * sizeof(char);
    newArray->body = saferMalloc(bytesToBeCopied);
    memcpy(newArray->body, arr, bytesToBeCopied);
    return newArray;
}

ArrayList newALFromByteArray(const char arr[], unsigned int size) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    return newALFromCharArray(arr, size);
}

void appendCharToAL(ArrayList arr, char element) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    if (!arr->type)
        arr->type = "%c";
    if (arr->size == 0)
        arr->body = saferMalloc(sizeof(char));
    else
        arr->body = saferRealloc(arr->body, sizeof(char));
    *((char *)arr->body + arr->size * sizeof(char)) = element;
    arr->size++;
}

void insertCharToAL(ArrayList arr, char element, unsigned int index) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->body, NULL_AL_BODY);
    __checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    void *newBody = saferMalloc(arr->size + 1 * sizeof(char));
    memcpy(newBody, arr->body, index * sizeof(char));
    *((char *)newBody + index * sizeof(char)) = element;
    memcpy(newBody + (index + 1) * sizeof(char), arr->body + index * sizeof(char), (arr->size - index) * sizeof(char));
    arr->size++;
    free(arr->body);
    arr->body = newBody;
}

void setALChar(ArrayList arr, char element, unsigned int index) {
    __checkCondition(!arr, NULL_AL_GIVEN);
    __checkCondition(!arr->body, NULL_AL_BODY);
    __checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    *((char *)arr->body + index * sizeof(char)) = element;
}
