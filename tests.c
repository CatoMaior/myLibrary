#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"

#define TEST_ARRAYLIST
#define TEST_UTILITY
#define TEST_STRING
#define TEST_ARRAY

int main() {

#ifdef TEST_ARRAYLIST

    printf("TESTING ARRAYLIST\n");
    ArrayList newByteAL = newAL("%c");
    ArrayList newCharAL = newAL("%c");
    ArrayList newIntAL = newAL("%i");
    ArrayList newFloatAL = newAL("%f");
    ArrayList newDoubleAL = newAL("%lf");
    ArrayList newPtrAL = newAL("%p");
    printf("Testing newAL()\n");
    printAL("%hi", newByteAL);
    printf("\n");
    printAL("%c", newCharAL);
    printf("\n");
    printAL("%i", newIntAL);
    printf("\n");
    printAL("%f", newFloatAL);
    printf("\n");
    printAL("%lf", newDoubleAL);
    printf("\n");
    printAL("%p", newPtrAL);
    printf("\n\n");
    deleteAL(newByteAL);
    deleteAL(newCharAL);
    deleteAL(newIntAL);
    deleteAL(newFloatAL);
    deleteAL(newDoubleAL);
    deleteAL(newPtrAL);

    byte byteArr[] = {32, 43, 65, 12, 76, 75, 1, 2};
    char charArr[] = {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'};
    int intArr[] = {3254, 433, 65554, 1223, 7665, 7600, 12, 254};
    float floatArr[] = {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2};
    double doubleArr[] = {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21};
    void *ptrArr[8];
    for (int i = 0; i < 8; i++)
        ptrArr[i] = saferMalloc(sizeof(byte));
    ArrayList byteAL = newALFromArray(byteArr, 8);
    ArrayList charAL = newALFromArray(charArr, 8);
    ArrayList intAL = newALFromArray(intArr, 8);
    ArrayList floatAL = newALFromArray(floatArr, 8);
    ArrayList doubleAL = newALFromArray(doubleArr, 8);
    ArrayList ptrAL = newALFromPtrArray(ptrArr, 8); // newALFromArray does not support pointerArray
    printf("Testing newArrayFromArray()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    byte myByte;
    char myChar;
    int myInt;
    float myFloat;
    double myDouble;
    void *myPtr;
    getFromAL(byteAL, 0, &myByte);
    getFromAL(charAL, 0, &myChar);
    getFromAL(intAL, 0, &myInt);
    getFromAL(floatAL, 0, &myFloat);
    getFromAL(doubleAL, 0, &myDouble);
    getFromAL(ptrAL, 0, &myPtr);
    printf("Testing getFromAl()\n");
    printf("%hi\n\n", myByte);
    printf("%c\n\n", myChar);
    printf("%i\n\n", myInt);
    printf("%f\n\n", myFloat);
    printf("%lf\n\n", myDouble);
    printf("%p\n\n", myPtr);
    printf("\n");

    setALItem(byteAL, 0, -1);
    setALItem(charAL, 0, '*');
    setALItem(intAL, 0, -1);
    setALItem(floatAL, 0, -1.2);
    setALItem(doubleAL, 0, -1.21);
    setALItem(ptrAL, 0, &myPtr);
    printf("Testing setALelement()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    appendToAL(byteAL, 42);
    appendToAL(charAL, 'a');
    appendToAL(intAL, -2);
    appendToAL(floatAL, -2.2);
    appendToAL(doubleAL, -2.21);
    appendToAL(ptrAL, &myDouble);
    printf("Testing appendToAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    removeFromAL(byteAL, 8);
    removeFromAL(charAL, 8);
    removeFromAL(intAL, 8);
    removeFromAL(floatAL, 8);
    removeFromAL(doubleAL, 8);
    removeFromAL(ptrAL, 8);
    printf("Testing removeFromAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    insertToAL(byteAL, 4, -42);
    insertToAL(charAL, 4, 'a');
    insertToAL(intAL, 4, -422);
    insertToAL(floatAL, 4, -422.2);
    insertToAL(doubleAL, 4, -422.21);
    insertToAL(ptrAL, 4, &myFloat);
    printf("Testing inserToAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    bubbleSortAL(byteAL);
    bubbleSortAL(charAL);
    bubbleSortAL(intAL);
    bubbleSortAL(floatAL);
    bubbleSortAL(doubleAL);
    bubbleSortAL(ptrAL);
    printf("Testing bubbleSortAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    reverseAL(byteAL);
    reverseAL(charAL);
    reverseAL(intAL);
    reverseAL(floatAL);
    reverseAL(doubleAL);
    reverseAL(ptrAL);
    printf("Testing reverseAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    quickSortAL(byteAL);
    quickSortAL(charAL);
    quickSortAL(intAL);
    quickSortAL(floatAL);
    quickSortAL(doubleAL);
    quickSortAL(ptrAL);
    printf("Testing quickSortAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    mergeAL(byteAL, byteAL);
    mergeAL(charAL, charAL);
    mergeAL(intAL, intAL);
    mergeAL(floatAL, floatAL);
    mergeAL(doubleAL, doubleAL);
    mergeAL(ptrAL, ptrAL);
    printf("Testing mergeAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    sliceAL(byteAL, 5, 15);
    sliceAL(charAL, 5, 15);
    sliceAL(intAL, 5, 15);
    sliceAL(floatAL, 5, 15);
    sliceAL(doubleAL, 5, 15);
    sliceAL(ptrAL, 5, 15);
    printf("Testing sliceAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%7.1f", floatAL);
    printf("\n\n");
    printAL("%8.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    printf("Testing linearSearchAL()\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(byteAL, i, &myByte);
        printf("%2i", linearSearchAL(byteAL, myByte));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(charAL, i, &myChar);
        printf("%2i", linearSearchAL(charAL, myChar));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(intAL, i, &myInt);
        printf("%2i", linearSearchAL(intAL, myInt));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(ptrAL, i, &myPtr);
        printf("%2i", linearSearchAL(ptrAL, myPtr));
    }
    printf("\n\n\n");

    ArrayList byteAL2 = newALFromAL(byteAL);
    ArrayList charAL2 = newALFromAL(charAL);
    ArrayList intAL2 = newALFromAL(intAL);
    ArrayList floatAL2 = newALFromAL(floatAL);
    ArrayList doubleAL2 = newALFromAL(doubleAL);
    ArrayList ptrAL2 = newALFromAL(ptrAL);
    printf("Testing areALEqual()\n");
    printf("%2hi\n", areALEqual(byteAL, byteAL2));
    printf("%2hi\n", areALEqual(charAL, charAL2));
    printf("%2hi\n", areALEqual(intAL2, intAL2));
    printf("%2hi\n", areALEqual(floatAL2, floatAL2));
    printf("%2hi\n", areALEqual(doubleAL2, doubleAL2));
    printf("%2hi\n", areALEqual(ptrAL2, ptrAL2));
    sliceAL(byteAL2, 3, 5);
    sliceAL(charAL2, 3, 5);
    sliceAL(intAL2, 3, 5);
    sliceAL(floatAL2, 3, 5);
    sliceAL(doubleAL2, 3, 5);
    sliceAL(ptrAL2, 3, 5);
    printf("%2hi\n", areALEqual(byteAL, byteAL2));
    printf("%2hi\n", areALEqual(charAL, charAL2));
    printf("%2hi\n", areALEqual(intAL, intAL2));
    printf("%2hi\n", areALEqual(floatAL, floatAL2));
    printf("%2hi\n", areALEqual(doubleAL, doubleAL2));
    printf("%2hi\n", areALEqual(ptrAL, ptrAL2));

    deleteAL(byteAL);
    deleteAL(charAL);
    deleteAL(intAL);
    deleteAL(floatAL);
    deleteAL(doubleAL);
    deleteAL(ptrAL);
    deleteAL(byteAL2);
    deleteAL(charAL2);
    deleteAL(intAL2);
    deleteAL(floatAL2);
    deleteAL(doubleAL2);
    deleteAL(ptrAL2);

    printf("\n\n");

#endif

#ifdef TEST_UTILITY
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
            printf("%3i", chooseCmp("%p", &ptrs[j], &ptrs[i]));
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
            printf("%3i", cmpVal(ptrs[j], ptrs[i]));
    printf("\n\n");

    printf("\n\n");
    for (int i = 0; i < 2; i++)
        free(ptrs[i]);
#endif

#ifdef TEST_STRING
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

#ifdef TEST_ARRAY
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
            ptrMatrix[i][j] = (void *)saferMalloc(sizeof(byte));
    
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

    printf("Testing chooseLinearSearch()\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", chooseLinearSearch("%c", byteMatrix, 8, byteMatrix[0][i]));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", chooseLinearSearch("%c", charMatrix, 8, charMatrix[0][i]));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", chooseLinearSearch("%i", intMatrix, 8, intMatrix[0][i]));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", chooseLinearSearch("%f", floatMatrix, 8, floatMatrix[0][i]));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", chooseLinearSearch("%lf", doubleMatrix, 8, doubleMatrix[0][i]));
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%2i", chooseLinearSearch("%p", ptrMatrix, 8, ptrMatrix[0][i]));
    printf("\n");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 8; j++)
            free(ptrMatrix[i][j]);
#endif

    return 0;
}