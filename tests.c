#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"

#define TEST_STACK
// #define TEST_LINKEDLIST
// #define TEST_ARRAYLIST
// #define TEST_UTILITY
// #define TEST_STRING
// #define TEST_ARRAY

int main() {

#ifdef TEST_STACK

    printf("TESTING STACK\n");
    Stack byteStack = newStack("%c");
    Stack charStack = newStack("%c");
    Stack intStack = newStack("%i");
    Stack floatStack = newStack("%f");
    Stack doubleStack = newStack("%lf");
    Stack ptrStack = newStack("%p");
    printf("Testing newStack()\n");
    printStack("%hi", byteStack);
    printf("\n");
    printStack("%c", charStack);
    printf("\n");
    printStack("%i", intStack);
    printf("\n");
    printStack("%f", floatStack);
    printf("\n");
    printStack("%lf", doubleStack);
    printf("\n");
    printStack("%p", ptrStack);
    printf("\n\n");

    deleteStack(byteStack);
    deleteStack(charStack);
    deleteStack(intStack);
    deleteStack(floatStack);
    deleteStack(doubleStack);
    deleteStack(ptrStack);

    byte byteArrForStack[] = {32, 43, 65, 12, 76, 75, 1, 2};
    char charArrForStack[] = {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'};
    int intArrForStack[] = {3254, 433, 65554, 1223, 7665, 7600, 12, 254};
    float floatArrForStack[] = {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2};
    double doubleArrForStack[] = {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21};
    void *ptrArrForStack[8];
    for (int i = 0; i < 8; i++)
        ptrArrForStack[i] = saferMalloc(sizeof(byte));
    byteStack = chooseNewStackFromArray("%c", byteArrForStack, 8);
    charStack = chooseNewStackFromArray("%c", charArrForStack, 8);
    intStack = chooseNewStackFromArray("%i", intArrForStack, 8);
    floatStack = chooseNewStackFromArray("%f", floatArrForStack, 8);
    doubleStack = chooseNewStackFromArray("%lf", doubleArrForStack, 8);
    ptrStack = chooseNewStackFromArray("%p", ptrArrForStack, 8);
    printf("Testing chooseNewStackFromArray()\n");
    printStack("%4hi", byteStack);
    printf("\n\n");
    printStack("%2c", charStack);
    printf("\n\n");
    printStack("%6i", intStack);
    printf("\n\n");
    printStack("%9.1f", floatStack);
    printf("\n\n");
    printStack("%10.2lf", doubleStack);
    printf("\n\n");
    printStack("%16p", ptrStack);
    printf("\n\n\n");
    ;

    byte myByteForStack;
    char myCharForStack;
    int myIntForStack;
    float myFloatForStack;
    double myDoubleForStack;
    void *myPtrForStack;

    pushToStack(byteStack, 42);
    pushToStack(charStack, 'a');
    pushToStack(intStack, 422);
    pushToStack(floatStack, -2.2);
    pushToStack(doubleStack, -2.21);
    pushToStack(ptrStack, &myDoubleForStack);
    printf("Testing pushToStack()\n");
    printStack("%4hi", byteStack);
    printf("\n\n");
    printStack("%2c", charStack);
    printf("\n\n");
    printStack("%6i", intStack);
    printf("\n\n");
    printStack("%9.1f", floatStack);
    printf("\n\n");
    printStack("%10.2lf", doubleStack);
    printf("\n\n");
    printStack("%16p", ptrStack);
    printf("\n\n\n");

    deleteHeadFromStack(byteStack);
    deleteHeadFromStack(charStack);
    deleteHeadFromStack(intStack);
    deleteHeadFromStack(floatStack);
    deleteHeadFromStack(doubleStack);
    deleteHeadFromStack(ptrStack);
    printf("Testing deleteHeadFromStack()\n");
    printStack("%4hi", byteStack);
    printf("\n\n");
    printStack("%2c", charStack);
    printf("\n\n");
    printStack("%6i", intStack);
    printf("\n\n");
    printStack("%9.1f", floatStack);
    printf("\n\n");
    printStack("%10.2lf", doubleStack);
    printf("\n\n");
    printStack("%16p", ptrStack);
    printf("\n\n\n");

    printf("Testing isInStack()\n");
    for (int i = 0; i < 8; i++) {
        getHeadDataFromStack(byteStack, &myByteForStack);
        printf("%3i", isInStack(byteStack, myByteForStack));
    }
    printf("%3i", isInStack(byteStack, -128));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getHeadDataFromStack(charStack, &myCharForStack);
        printf("%3i", isInStack(charStack, myCharForStack));
    }
    printf("%3i", isInStack(charStack, '\0'));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getHeadDataFromStack(intStack, &myIntForStack);
        printf("%3i", isInStack(intStack, myIntForStack));
    }
    printf("%3i", isInStack(intStack, -65536));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getHeadDataFromStack(ptrStack, &myPtrForStack);
        printf("%3i", isInStack(ptrStack, myPtrForStack));
    }
    printf("%3i", isInStack(ptrStack, NULL));
    printf("\n\n\n");

    deleteStack(byteStack);
    deleteStack(charStack);
    deleteStack(intStack);
    deleteStack(floatStack);
    deleteStack(doubleStack);
    deleteStack(ptrStack);

#endif

#ifdef TEST_LINKEDLIST

    printf("TESTING LINKEDLIST\n");
    LinkedList newByteLL = newLL("%c");
    LinkedList newCharLL = newLL("%c");
    LinkedList newIntLL = newLL("%i");
    LinkedList newFloatLL = newLL("%f");
    LinkedList newDoubleLL = newLL("%lf");
    LinkedList newPtrLL = newLL("%p");
    printf("Testing newLL()\n");
    printLL("%hi", newByteLL);
    printf("\n");
    printLL("%c", newCharLL);
    printf("\n");
    printLL("%i", newIntLL);
    printf("\n");
    printLL("%f", newFloatLL);
    printf("\n");
    printLL("%lf", newDoubleLL);
    printf("\n");
    printLL("%p", newPtrLL);
    printf("\n\n");
    deleteLL(newByteLL);
    deleteLL(newCharLL);
    deleteLL(newIntLL);
    deleteLL(newFloatLL);
    deleteLL(newDoubleLL);
    deleteLL(newPtrLL);

    byte byteArrForLL[] = {32, 43, 65, 12, 76, 75, 1, 2};
    char charArrForLL[] = {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'};
    int intArrForLL[] = {3254, 433, 65554, 1223, 7665, 7600, 12, 254};
    float floatArrForLL[] = {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2};
    double doubleArrForLL[] = {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21};
    void *ptrArrForLL[8];
    for (int i = 0; i < 8; i++)
        ptrArrForLL[i] = saferMalloc(sizeof(byte));
    LinkedList byteLL = chooseNewLLFromArray("%c", byteArrForLL, 8);
    LinkedList charLL = chooseNewLLFromArray("%c", charArrForLL, 8);
    LinkedList intLL = chooseNewLLFromArray("%i", intArrForLL, 8);
    LinkedList floatLL = chooseNewLLFromArray("%f", floatArrForLL, 8);
    LinkedList doubleLL = chooseNewLLFromArray("%lf", doubleArrForLL, 8);
    LinkedList ptrLL = chooseNewLLFromArray("%p", ptrArrForLL, 8);
    printf("Testing chooseNewLLFromArray()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    byte myByteForLL;
    char myCharForLL;
    int myIntForLL;
    float myFloatForLL;
    double myDoubleForLL;
    void *myPtrForLL;
    getFromLL(byteLL, 0, &myByteForLL);
    getFromLL(charLL, 0, &myCharForLL);
    getFromLL(intLL, 0, &myIntForLL);
    getFromLL(floatLL, 0, &myFloatForLL);
    getFromLL(doubleLL, 0, &myDoubleForLL);
    getFromLL(ptrLL, 0, &myPtrForLL);
    printf("Testing getFromAl()\n");
    printf("%hi\n\n", myByteForLL);
    printf("%c\n\n", myCharForLL);
    printf("%i\n\n", myIntForLL);
    printf("%f\n\n", myFloatForLL);
    printf("%lf\n\n", myDoubleForLL);
    printf("%p\n\n", myPtrForLL);
    printf("\n");

    setLLItem(byteLL, 0, -1);
    setLLItem(charLL, 0, '*');
    setLLItem(intLL, 0, -1);
    setLLItem(floatLL, 0, -1.2);
    setLLItem(doubleLL, 0, -1.21);
    setLLItem(ptrLL, 0, &myPtrForLL);
    printf("Testing setLLelement()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    appendToLL(byteLL, 42);
    appendToLL(charLL, 'a');
    appendToLL(intLL, 422);
    appendToLL(floatLL, -2.2);
    appendToLL(doubleLL, -2.21);
    appendToLL(ptrLL, &myDoubleForLL);
    printf("Testing appendToLL()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    insertToLL(byteLL, 4, -42);
    insertToLL(charLL, 4, 'a');
    insertToLL(intLL, 4, -422);
    insertToLL(floatLL, 4, -422.2);
    insertToLL(doubleLL, 4, -422.21);
    insertToLL(ptrLL, 4, &myFloatForLL);
    printf("Testing inserToLL()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    removeFromLL(byteLL, 8);
    removeFromLL(charLL, 8);
    removeFromLL(intLL, 8);
    removeFromLL(floatLL, 8);
    removeFromLL(doubleLL, 8);
    removeFromLL(ptrLL, 8);
    printf("Testing removeFromLL()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    insertToLL(byteLL, 4, -42);
    insertToLL(charLL, 4, 'a');
    insertToLL(intLL, 4, -422);
    insertToLL(floatLL, 4, -422.2);
    insertToLL(doubleLL, 4, -422.21);
    insertToLL(ptrLL, 4, &myFloatForLL);
    printf("Testing inserToLL()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    mergeLL(byteLL, byteLL);
    mergeLL(charLL, charLL);
    mergeLL(intLL, intLL);
    mergeLL(floatLL, floatLL);
    mergeLL(doubleLL, doubleLL);
    mergeLL(ptrLL, ptrLL);
    printf("Testing mergeLL()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    sliceLL(byteLL, 5, 15);
    sliceLL(charLL, 5, 15);
    sliceLL(intLL, 5, 15);
    sliceLL(floatLL, 5, 15);
    sliceLL(doubleLL, 5, 15);
    sliceLL(ptrLL, 5, 15);
    printf("Testing sliceLL()\n");
    printLL("%4hi", byteLL);
    printf("\n\n");
    printLL("%2c", charLL);
    printf("\n\n");
    printLL("%6i", intLL);
    printf("\n\n");
    printLL("%9.1f", floatLL);
    printf("\n\n");
    printLL("%10.2lf", doubleLL);
    printf("\n\n");
    printLL("%16p", ptrLL);
    printf("\n\n\n");

    printf("Testing linearSearchLL()\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(byteLL, i, &myByteForLL);
        printf("%2i", linearSearchLL(byteLL, myByteForLL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(charLL, i, &myCharForLL);
        printf("%2i", linearSearchLL(charLL, myCharForLL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(intLL, i, &myIntForLL);
        printf("%2i", linearSearchLL(intLL, myIntForLL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(ptrLL, i, &myPtrForLL);
        printf("%2i", linearSearchLL(ptrLL, myPtrForLL));
    }
    printf("\n\n\n");

    printf("Testing linearSearchLLPtr()\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(byteLL, i, &myByteForLL);
        printf("%p\n", linearSearchLLPtr(byteLL, myByteForLL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(charLL, i, &myCharForLL);
        printf("%p\n", linearSearchLLPtr(charLL, myCharForLL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(intLL, i, &myIntForLL);
        printf("%p\n", linearSearchLLPtr(intLL, myIntForLL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(ptrLL, i, &myPtrForLL);
        printf("%p\n", linearSearchLLPtr(ptrLL, myPtrForLL));
    }
    printf("\n\n\n");

    printf("Testing isInLL()\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(byteLL, i, &myByteForLL);
        printf("%3i", isInLL(byteLL, myByteForLL));
    }
    printf("%3i", isInLL(byteLL, -128));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(charLL, i, &myCharForLL);
        printf("%3i", isInLL(charLL, myCharForLL));
    }
    printf("%3i", isInLL(charLL, '\0'));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(intLL, i, &myIntForLL);
        printf("%3i", isInLL(intLL, myIntForLL));
    }
    printf("%3i", isInLL(intLL, -65536));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromLL(ptrLL, i, &myPtrForLL);
        printf("%3i", isInLL(ptrLL, myPtrForLL));
    }
    printf("%3i", isInLL(ptrLL, NULL));
    printf("\n\n\n");

    LinkedList byteLL2 = newLLFromLL(byteLL);
    LinkedList charLL2 = newLLFromLL(charLL);
    LinkedList intLL2 = newLLFromLL(intLL);
    LinkedList floatLL2 = newLLFromLL(floatLL);
    LinkedList doubleLL2 = newLLFromLL(doubleLL);
    LinkedList ptrLL2 = newLLFromLL(ptrLL);
    printf("Testing areLLEqual()\n");
    printf("%2hi\n", areLLEqual(byteLL, byteLL2));
    printf("%2hi\n", areLLEqual(charLL, charLL2));
    printf("%2hi\n", areLLEqual(intLL2, intLL2));
    printf("%2hi\n", areLLEqual(floatLL2, floatLL2));
    printf("%2hi\n", areLLEqual(doubleLL2, doubleLL2));
    printf("%2hi\n", areLLEqual(ptrLL2, ptrLL2));
    sliceLL(byteLL2, 3, 5);
    sliceLL(charLL2, 3, 5);
    sliceLL(intLL2, 3, 5);
    sliceLL(floatLL2, 3, 5);
    sliceLL(doubleLL2, 3, 5);
    sliceLL(ptrLL2, 3, 5);
    printf("%2hi\n", areLLEqual(byteLL, byteLL2));
    printf("%2hi\n", areLLEqual(charLL, charLL2));
    printf("%2hi\n", areLLEqual(intLL, intLL2));
    printf("%2hi\n", areLLEqual(floatLL, floatLL2));
    printf("%2hi\n", areLLEqual(doubleLL, doubleLL2));
    printf("%2hi\n", areLLEqual(ptrLL, ptrLL2));

    deleteLL(byteLL);
    deleteLL(charLL);
    deleteLL(intLL);
    deleteLL(floatLL);
    deleteLL(doubleLL);
    deleteLL(ptrLL);
    deleteLL(byteLL2);
    deleteLL(charLL2);
    deleteLL(intLL2);
    deleteLL(floatLL2);
    deleteLL(doubleLL2);
    deleteLL(ptrLL2);

    printf("\n\n");

#endif

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

    byte byteArrForAL[] = {32, 43, 65, 12, 76, 75, 1, 2};
    char charArrForAL[] = {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'};
    int intArrForAL[] = {3254, 433, 65554, 1223, 7665, 7600, 12, 254};
    float floatArrForAL[] = {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2};
    double doubleArrForAL[] = {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21};
    void *ptrArrForAL[8];
    for (int i = 0; i < 8; i++)
        ptrArrForAL[i] = saferMalloc(sizeof(byte));
    ArrayList byteAL = chooseNewALFromArray("%c", byteArrForAL, 8);
    ArrayList charAL = chooseNewALFromArray("%c", charArrForAL, 8);
    ArrayList intAL = chooseNewALFromArray("%i", intArrForAL, 8);
    ArrayList floatAL = chooseNewALFromArray("%f", floatArrForAL, 8);
    ArrayList doubleAL = chooseNewALFromArray("%lf", doubleArrForAL, 8);
    ArrayList ptrAL = chooseNewALFromArray("%p", ptrArrForAL, 8);
    printf("Testing chooseNewALFromArray()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    byte myByteForAL;
    char myCharForAL;
    int myIntForAL;
    float myFloatForAL;
    double myDoubleForAL;
    void *myPtrForAL;
    getFromAL(byteAL, 0, &myByteForAL);
    getFromAL(charAL, 0, &myCharForAL);
    getFromAL(intAL, 0, &myIntForAL);
    getFromAL(floatAL, 0, &myFloatForAL);
    getFromAL(doubleAL, 0, &myDoubleForAL);
    getFromAL(ptrAL, 0, &myPtrForAL);
    printf("Testing getFromAL()\n");
    printf("%hi\n\n", myByteForAL);
    printf("%c\n\n", myCharForAL);
    printf("%i\n\n", myIntForAL);
    printf("%f\n\n", myFloatForAL);
    printf("%lf\n\n", myDoubleForAL);
    printf("%p\n\n", myPtrForAL);
    printf("\n");

    setALItem(byteAL, 0, -1);
    setALItem(charAL, 0, '*');
    setALItem(intAL, 0, -1);
    setALItem(floatAL, 0, -1.2);
    setALItem(doubleAL, 0, -1.21);
    setALItem(ptrAL, 0, &myPtrForAL);
    printf("Testing setALelement()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    appendToAL(byteAL, 42);
    appendToAL(charAL, 'a');
    appendToAL(intAL, 422);
    appendToAL(floatAL, -2.2);
    appendToAL(doubleAL, -2.21);
    appendToAL(ptrAL, &myDoubleForAL);
    printf("Testing appendToAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
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
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    insertToAL(byteAL, 4, -42);
    insertToAL(charAL, 4, 'a');
    insertToAL(intAL, 4, -422);
    insertToAL(floatAL, 4, -422.2);
    insertToAL(doubleAL, 4, -422.21);
    insertToAL(ptrAL, 4, &myFloatForAL);
    printf("Testing inserToAL()\n");
    printAL("%4hi", byteAL);
    printf("\n\n");
    printAL("%2c", charAL);
    printf("\n\n");
    printAL("%6i", intAL);
    printf("\n\n");
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
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
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
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
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
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
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
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
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
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
    printAL("%9.1f", floatAL);
    printf("\n\n");
    printAL("%10.2lf", doubleAL);
    printf("\n\n");
    printAL("%16p", ptrAL);
    printf("\n\n\n");

    printf("Testing linearSearchAL()\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(byteAL, i, &myByteForAL);
        printf("%2i", linearSearchAL(byteAL, myByteForAL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(charAL, i, &myCharForAL);
        printf("%2i", linearSearchAL(charAL, myCharForAL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(intAL, i, &myIntForAL);
        printf("%2i", linearSearchAL(intAL, myIntForAL));
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(ptrAL, i, &myPtrForAL);
        printf("%2i", linearSearchAL(ptrAL, myPtrForAL));
    }
    printf("\n\n\n");

    printf("Testing isInAL()\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(byteAL, i, &myByteForAL);
        printf("%3i", isInAL(byteAL, myByteForAL));
    }
    printf("%3i", isInAL(byteAL, -128));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(charAL, i, &myCharForAL);
        printf("%3i", isInAL(charAL, myCharForAL));
    }
    printf("%3i", isInAL(charAL, '\0'));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(intAL, i, &myIntForAL);
        printf("%3i", isInAL(intAL, myIntForAL));
    }
    printf("%3i", isInAL(intAL, -65536));
    printf("\n");
    for (int i = 0; i < 8; i++) {
        getFromAL(ptrAL, i, &myPtrForAL);
        printf("%3i", isInAL(ptrAL, myPtrForAL));
    }
    printf("%3i", isInAL(ptrAL, NULL));
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
    void *ptrMatrix[4][8];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 8; j++)
            ptrMatrix[i][j] = (void *)saferMalloc(sizeof(byte));
    
    printf("Testing printMatrix()\n");
    printMatrix("%4hi", byteMatrix, 2, 8);
    printMatrix("%2c", charMatrix, 2, 8);
    printMatrix("%10.2f", floatMatrix, 2, 8);
    printMatrix("%10.2lf", doubleMatrix, 2, 8);
    printMatrix("%16p", ptrMatrix, 2, 8);

    chooseQuickSortArr("%c", byteMatrix[0], 8);
    chooseQuickSortArr("%c", charMatrix[0], 8);
    chooseQuickSortArr("%i", intMatrix[0], 8);
    chooseQuickSortArr("%f", floatMatrix[0], 8);
    chooseQuickSortArr("%lf", doubleMatrix[0], 8);
    chooseQuickSortArr("%p", ptrMatrix[0], 8);

    printf("Testing chooseQuickSortArr()\n");
    printMatrix("%4hi", byteMatrix, 1, 8);
    printMatrix("%2c", charMatrix, 1, 8);
    printMatrix("%6i", intMatrix, 1, 8);
    printMatrix("%10.2f", floatMatrix, 1, 8);
    printMatrix("%10.2lf", doubleMatrix, 1, 8);
    for (int i = 0; i < 8; i++)
        printf("%16p", ptrMatrix[0][i]);
    printf("\n\n");

    chooseBubbleSortArr("%c", byteMatrix[1], 8);
    chooseBubbleSortArr("%c", charMatrix[1], 8);
    chooseBubbleSortArr("%i", intMatrix[1], 8);
    chooseBubbleSortArr("%f", floatMatrix[1], 8);
    chooseBubbleSortArr("%lf", doubleMatrix[1], 8);
    chooseBubbleSortArr("%p", ptrMatrix[1], 8);

    printf("Testing chooseBubbleSortArr()\n");
    printMatrix("%4hi", byteMatrix[1], 1, 8);
    printMatrix("%2c", charMatrix[1], 1, 8);
    printMatrix("%6i", intMatrix[1], 1, 8);
    printMatrix("%10.2f", floatMatrix[1], 1, 8);
    printMatrix("%10.2lf", doubleMatrix[1], 1, 8);
    printMatrix("%16p", ptrMatrix, 2, 8);
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