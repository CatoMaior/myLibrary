#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../arrays.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"
#include "errors.h"

void chooseQuickSort(const spec_t spec, void *arr, int size) {
    //size is not unsigned int beacause qsort requires signed int
    checkCondition(!spec || !arr, NULL_POINTER_GIVEN);
    size_t typeSize;
    if (strcmp("%c", spec) == 0)
        typeSize = sizeof(char);
    else if (strcmp("%i", spec) == 0)
        typeSize = sizeof(int);
    else if (strcmp("%f", spec) == 0)
        typeSize = sizeof(float);
    else if (strcmp("%lf", spec) == 0)
        typeSize = sizeof(double);
    else if (strcmp("%p", spec) == 0)
        typeSize = sizeof(void *);
    else
        checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
    void *cmp = __getCmp(spec);
    qsort(arr, size, typeSize, cmp);
}

void charQuickSort(char *arr, unsigned int size) {
    checkCondition(!arr, NULL_POINTER_GIVEN);
    chooseQuickSort("%c", arr, size);
}

void intQuickSort(int *arr, unsigned int size) {
    checkCondition(!arr, NULL_POINTER_GIVEN);
    chooseQuickSort("%i", arr, size);
}

void floatQuickSort(float *arr, unsigned int size) {
    checkCondition(!arr, NULL_POINTER_GIVEN);
    chooseQuickSort("%f", arr, size);
}

void doubleQuickSort(double *arr, unsigned int size) {
    checkCondition(!arr, NULL_POINTER_GIVEN);
    chooseQuickSort("%lf", arr, size);
}

void ptrQuickSort(void **arr, unsigned int size) {
    checkCondition(!arr, NULL_POINTER_GIVEN);
    chooseQuickSort("%p", arr, size);
}

void chooseBubbleSort(const spec_t spec, void *arr, unsigned int size) {
    checkCondition(!arr || !spec, NULL_POINTER_GIVEN);
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
    checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
}

int linearSearch(const spec_t spec, const void *arr, const void *key, int size) {
    checkCondition((!spec || !arr || !key), NULL_POINTER_GIVEN);
    //int and not unsigned int because KEY_NOT_FOUND is -1
    //key pointer is void in order to be used with pointers of all types
    // TODO use memcmp instead of the abort it uses now
    char typeSize;
    char *castedArrPtr = (char *)arr;
    char *castedKeyPtr = (char *)key;
    if (strcmp("%c", spec) == 0)
        typeSize = sizeof(char);
    else if (strcmp("%i", spec) == 0)
        typeSize = sizeof(int);
    else if (strcmp("%f", spec) == 0)
        typeSize = sizeof(float);
    else if (strcmp("%lf", spec) == 0)
        typeSize = sizeof(double);
    else if (strcmp("%p", spec) == 0)
        typeSize = sizeof(void *);
    else
        checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
    int index;
    char equalUntilNow;
    for (index = 0; index < typeSize * size; index += typeSize) {
        equalUntilNow = 1;
        for (int j = 0; j < typeSize && equalUntilNow; j++) {
            if (*(castedArrPtr + index + j) != *(castedKeyPtr + j)) {
                equalUntilNow = 0;
                continue;
            }
            if (j == typeSize - 1)
                return index / typeSize;
        }
    }
    return KEY_NOT_FOUND;
}

void printMatrix(const spec_t spec, const void *matrix, const unsigned int nRows, const unsigned int nColumns) {
    checkCondition(!spec || !matrix, NULL_POINTER_GIVEN);
    if (endsWith(spec, "hhi"))
        checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
    if (endsWith(spec, "hi")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((char *)(matrix + i * nColumns * sizeof(char) + j * sizeof(char))));
            printf("\n\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "c")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((char *)(matrix + i * nColumns * sizeof(char) + j * sizeof(char))));
            printf("\n\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "i")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((int *)(matrix + i * nColumns * sizeof(int) + j * sizeof(int))));
            printf("\n\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "lf")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((double *)(matrix + i * nColumns * sizeof(double) + j * sizeof(double))));
            printf("\n\n");
        }
        printf("\n");
    }
    else if (endsWith(spec, "f")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((float *)(matrix + i * nColumns * sizeof(float) + j * sizeof(float))));
            printf("\n\n");
        }
        printf("\n");
    }
    else
        checkCondition(TRUE, UNSUPPORTED_SPECIFIER);
}

void charBubbleSort(char *arr, unsigned int size) {
    checkCondition(!arr, NULL_POINTER_GIVEN);
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
    checkCondition(!arr, NULL_POINTER_GIVEN);
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
    checkCondition(!arr, NULL_POINTER_GIVEN);
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
    checkCondition(!arr, NULL_POINTER_GIVEN);
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
    checkCondition(!arr, NULL_POINTER_GIVEN);
    byte isSorted;
    unsigned int sorted = 0;
    int *temp;
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
