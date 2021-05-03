#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../types.h"
#include "../constants.h"
#include "../utility.h"

String getString() {
    String string;
    string.text = saferMalloc(sizeof(char));
    if (!string.text) {
        string.lenght = 0;
        return string;
    }
    string.lenght = 1;
    while ((string.text[string.lenght - 1] = getchar()) != '\n') {
        string.lenght++;
        string.text = saferRealloc(string.text, string.lenght * sizeof(char));
        if (!string.text) {
            string.lenght = 0;
            return string;
        }
    }
    string.text[string.lenght - 1] = '\0';
    return string;
}

byte endsWith(const char *string, const char *suffix) {
    if (!string || !suffix )
        return NULL_POINTER_GIVEN;
    size_t lenstr = strlen(string);
    size_t lensuffix = strlen(suffix);
    if (lensuffix > lenstr)
        return 0;
    return strncmp(string + lenstr - lensuffix, suffix, lensuffix) == 0;
}

unsigned int getLength(const char *string) {
    if (!string)
        return NULL_POINTER_GIVEN;
    unsigned int length = 0;
    while (*(string + length * sizeof(char)) != '\0')
        length++;
    return length;
}

char *copyOf(const char *src) {
    if (!src)
        return NULL;
    char *dest = (char *)saferMalloc(getLength(src) * sizeof(char));
    if (!dest)
        return NULL;
    strcpy(dest, src);
    return dest;
}

char *changeLastCharacter(char *string, char newCharacter) {
    if (!string)
        return NULL;
    char *newString = copyOf(string);
    if (!newString)
        return NULL;
    *(newString + (getLength(string) - 1) * sizeof(char)) = newCharacter;
    return newString;
}