#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../types.h"
#include "../constants.h"
#include "../utility.h"
#include "utilityInternal.h"
#include "errors.h"

string getString() {
    string str;
    unsigned int length = 0;
    str = saferMalloc(sizeof(char));
    length = 1;
    while ((str[length - 1] = getchar()) != '\n') {
        length++;
        str = saferRealloc(str, length * sizeof(char));
    }
    str[length - 1] = '\0';
    return str;
}

byte endsWith(const string str, const string suffix) {
    funcThrowIf(!str || !suffix, NULL_POINTER_GIVEN);
    unsigned int lenstr = strlen(str);
    unsigned int lensuffix = strlen(suffix);
    if (lensuffix > lenstr)
        return FALSE;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0 ? TRUE : FALSE;
}

string copyOf(const string src) {
    funcThrowIf(!src, NULL_POINTER_GIVEN);
    char *dest = (char *)saferMalloc(strlen(src) * sizeof(char));
    strcpy(dest, src);
    return dest;
}

string changeLastCharacter(const string str, char newCharacter) {
    funcThrowIf(!str, NULL_POINTER_GIVEN);
    string newString = copyOf(str);
    *(newString + (strlen(str) - 1) * sizeof(char)) = newCharacter;
    return newString;
}