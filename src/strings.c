#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../types.h"
#include "../constants.h"
#include "../utility.h"

string getString() {
    string str;
    unsigned int length = 0;
    str = saferMalloc(sizeof(char));
    if (!str)
        return NULL;
    length = 1;
    while ((str[length - 1] = getchar()) != '\n') {
        length++;
        str = saferRealloc(str, length * sizeof(char));
        if (!str)
            return NULL;
    }
    str[length - 1] = '\0';
    return str;
}

byte endsWith(const string str, const string suffix) {
    if (!str || !suffix)
        return NULL_POINTER_GIVEN;
    unsigned int lenstr = strlen(str);
    unsigned int lensuffix = strlen(suffix);
    if (lensuffix > lenstr)
        return 0;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}

unsigned int getLength(const string str) {
    if (!str)
        return NULL_POINTER_GIVEN;
    return strlen(str);
}

string copyOf(const string src) {
    if (!src)
        return NULL;
    char *dest = (char *)saferMalloc(getLength(src) * sizeof(char));
    if (!dest)
        return NULL;
    strcpy(dest, src);
    return dest;
}

string changeLastCharacter(const string str, char newCharacter) {
    if (!str)
        return NULL;
    string newString = copyOf(str);
    if (!newString)
        return NULL;
    *(newString + (getLength(str) - 1) * sizeof(char)) = newCharacter;
    return newString;
}