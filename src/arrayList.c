#include "../constants.h"
#include "../strings.h"
#include "../types.h"
#include "../utility.h"
#include "errors.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayList newAL() {
    ArrayList newArray = saferMalloc(sizeof(ArrayList));
    newArray->size = 0;
    return newArray;
}

ArrayList newALFromAL(const ArrayList arr) {
    checkCondition(!arr, NULL_AL_GIVEN);
    ArrayList copy = newAL();
    copy->size = arr->size;
    unsigned int bytesToBeCopied;
    if (strcmp(arr->type, "%c") == 0) {
        copy->type = "%c";
        bytesToBeCopied = arr->size * sizeof(char);
    }
    copy->body = saferRealloc(copy->body, bytesToBeCopied);
    memcpy(copy->body, arr->body, bytesToBeCopied);
    return copy;
}

void mergeAL(ArrayList arr1, const ArrayList arr2) {
    checkCondition(!arr1 || !arr2, NULL_AL_GIVEN);
    checkCondition(!arr1->type || !arr2->type, NULL_AL_TYPE);
    checkCondition(strcmp(arr1->type, arr2->type) != 0, DIFFERENT_AL_TYPES);
    unsigned int bytesToBeCopied;
    byte typeSize;
    if (strcmp(arr1->type, "%c") == 0) {
        typeSize = sizeof(char);
        bytesToBeCopied = arr2->size * sizeof(char);
    }
    arr1->body = saferRealloc(arr1->body, (arr1->size + arr2->size) * typeSize);
    memcpy(arr1->body + arr1->size * typeSize, arr2->body, bytesToBeCopied);
    arr1->size = arr1->size + arr2->size;
}

void sliceAL(ArrayList arr, unsigned int begin, unsigned int end) {
    checkCondition(!arr, NULL_AL_GIVEN);
    checkCondition(!arr->type, NULL_AL_TYPE);
    checkCondition(begin < 0 || end > arr->size, OUT_OF_AL_BOUNDS);
    checkCondition(begin > end, WRONG_INDEX_ORDER);
    byte typeSize;
    void *newBody;
    if (strcmp(arr->type, "%c") == 0)
        typeSize = sizeof(char);
    arr->size = abs(end - begin);
    newBody = saferMalloc(arr->size * typeSize);
    memcpy(newBody, arr->body + begin * typeSize, arr->size * typeSize);
    free(arr->body);
    arr->body = newBody;
}

void printAL(const spec_t spec, const ArrayList arr) {
    checkCondition(!arr, NULL_AL_GIVEN);
    checkCondition(!spec, NULL_POINTER_GIVEN);
    checkCondition(!arr->type, NULL_AL_TYPE);
    if (arr->size == 0) {
        printf("Empty\n");
        return;
    }
    if (strcmp(arr->type, "%c") == 0)
        for (unsigned int i = 0; i < arr->size; i++)
            printf(spec, *((char *)arr->body + i * sizeof(char)));
}

void removeFromAL(ArrayList arr, unsigned int index) {
    checkCondition(!arr, NULL_AL_GIVEN);
    checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    if (arr->size == 1) {
        free(arr->body);
        arr->size--;
        return;
    }
    byte typeSize;
    if (strcmp(arr->type, "%c") == 0)
        typeSize = sizeof(char);
    memcpy(arr->body + index * typeSize, arr->body + (index + 1) * typeSize, (arr->size - index) * typeSize);
    arr->body = saferRealloc(arr->body, --arr->size * typeSize);
}

void getFromAL(const ArrayList arr, unsigned int index, void *dest) {
    checkCondition(!arr, NULL_AL_GIVEN);
    checkCondition(!dest, NULL_DESTINATION_GIVEN);
    checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    if (strcmp(arr->type, "%c") == 0)
        *(char *)dest = *((char *)arr->body + index * sizeof(char));
}

byte areALEqual(ArrayList arr1, ArrayList arr2) {
    checkCondition(!arr1 || !arr2, NULL_AL_GIVEN);
    if (strcmp(arr1->type, arr2->type) != 0 || arr1->size != arr2->size)
        return FALSE;
    byte typeSize;
    if (strcmp(arr1->type, "%c") == 0)
        typeSize = sizeof(char);
    if (memcmp(arr1->body, arr2->body, arr1->size * typeSize) == 0)
        return TRUE;
    return FALSE;
}

void appendCharToAL(ArrayList arr, char element) {
    checkCondition(!arr, NULL_AL_GIVEN);
    if (!arr->type)
        arr->type = "%c";
    if (arr->size == 0)
        arr->body = saferMalloc(sizeof(char));
    else
        arr->body = saferRealloc(arr->body, sizeof(char));
    *((char *)arr->body + arr->size * sizeof(char)) = element;
    arr->size++;
}

ArrayList newALFromCharArray(const char arr[], unsigned int size) {
    checkCondition(!arr, NULL_AL_GIVEN);
    ArrayList newArray = saferMalloc(sizeof(ArrayList));
    newArray->type = "%c";
    newArray->size = 0;
    for (unsigned int i = 0; i < size; i++)
        appendCharToAL(newArray, arr[i]);
    return newArray;
}

void deleteAL(ArrayList arr) {
    checkCondition(!arr, NULL_AL_GIVEN);
    free(arr->body);
    free(arr);
}

void insertCharToAL(ArrayList arr, char element, unsigned int index) {
    checkCondition(!arr, NULL_AL_GIVEN);
    checkCondition(!arr->type, NULL_AL_TYPE);
    checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    void *newBody = saferMalloc(arr->size + 1 * sizeof(char));
    memcpy(newBody, arr->body, index * sizeof(char));
    *((char *)newBody + index * sizeof(char)) = element;
    memcpy(newBody + (index + 1) * sizeof(char), arr->body + index * sizeof(char), (arr->size - index) * sizeof(char));
    arr->size++;
    free(arr->body);
    arr->body = newBody;
}

void setALChar(ArrayList arr, char element, unsigned int index) {
    checkCondition(!arr, NULL_AL_GIVEN);
    checkCondition(index >= arr->size, OUT_OF_AL_BOUNDS);
    *((char *)arr->body + index * sizeof(char)) = element;
}

void reverseAL(ArrayList arr) {
    checkCondition(!arr, NULL_AL_GIVEN);
    void *newBody;
    if (strcmp(arr->type, "%c") == 0) {
        newBody = saferMalloc(arr->size * sizeof(char));
        char temp;
        for (unsigned int i = 0; i < arr->size; i++)
            getFromAL(arr, i, newBody + (arr->size - i - 1) * sizeof(char));
    }
    free(arr->body);
    arr->body = newBody;
}

ArrayList newALFromByteArray(const char arr[], unsigned int size) {
    return newALFromCharArray(arr, size);
}
