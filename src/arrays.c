#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../arrays.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"
#include "errors.h"
#include "utilityInternal.h"

void chooseQuickSortArr(const spec_t spec, void *arr, int size) {
    //size is not unsigned int beacause qsort requires signed int
    funcThrowIf(!spec || !arr, NULL_POINTER_GIVEN);
    size_t typeSize = getTypeSize(spec);
    void *cmpVal = getCmp(spec);
    qsort(arr, size, typeSize, cmpVal);
}

void charQuickSort(char *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%c", arr, size);
}

void intQuickSort(int *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%i", arr, size);
}

void floatQuickSort(float *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%f", arr, size);
}

void doubleQuickSort(double *arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%lf", arr, size);
}

void ptrQuickSort(void **arr, int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    chooseQuickSortArr("%p", arr, size);
}

void chooseBubbleSortArr(const spec_t spec, void *arr, unsigned int size) {
    funcThrowIf(!arr || !spec, NULL_POINTER_GIVEN);
    char isSorted;
    unsigned int sorted = 0;
    if (strcmp("%c", spec) == 0)
        return charBubbleSort(arr, size);
    if (strcmp("%i", spec) == 0) 
        return intBubbleSort(arr, size);
    if (strcmp("%f", spec) == 0)
        return floatBubbleSort(arr, size);
    if (strcmp("%lf", spec) == 0) 
        return doubleBubbleSort(arr, size);
    if (strcmp("%p", spec) == 0) 
        return ptrBubbleSort(arr, size);
    funcThrowIf(TRUE, UNSUPPORTED_SPECIFIER);
}

// TODO Linear searches for all types definition and implementation (just for completeness and macros, chooseLinearSearch is already working)

int chooseLinearSearch(const spec_t spec, void *arr, int size, ...) {
    funcThrowIf(!spec || !arr, NULL_POINTER_GIVEN);
    funcThrowIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER);
    va_list argList;
    va_start(argList, size);
    varData key;
    getDataFromArgList(spec, argList, &key);
    va_end(argList);
    byte typeSize = getTypeSize(spec);
    for (int i = 0; i < size; i++)
        if (memcmp(arr + i * typeSize, &key, typeSize) == 0)
            return i;
    return KEY_NOT_FOUND;
}

int charLinearSearch(const char* arr, int size, char key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearch("%c", arr, size, key);
}

int intLinearSearch(const char *arr, int size, int key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearch("%i", arr, size, key);
}

int floatLinearSearch(const char *arr, int size, float key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearch("%f", arr, size, key);
}

int doubleLinearSearch(const char *arr, int size, double key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearch("%lf", arr, size, key);
}

int ptrLinearSearch(const char **arr, int size, void *key) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    return chooseLinearSearch("%p", arr, size, key);
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

void charBubbleSort(char *arr, unsigned int size) {
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

void intBubbleSort(int *arr, unsigned int size) {
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

void floatBubbleSort(float *arr, unsigned int size) {
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

void doubleBubbleSort(double *arr, unsigned int size) {
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

void ptrBubbleSort(void **arr, unsigned int size) {
    funcThrowIf(!arr, NULL_POINTER_GIVEN);
    byte isSorted;
    unsigned int sorted = 0;
    void *temp;
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
