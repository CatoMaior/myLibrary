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
    throwIf(!spec || !arr, NULL_POINTER_GIVEN, __func__);
    size_t typeSize = getTypeSize(spec);
    void *cmpVal = getCmp(spec);
    qsort(arr, size, typeSize, cmpVal);
}

void charQuickSort(char *arr, int size) {
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
    chooseQuickSortArr("%c", arr, size);
}

void intQuickSort(int *arr, int size) {
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
    chooseQuickSortArr("%i", arr, size);
}

void floatQuickSort(float *arr, int size) {
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
    chooseQuickSortArr("%f", arr, size);
}

void doubleQuickSort(double *arr, int size) {
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
    chooseQuickSortArr("%lf", arr, size);
}

void ptrQuickSort(void **arr, int size) {
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
    chooseQuickSortArr("%p", arr, size);
}

void chooseBubbleSortArr(const spec_t spec, void *arr, unsigned int size) {
    throwIf(!arr || !spec, NULL_POINTER_GIVEN, __func__);
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
    throwIf(TRUE, UNSUPPORTED_SPECIFIER, __func__);
}

// TODO Linear searches for all types definition and implementation

int chooseLinearSearch(const spec_t spec, void *arr, int size, ...) {
    throwIf(!spec || !arr, NULL_POINTER_GIVEN, __func__);
    throwIf(!isTypeSupported(spec), UNSUPPORTED_SPECIFIER, __func__);
    va_list argList;
    va_start(argList, size);
    varData key = getData(spec, argList);
    va_end(argList);
    byte typeSize = getTypeSize(spec);
    for (int i = 0; i < size; i++)
        if (memcmp(arr + i * typeSize, key, typeSize) == 0) {
            free(key);
            return i;
        }
    free(key);
    return KEY_NOT_FOUND;
}

void printMatrix(const spec_t spec, const void *matrix, const unsigned int nRows, const unsigned int nColumns) {
    throwIf(!spec || !matrix, NULL_POINTER_GIVEN, __func__);
    if (endsWith(spec, "hhi"))
        throwIf(TRUE, UNSUPPORTED_SPECIFIER, __func__);
    if (endsWith(spec, "hi")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((char *)(matrix + i * nColumns * sizeof(char) + j * sizeof(char))));
            printf("\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "c")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((char *)(matrix + i * nColumns * sizeof(char) + j * sizeof(char))));
            printf("\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "i")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((int *)(matrix + i * nColumns * sizeof(int) + j * sizeof(int))));
            printf("\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "lf")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((double *)(matrix + i * nColumns * sizeof(double) + j * sizeof(double))));
            printf("\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "f")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((float *)(matrix + i * nColumns * sizeof(float) + j * sizeof(float))));
            printf("\n");
        }
        printf("\n");
    }
    else
        throwIf(TRUE, UNSUPPORTED_SPECIFIER, __func__);
}

void charBubbleSort(char *arr, unsigned int size) {
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
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
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
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
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
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
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
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
    throwIf(!arr, NULL_POINTER_GIVEN, __func__);
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
