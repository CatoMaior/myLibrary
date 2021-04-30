/**
 * @file strings.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Common tasks with strings
 */

#include "types.h"

/**
 * @brief Reads from terminal a string of arbitrary length
 * @return A char pointer to the first element of the string or a null pointer in case of errors 
 */
char *getString();

/**
 * @brief Check if a string ends with the specified substring
 * @param string The string to be inspected
 * @param suffix The string you want to check if `string`ends with
 * @return A boolean value
 * @retval TRUE `string` ends with `suffix`
 * @retval FALSE `string` does not end with `suffix`
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
byte endsWith(const char *string, const char *suffix);

/**
 * @brief Get string with different last character
 * @param string The string you want to change the last character
 * @param newCharacter The character you want to set as last character
 * @return A pointer to a string with the same characters of `string` and newCharacter as last character or a null pointer in case of errors
 */
char *changeLastCharacter(char *string, char newCharacter);

/**
 * @brief Get the lenght of a string
 * @param string pointer to the first element of the string to be evaluated
 * @return The lenght of the given string or the error code of the function
 * @retval NULL_POINTER_GIVEN At least one among given pointers was NULL
 */
unsigned int getLength(const char *string);

/**
 * @brief Get a copy of the given string
 * @param src The string to be copied
 * @return A pointer to the copy of the given string or or a null pointer in case of errors 
 */
char *copyOf(const char *src);