#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"

// #define SKIP_UTILITY
// #define SKIP_STRING
// #define SKIP_ARRAY

int main() {

#ifndef SKIP_UTILITY
    byte bytes[2] = {-1, 1};
    char chars[] = {'A', 'a'};
    int ints[] = {-128, 128};
    float floats[] = {-1.1, 1.1};
    double doubles[] = {-1.2, 1.2};
    void *ptrs[2];
    for (int i = 0; i < 2; i++)
        ptrs[i] = saferMalloc(sizeof(char));

    byte (*cmpFunc)(const void *a, const void *b);

    cmpFunc = getCmp("%c");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", (*cmpFunc)(&bytes[i], &bytes[j]));
    printf("\n");
    cmpFunc = getCmp("%c");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", (*cmpFunc)(&chars[i], &chars[j]));
    printf("\n");
    cmpFunc = getCmp("%i");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", (*cmpFunc)(&ints[i], &ints[j]));
    printf("\n");
    cmpFunc = getCmp("%f");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", (*cmpFunc)(&floats[i], &floats[j]));
    printf("\n");
    cmpFunc = getCmp("%lf");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", (*cmpFunc)(&doubles[i], &doubles[j]));
    printf("\n");
    cmpFunc = getCmp("%p");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", (*cmpFunc)(&ptrs[i], &ptrs[j]));
    printf("\n");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", chooseCmp("%c", &bytes[i], &bytes[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", chooseCmp("%c", &chars[i], &chars[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", chooseCmp("%i", &ints[i], &ints[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", chooseCmp("%f", &floats[i], &floats[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", chooseCmp("%lf", &doubles[i], &doubles[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", chooseCmp("%p", &ptrs[i], &ptrs[j]));
    printf("\n");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmp(bytes[i], bytes[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmp(chars[i], chars[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmp(ints[i], ints[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmp(floats[i], floats[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmp(doubles[i], doubles[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmp(ptrs[i], ptrs[j]));
    printf("\n");

    printf("\n\n");
    for (int i = 0; i < 2; i++)
        free(ptrs[i]);
#endif

#ifndef SKIP_STRING
    printf("Insert string: ");
    string myString = getString();
    printf("String: %s\n", myString);
    myString = changeLastCharacter(myString, 'X');
    printf("Changed string: %s\n", myString);
    printf("Changed string length: %i\n", getLength(myString));
    myString = changeLastCharacter(myString, '\0');
    printf("Shrinked string: %s\n", myString);
    printf("Shrinked string length: %i\n", getLength(myString));
    printf("\n\n");
#endif

#ifndef SKIP_ARRAY
    byte byteMatrix[][8] = {
        {32, 43, 65, 12, 76, 75, 1, 2},
        {32, 43, 65, 12, 76, 75, 1, 2}};
    char charMatrix[][8] = {
        {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'},
        {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'}};
    int intMatrix[][8] = {
        {3254, 433, 65554, 1223, 7665, 7600, 12, 254},
        {3254, 433, 65554, 1223, 7665, 7600, 12, 254}};
    float floatMatrix[][8] = {
        {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2},
        {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2}};
    double doubleMatrix[][8] = {
        {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21},
        {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21}};
    void *ptrMatrix[2][8];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 8; j++)
            ptrMatrix[i][j] = (void *)saferMalloc(sizeof(char));

    printf("MATRICES\n");
    printMatrix("%4hi", byteMatrix, 2, 8);
    printMatrix("%2c", charMatrix, 2, 8);
    printMatrix("%10.2f", floatMatrix, 2, 8);
    printMatrix("%10.2lf", doubleMatrix, 2, 8);
    //no printMatrix("%p", ptrMatrix) beacause %p is not supported by printMatrix

    chooseQuickSort("%c", byteMatrix[0], 8);
    chooseQuickSort("%c", charMatrix[0], 8);
    chooseQuickSort("%i", intMatrix[0], 8);
    chooseQuickSort("%f", floatMatrix[0], 8);
    chooseQuickSort("%lf", doubleMatrix[0], 8);
    chooseQuickSort("%p", ptrMatrix[0], 8);

    printf("QUICKSORTED MATRICES\n");
    printMatrix("%4hi", byteMatrix, 1, 8);
    printMatrix("%2c", charMatrix, 1, 8);
    printMatrix("%6i", intMatrix, 1, 8);
    printMatrix("%10.2f", floatMatrix, 1, 8);
    printMatrix("%10.2lf", doubleMatrix, 1, 8);
    for (int i = 0; i < 8; i++)
        printf("%16p", ptrMatrix[0][i]);
    printf("\n\n");

    bubbleSort(byteMatrix[1], 8);  // equivalent to chooseBubbleSort("%c", byteMatrix[1], 8);
    bubbleSort(charMatrix[1], 8);  // equivalent to chooseBubbleSort("%c", charMatrix[1], 8);
    bubbleSort(intMatrix[1], 8);   // equivalent to chooseBubbleSort("%i", intMatrix[1], 8);
    bubbleSort(floatMatrix[1], 8); // equivalent to chooseBubbleSort("%f", floatMatrix[1], 8);
    bubbleSort(doubleMatrix[1], 8);// equivalent to chooseBubbleSort("%lf", doubleMatrix[1], 8);
    bubbleSort(ptrMatrix[1], 8);   // equivalent to chooseBubbleSort("%p", ptrMatrix[1], 8);

    printf("BUBBLESORTED MATRICES\n");
    printMatrix("%4hi", byteMatrix[1], 1, 8);
    printMatrix("%2c", charMatrix[1], 1, 8);
    printMatrix("%6i", intMatrix[1], 1, 8);
    printMatrix("%10.2f", floatMatrix[1], 1, 8);
    printMatrix("%10.2lf", doubleMatrix[1], 1, 8);
    for (int i = 0; i < 8; i++)
        printf("%16p", ptrMatrix[1][i]);
    //no printMatrix("%p", ptrMatrix) beacause %p is not supported by printMatrix
    printf("\n\n");

    printf("LINEAR SEARCH\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", linearSearch("%c", byteMatrix, &byteMatrix[0][i], 8));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", linearSearch("%c", charMatrix, &charMatrix[0][i], 8));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", linearSearch("%i", intMatrix, &intMatrix[0][i], 8));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", linearSearch("%f", floatMatrix, &floatMatrix[0][i], 8));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", linearSearch("%lf", doubleMatrix, &doubleMatrix[0][i], 8));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", linearSearch("%p", ptrMatrix, &ptrMatrix[0][i], 8));
    printf("\n");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 8; j++)
            free(ptrMatrix[i][j]);
#endif

    return 0;
}