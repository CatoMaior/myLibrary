/**
 * @file strings.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Common tasks with strings
 */

#ifndef SEEN_STRINGS
#define SEEN_STRINGS

#include "types.h"

/**
 * @brief Reads from terminal a string of arbitrary length
 * @return A char pointer to the first character of the string or the return code of the function
 * @retval NULL Errors occurred during the execution of the function
 */
string getString();

/**
 * @brief Check if a ::string ends with the specified substring
 * @param str The ::string to be inspected
 * @param suffix The ::string you want to check if `string` ends with
 * @return The return code of the function
 * @retval TRUE `str` ends with `suffix`
 * @retval FALSE `str` does not end with `suffix`
 */
byte endsWith(const string str, const string suffix);

/**
 * @brief Get a tring with different last character
 * @param str The ::string you want to change the last character
 * @param newCharacter The character you want to set as last character
 * @return A pointer to a ::string with the same characters of `str` and newCharacter as last character or the return code of the function
 * @retval NULL Errors occurred during the execution of the function
*/
string changeLastCharacter(const string str, char newCharacter);

/**
 * @brief Get a copy of the given ::string
 * @param src The ::string to be copied
 * @return A pointer to the copy of the given ::string
 */
string copyOf(const string src);

#endif