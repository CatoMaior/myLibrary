/**
 * @file strings.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Common tasks with strings
 */

#ifndef _SEEN_STRINGS
#define _SEEN_STRINGS

#include "types.h"

/**
 * @brief Reads from terminal a string of arbitrary length
 * @return A char pointer to the first element of the string or a null pointer in case of errors 
 */
string getString();

/**
 * @brief Check if a string ends with the specified substring
 * @param str The string to be inspected
 * @param suffix The string you want to check if `string`ends with
 * @return A boolean value
 * @retval TRUE `str` ends with `suffix`
 * @retval FALSE `str` does not end with `suffix`
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
byte endsWith(const string str, const string suffix);

/**
 * @brief Get string with different last character
 * @param str The string you want to change the last character
 * @param newCharacter The character you want to set as last character
 * @return A pointer to a string with the same characters of `str` and newCharacter as last character or a null pointer in case of errors
 */
string changeLastCharacter(const string str, char newCharacter);

/**
 * @brief Get the lenght of a string
 * @param str The string to be evaluated
 * @return The lenght of the given string (terminator EXCLUDED) or the return code of the function
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
unsigned int getLength(const string str);

/**
 * @brief Get a copy of the given string
 * @param src The string to be copied
 * @return A pointer to the copy of the given string or or a null pointer in case of errors 
 */
string copyOf(const string src);

#endif