#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"

// #define SKIP_ARRAYLIST
// #define SKIP_UTILITY
// #define SKIP_STRING
// #define SKIP_ARRAY

int main() {

#ifndef SKIP_ARRAYLIST

    printf("TESTING ARRAYLIST\n");
    ArrayList newByteAL = newAL("%c");
    ArrayList newCharAL = newAL("%c");
    printf("Testing newAL()\n");
    printAL("%4hi", newByteAL);
    printf("\n");
    printAL("%2c", newCharAL);
    printf("\n\n");
    deleteAL(newByteAL);
    deleteAL(newCharAL);

    byte byteArr[] = {32, 43, 65, 12, 76, 75, 1, 2};
    char charArr[] = {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'};
    ArrayList byteAL = newALFromArray(byteArr, 8);
    ArrayList charAL = newALFromArray(charArr, 8);
    printf("Testing newArrayFromArray()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    byte myByte;
    char myChar;
    getFromAL(byteAL, 0, &myByte);
    getFromAL(charAL, 0, &myChar);
    printf("Testing getFromAl()\n");
    printf("%hi\n\n", myByte);
    printf("%c\n\n", myChar);
    printf("\n");

    setALElement(byteAL, 0, -1);
    setALElement(charAL, 0, '*');
    printf("Testing setALelement()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    appendToAL(byteAL, 42);
    appendToAL(charAL, 'a');
    printf("Testing appendToAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    removeFromAL(byteAL, 8);
    removeFromAL(charAL, 8);
    printf("Testing removeFromAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    insertToAL(byteAL, 4, -42);
    insertToAL(charAL, 4, 'a');
    printf("Testing inserToAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    bubbleSortAL(byteAL);
    bubbleSortAL(charAL);
    printf("Testing bubbleSortAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");
    
    reverseAL(byteAL);
    reverseAL(charAL);
    printf("Testing reverseAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    quickSortAL(byteAL);
    quickSortAL(charAL);
    printf("Testing quickSortAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    mergeAL(byteAL, byteAL);
    mergeAL(charAL, charAL);
    printf("Testing mergeAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    sliceAL(byteAL, 5, 15);
    sliceAL(charAL, 5, 15);
    printf("Testing sliceAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n\n");

    ArrayList byteAL2 = newALFromAL(byteAL);
    ArrayList charAL2 = newALFromAL(charAL);
    printf("Testing areALEqual()\n");
    printf("%2hi\n", areALEqual(byteAL, byteAL2));
    printf("%2hi\n", areALEqual(charAL, charAL2));
    sliceAL(byteAL2, 3, 5);
    sliceAL(charAL2, 3, 5);
    printf("%2hi\n", areALEqual(byteAL, byteAL2));
    printf("%2hi\n", areALEqual(charAL, charAL2));

    deleteAL(byteAL);
    deleteAL(charAL);
    deleteAL(byteAL2);
    deleteAL(charAL2);
    printf("\n\n");

#endif

#ifndef SKIP_UTILITY
    printf("TESTING UTILITY\n");
    byte bytes[2] = {-1, 1};
    char chars[] = {'A', 'a'};
    int ints[] = {-128, 128};
    float floats[] = {-1.1, 1.1};
    double doubles[] = {-1.2, 1.2};
    void *ptrs[2];
    for (int i = 0; i < 2; i++)
        ptrs[i] = saferMalloc(sizeof(char));

    printf("Testing chooseCmp()\n");
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
    printf("\n\n");

    printf("Testing cmpVal()\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmpVal(bytes[i], bytes[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmpVal(chars[i], chars[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmpVal(ints[i], ints[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmpVal(floats[i], floats[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmpVal(doubles[i], doubles[j]));
    printf("\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%3i", cmpVal(ptrs[i], ptrs[j]));
    printf("\n\n");

    printf("\n\n");
    for (int i = 0; i < 2; i++)
        free(ptrs[i]);
#endif

#ifndef SKIP_STRING
    printf("TESTING STRINGS\n");
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
    printf("TESTING ARRAYS\n");
    byte byteMatrix[][8] = {
        {32, 43, 65, 12, 76, 75, 1, 2},
        {32, 43, 65, 12, 76, 75, 1, 2},
        {32, 43, 65, 12, 76, 75, 1, 2},
        {32, 43, 65, 12, 76, 75, 1, 2}};
    char charMatrix[][8] = {
        {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'},
        {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'},
        {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'},
        {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'}};
    int intMatrix[][8] = {
        {3254, 433, 65554, 1223, 7665, 7600, 12, 254},
        {3254, 433, 65554, 1223, 7665, 7600, 12, 254},
        {3254, 433, 65554, 1223, 7665, 7600, 12, 254},
        {3254, 433, 65554, 1223, 7665, 7600, 12, 254}};
    float floatMatrix[][8] = {
        {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2},
        {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2},
        {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2},
        {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2}};
    double doubleMatrix[][8] = {
        {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21},
        {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21},
        {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21},
        {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21}};
    void *ptrMatrix[4][8];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            ptrMatrix[i][j] = (void *)saferMalloc(sizeof(char));
    
    printf("Testing printMatrix()\n");
    printMatrix("%4hi", byteMatrix, 2, 8);
    printMatrix("%2c", charMatrix, 2, 8);
    printMatrix("%10.2f", floatMatrix, 2, 8);
    printMatrix("%10.2lf", doubleMatrix, 2, 8);
    //no printMatrix("%p", ptrMatrix) beacause %p is not supported by printMatrix

    quickSortArr(byteMatrix[0], 8);    // chooseQuickSortArr("%c", byteMatrix[0], 8);
    quickSortArr(charMatrix[0], 8);    // chooseQuickSortArr("%c", charMatrix[0], 8);
    quickSortArr(intMatrix[0], 8);     // chooseQuickSortArr("%i", intMatrix[0], 8);
    quickSortArr(floatMatrix[0], 8);   // chooseQuickSortArr("%f", floatMatrix[0], 8);
    quickSortArr(doubleMatrix[0], 8);  // chooseQuickSortArr("%lf", doubleMatrix[0], 8);
    quickSortArr(ptrMatrix[0], 8);     // chooseQuickSortArr("%p", ptrMatrix[0], 8);

    printf("Testing quickSortArr()\n");
    printMatrix("%4hi", byteMatrix, 1, 8);
    printMatrix("%2c", charMatrix, 1, 8);
    printMatrix("%6i", intMatrix, 1, 8);
    printMatrix("%10.2f", floatMatrix, 1, 8);
    printMatrix("%10.2lf", doubleMatrix, 1, 8);
    for (int i = 0; i < 8; i++)
        printf("%16p", ptrMatrix[0][i]);
    printf("\n\n");

    bubbleSortArr(byteMatrix[1], 8);
    bubbleSortArr(charMatrix[1], 8);
    bubbleSortArr(intMatrix[1], 8);
    bubbleSortArr(floatMatrix[1], 8);
    bubbleSortArr(doubleMatrix[1], 8);
    bubbleSortArr(ptrMatrix[1], 8);

    printf("Testing bubbleSortArr()\n");
    printMatrix("%4hi", byteMatrix[1], 1, 8);
    printMatrix("%2c", charMatrix[1], 1, 8);
    printMatrix("%6i", intMatrix[1], 1, 8);
    printMatrix("%10.2f", floatMatrix[1], 1, 8);
    printMatrix("%10.2lf", doubleMatrix[1], 1, 8);
    for (int i = 0; i < 8; i++)
        printf("%16p", ptrMatrix[1][i]);
    //no printMatrix("%p", ptrMatrix) beacause %p is not supported by printMatrix
    printf("\n\n");

    chooseQuickSortArr("%c", byteMatrix[2], 8);
    chooseQuickSortArr("%c", charMatrix[2], 8);
    chooseQuickSortArr("%i", intMatrix[2], 8);
    chooseQuickSortArr("%f", floatMatrix[2], 8);
    chooseQuickSortArr("%lf", doubleMatrix[2], 8);
    chooseQuickSortArr("%p", ptrMatrix[2], 8);

    printf("Testing chooseQuickSortArr()\n");
    printMatrix("%4hi", byteMatrix[2], 1, 8);
    printMatrix("%2c", charMatrix[2], 1, 8);
    printMatrix("%6i", intMatrix[2], 1, 8);
    printMatrix("%10.2f", floatMatrix[2], 1, 8);
    printMatrix("%10.2lf", doubleMatrix[2], 1, 8);
    for (int i = 0; i < 8; i++)
        printf("%16p", ptrMatrix[2][i]);
    printf("\n\n");

    chooseBubbleSortArr("%c", byteMatrix[3], 8);
    chooseBubbleSortArr("%c", charMatrix[3], 8);
    chooseBubbleSortArr("%i", intMatrix[3], 8);
    chooseBubbleSortArr("%f", floatMatrix[3], 8);
    chooseBubbleSortArr("%lf", doubleMatrix[3], 8);
    chooseBubbleSortArr("%p", ptrMatrix[3], 8);

    printf("Testing chooseQuickSortArr()\n");
    printMatrix("%4hi", byteMatrix[3], 1, 8);
    printMatrix("%2c", charMatrix[3], 1, 8);
    printMatrix("%6i", intMatrix[3], 1, 8);
    printMatrix("%10.2f", floatMatrix[3], 1, 8);
    printMatrix("%10.2lf", doubleMatrix[3], 1, 8);
    for (int i = 0; i < 8; i++)
        printf("%16p", ptrMatrix[3][i]);
    printf("\n\n");

    printf("Testing linearSearch()\n");
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