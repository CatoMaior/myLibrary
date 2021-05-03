#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../arrays.h"
#include "../utility.h"
#include "../constants.h"
#include "../strings.h"

byte quickSort(const spec_t spec, void *arr, int size) {
    //size not unsigned int beacause qsort requires signed int
    if (!spec || !arr)
        return NULL_POINTER_GIVEN;
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
        return UNKNOWN_SPEC;
    void *cmp = chooseCmp(spec);
    qsort(arr, size, typeSize, cmp);
    return SUCCESS;
}

byte bubbleSort(const spec_t spec, void *arr, unsigned int size) {
    if (!arr || !spec)
        return NULL_POINTER_GIVEN;
    char isSorted;
    unsigned int sorted = 0;
    if (strcmp("%c", spec) == 0) {
        char temp;
        char *castedArr = arr;
        do {
            isSorted = 1;
            int i = -1;
            while (++i < size - 1 - sorted) {
                if (castedArr[i] > castedArr[i + 1]) {
                    temp = castedArr[i + 1];
                    castedArr[i + 1] = castedArr[i];
                    castedArr[i] = temp;
                    if (isSorted)
                        isSorted = 0;
                }
            }
            sorted++;
        } while (!isSorted);
        return SUCCESS;
    }
    if (strcmp("%i", spec) == 0) {
        int temp;
        int *castedArr = arr;
        do {
            isSorted = 1;
            int i = -1;
            while (++i < size - 1 - sorted) {
                if (castedArr[i] > castedArr[i + 1]) {
                    temp = castedArr[i + 1];
                    castedArr[i + 1] = castedArr[i];
                    castedArr[i] = temp;
                    if (isSorted)
                        isSorted = 0;
                }
            }
            sorted++;
        } while (!isSorted);
        return SUCCESS;
    }
    if (strcmp("%f", spec) == 0) {
        float temp;
        float *castedArr = arr;
        do {
            isSorted = 1;
            int i = -1;
            while (++i < size - 1 - sorted) {
                if (castedArr[i] > castedArr[i + 1]) {
                    temp = castedArr[i + 1];
                    castedArr[i + 1] = castedArr[i];
                    castedArr[i] = temp;
                    if (isSorted)
                        isSorted = 0;
                }
            }
            sorted++;
        } while (!isSorted);
        return SUCCESS;
    }
    if (strcmp("%lf", spec) == 0) {
        double temp;
        double *castedArr = arr;
        do {
            isSorted = 1;
            int i = -1;
            while (++i < size - 1 - sorted) {
                if (castedArr[i] > castedArr[i + 1]) {
                    temp = castedArr[i + 1];
                    castedArr[i + 1] = castedArr[i];
                    castedArr[i] = temp;
                    if (isSorted)
                        isSorted = 0;
                }
            }
            sorted++;
        } while (!isSorted);
        return SUCCESS;
    }
    if (strcmp("%p", spec) == 0) {
        void *temp;
        void **castedArr = arr;
        do {
            isSorted = 1;
            int i = -1;
            while (++i < size - 1 - sorted) {
                if (castedArr[i] > castedArr[i + 1]) {
                    temp = castedArr[i + 1];
                    castedArr[i + 1] = castedArr[i];
                    castedArr[i] = temp;
                    if (isSorted)
                        isSorted = 0;
                }
            }
            sorted++;
        } while (!isSorted);
        return SUCCESS;
    }
    return UNKNOWN_SPEC;
}

int linearSearch(const spec_t spec, const void *arr, const void *key, int size) {
    if (!spec || !arr || !key)
        return NULL_POINTER_GIVEN;
    //int and not unsigned int because KEY_NOT_FOUND is -1
    //key pointer is void in order to be used with pointers of all types
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
        return UNKNOWN_SPEC;
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

byte printMatrix(const spec_t spec, const void *matrix, const unsigned int nRows, const unsigned int nColumns) {
    if (!spec || !matrix)
        return NULL_POINTER_GIVEN;
    if (endsWith(spec, "hhi"))
        return UNKNOWN_SPEC;
    if (endsWith(spec, "hi")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((char *)(matrix + i * nColumns * sizeof(char) + j * sizeof(char))));
            printf("\n\n");
        }
        printf("\n");
        return SUCCESS;
    }
    if (endsWith(spec, "c")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((char *)(matrix + i * nColumns * sizeof(char) + j * sizeof(char))));
            printf("\n\n");
        }
        printf("\n");
        return SUCCESS;
    }
    if (endsWith(spec, "i")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((int *)(matrix + i * nColumns * sizeof(int) + j * sizeof(int))));
            printf("\n\n");
        }
        printf("\n");
        return SUCCESS;
    }
    if (endsWith(spec, "lf")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((double *)(matrix + i * nColumns * sizeof(double) + j * sizeof(double))));
            printf("\n\n");
        }
        printf("\n");
        return SUCCESS;
    }
    if (endsWith(spec, "f")) {
        for (unsigned int i = 0; i < nRows; i++) {
            for (unsigned int j = 0; j < nColumns; j++)
                printf(spec, *((float *)(matrix + i * nColumns * sizeof(float) + j * sizeof(float))));
            printf("\n\n");
        }
        printf("\n");
        return SUCCESS;
    }
    return UNKNOWN_SPEC;
}