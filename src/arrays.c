#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../arrays.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"
#include "errors.h"
#include "utilityInternal.h"

void chooseQuickSortArr(const spec_t spec, void *arr, int size, ...) {
    //size is not unsigned int beacause qsort requires signed int
    funcThrowIf(!spec || !arr, NULL_POINTER_GIVEN);
    int (*cmpFunc)(const void *a, const void *b);
    if (strcmp("%p", spec) == 0) {
        va_list argList;
        va_start(argList, size);
        cmpFunc = va_arg(argList, void *);
        va_end(argList);
    } else
        cmpFunc = getCmp(spec);
    byte typeSize = getTypeSize(spec);
    qsort(arr, size, typeSize, cmpFunc);
}

void charQuickSortArr(char *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%c", arr, size);
}

void intQuickSortArr(int *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%i", arr, size);
}

void floatQuickSortArr(float *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%f", arr, size);
}

void doubleQuickSortArr(double *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%lf", arr, size);
}

void ptrQuickSortArr(void *arr, int size, int (*cmpFunc)(const void *a, const void *b)) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    qsort(arr, size, sizeof(void *), cmpFunc);
}

void chooseBubbleSortArr(const spec_t spec, void *arr, unsigned int size, ...) {
    funcThrowIf(!arr || !spec, NULL_POINTER_GIVEN);
    char isSorted;
    unsigned int sorted = 0;
    if (strcmp("%p", spec) == 0) {
        va_list argList;
        va_start(argList, size);
        int (*cmpFunc)(const void *a, const void *b) = va_arg(argList, void *);
        va_end(argList);
        return ptrBubbleSortArr(arr, size, cmpFunc);
    }
    if (strcmp("%c", spec) == 0)
        return charBubbleSortArr(arr, size);
    if (strcmp("%i", spec) == 0) 
        return intBubbleSortArr(arr, size);
    if (strcmp("%f", spec) == 0)
        return floatBubbleSortArr(arr, size);
    if (strcmp("%lf", spec) == 0) 
        return doubleBubbleSortArr(arr, size);
    funcThrowIf(TRUE, UNSUPPORTED_SPECIFIER);
}

int chooseLinearSearchArr(const spec_t spec, const void *arr, int size, ...) {
    funcThrowIf(!spec || !arr, NULL_POINTER_GIVEN);
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    va_list argList;
    va_start(argList, size);
    varData key;
    getDataFromArgList(spec, argList, &key);
    if (strcmp(spec, "%p") == 0) {
        int (*cmpFunc)(const void *a, const void *b) = va_arg(argList, void *);
        va_end(argList);
        for (int i = 0; i < size; i++)
            if (cmpFunc(arr + i * sizeof(void *), &key) == EQUAL)
                return i;
    } else {
        va_end(argList);
        byte typeSize = getTypeSize(spec);
        for (int i = 0; i < size; i++)
            if (memcmp(arr + i * typeSize, &key, typeSize) == 0)
                return i;
    }
    return KEY_NOT_FOUND;
}

int charLinearSearchArr(const char* arr, int size, char key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearchArr("%c", arr, size, key);
}

int intLinearSearchArr(const char *arr, int size, int key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearchArr("%i", arr, size, key);
}

int floatLinearSearchArr(const char *arr, int size, float key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearchArr("%f", arr, size, key);
}

int doubleLinearSearchArr(const char *arr, int size, double key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearchArr("%lf", arr, size, key);
}

int ptrLinearSearchArr(const void *arr, int size, void *key, int (*cmpFunc)(const void *a, const void *b)) {
    funcThrowIf(!arr || !key || !cmpFunc, NULL_POINTER_GIVEN);
    for (int i = 0; i < size; i++) {
        if (cmpFunc(arr + i * sizeof(void *), &key) == EQUAL)
            return i;
    }
    return KEY_NOT_FOUND;
}

void printMatrix(const spec_t spec, const void *matrix, const unsigned int nRows, const unsigned int nColumns) {
    funcThrowIf(!spec || !matrix, NULL_POINTER_GIVEN);
    if (endsWith(spec, "hhi"))
        funcThrowIf(TRUE, UNSUPPORTED_SPECIFIER);
    if (endsWith(spec, "hi") || endsWith(spec, "c")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((char *)matrix + i * nColumns + j));
            printf("\n");
        }
        printf("\n");
    } 
    else if (endsWith(spec, "i")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((int *)matrix + i * nColumns + j));
            printf("\n");
        }
        printf("\n");
    } else if (endsWith(spec, "lf")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((double *)matrix + i * nColumns + j));
            printf("\n");
        }
        printf("\n");
    } else if (endsWith(spec, "f")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((float *)matrix + i * nColumns + j));
            printf("\n");
        }
        printf("\n");
    } else if (endsWith(spec, "p")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((byte **)matrix + i * nColumns + j));
            printf("\n");
        }
        printf("\n");
    } else
        funcThrowIf(TRUE, UNSUPPORTED_SPECIFIER);
}

void charBubbleSortArr(char *arr, unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    byte isSorted;
    unsigned int sorted = 0;
    char temp;
    do {
        isSorted = 1;
        int i = -1;
        while (++i < size - 1 - sorted) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                if (isSorted)
                    isSorted = 0;
            }
        }
        sorted++;
    } while (!isSorted);
}

void intBubbleSortArr(int *arr, unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    byte isSorted;
    unsigned int sorted = 0;
    int temp;
    do {
        isSorted = 1;
        int i = -1;
        while (++i < size - 1 - sorted) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                if (isSorted)
                    isSorted = 0;
            }
        }
        sorted++;
    } while (!isSorted);
}

void floatBubbleSortArr(float *arr, unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    byte isSorted;
    unsigned int sorted = 0;
    float temp;
    do {
        isSorted = 1;
        int i = -1;
        while (++i < size - 1 - sorted) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                if (isSorted)
                    isSorted = 0;
            }
        }
        sorted++;
    } while (!isSorted);
}

void doubleBubbleSortArr(double *arr, unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    byte isSorted;
    unsigned int sorted = 0;
    double temp;
    do {
        isSorted = 1;
        int i = -1;
        while (++i < size - 1 - sorted) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                if (isSorted)
                    isSorted = 0;
            }
        }
        sorted++;
    } while (!isSorted);
}

void ptrBubbleSortArr(void **arr, unsigned int size, int (*cmpFunc)(const void *a, const void *b)) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    byte isSorted;
    unsigned int sorted = 0;
    void *temp;
    do {
        isSorted = 1;
        int i = -1;
        while (++i < size - 1 - sorted) {
            if (cmpFunc(arr[i], arr[i + 1]) > 0) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                if (isSorted)
                    isSorted = 0;
            }
        }
        sorted++;
    } while (!isSorted);
}
