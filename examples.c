#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"

#define UTILITY_TESTING 1
#define STRING_TESTING 1
#define ARRAY_TESTING 1

int main() {
    if (UTILITY_TESTING) {
        byte bytes[2] = {-1, 1};
        char chars[] = {'A', 'a'};
        int ints[] = {-128, 128};
        float floats[] = {-1.1, 1.1};
        double doubles[] = {-1.2, 1.2};
        void *ptrs[2];
        for (int i = 0; i < 2; i++) 
            ptrs[i] = saferMalloc(sizeof(char));
            
        byte (*cmpFunc)(void *a, void *b);

        cmpFunc = chooseCmp("%c");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                printf("%3i", (*cmpFunc)(&bytes[i], &bytes[j]));
        printf("\n");
        cmpFunc = chooseCmp("%c");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                printf("%3i", (*cmpFunc)(&chars[i], &chars[j]));
        printf("\n");
        cmpFunc = chooseCmp("%i");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                printf("%3i", (*cmpFunc)(&ints[i], &ints[j]));
        printf("\n");
        cmpFunc = chooseCmp("%f");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                printf("%3i", (*cmpFunc)(&floats[i], &floats[j]));
        printf("\n");
        cmpFunc = chooseCmp("%lf");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                printf("%3i", (*cmpFunc)(&doubles[i], &doubles[j]));
        printf("\n");
        cmpFunc = chooseCmp("%p");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                printf("%3i", (*cmpFunc)(&ptrs[i], &ptrs[j]));
        printf("\n\n");

        for (int i = 0; i < 2; i++)
            free(ptrs[i]);
    }

    if (STRING_TESTING) {
        printf("Insert string: ");
        char *myString = getString();
        printf("String: %s\n", myString);
        myString = changeLastCharacter(myString, 'X');
        printf("Changed string: %s\n", myString);
        printf("Changed string length: %i\n", getLength(myString));
        myString = changeLastCharacter(myString, '\0');
        printf("Shrinked string: %s\n", myString);
        printf("Shrinked string length: %i\n", getLength(myString));
        printf("\n\n");
    }

    if (ARRAY_TESTING) {
        byte byteArr[][8] = {
            {32, 43, 65, 12, 76, 75, 1, 2},
            {32, 43, 65, 12, 76, 75, 1, 2}
        };
        char charArr[][8] = {
            {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'},
            {'F', 'Q', 'A', 'C', '3', '0', 'Z', 'R'}
        };
        int intArr[][8] = {
            {3254, 433, 65554, 1223, 7665, 7600, 12, 254},
            {3254, 433, 65554, 1223, 7665, 7600, 12, 254}
        };
        float floatArr[][8] = {
            {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2},
            {3254.2, 433.2, 65554.2, 1223.2, 7665.2, 7600.2, 12.2, 254.2}
        };
        double doubleArr[][8] = {
            {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21},
            {3254.21, 433.21, 65554.21, 1223.21, 7665.21, 7600.21, 12.21, 254.21}
        };
        void *ptrArr[2][8];
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 8; j++)
                ptrArr[i][j] = (void *)saferMalloc(sizeof(char));

        printMatrix("%4hi", byteArr, 2, 8);
        printMatrix("%2c", charArr, 2, 8);
        printMatrix("%10.2f", floatArr, 2, 8);
        printMatrix("%10.2lf", doubleArr, 2, 8);
        //no printMatrix("%p", ptrArr) beacause %p is not supported by printMatrix

        quickSort("%c", byteArr[0], 8);
        quickSort("%c", charArr[0], 8);
        quickSort("%i", intArr[0], 8);
        quickSort("%f", floatArr[0], 8);
        quickSort("%lf", doubleArr[0], 8);
        quickSort("%p", ptrArr[0], 8);

        printMatrix("%4hi", byteArr, 1, 8);
        printMatrix("%2c", charArr, 1, 8);
        printMatrix("%10.2f", floatArr, 1, 8);
        printMatrix("%10.2lf", doubleArr, 1, 8);
        for (int i = 0; i < 8; i++) 
            printf("%16p", ptrArr[0][i]);
        printf("\n\n");

        bubbleSort("%c", byteArr[1], 8);
        bubbleSort("%c", charArr[1], 8);
        bubbleSort("%i", intArr[1], 8);
        bubbleSort("%f", floatArr[1], 8);
        bubbleSort("%lf", doubleArr[1], 8);
        bubbleSort("%p", ptrArr[1], 8);

        printMatrix("%4hi", byteArr[1], 1, 8);
        printMatrix("%2c", charArr[1], 1, 8);
        printMatrix("%10.2f", floatArr[1], 1, 8);
        printMatrix("%10.2lf", doubleArr[1], 1, 8);
        for (int i = 0; i < 8; i++)
            printf("%16p", ptrArr[1][i]);
        printf("\n\n");

        for (int i = 0; i < 8; i++) 
            printf("%2i", linearSearch("%c", byteArr, &byteArr[0][i], 8));
        printf("\n");
        for (int i = 0; i < 8; i++)
            printf("%2i", linearSearch("%c", charArr, &charArr[0][i], 8));
        printf("\n");
        for (int i = 0; i < 8; i++)
            printf("%2i", linearSearch("%i", intArr, &intArr[0][i], 8));
        printf("\n");
        for (int i = 0; i < 8; i++)
            printf("%2i", linearSearch("%f", floatArr, &floatArr[0][i], 8));
        printf("\n");
        for (int i = 0; i < 8; i++)
            printf("%2i", linearSearch("%lf", doubleArr, &doubleArr[0][i], 8));
        printf("\n");
        for (int i = 0; i < 8; i++)
            printf("%2i", linearSearch("%p", ptrArr, &ptrArr[0][i], 8));
        printf("\n");

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 8; j++)
                free(ptrArr[i][j]);
    }
    return 0;
}