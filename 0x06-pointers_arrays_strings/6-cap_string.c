#include "main.h"
#include <stdbool.h>

/**
 * is_separator - Checks if a character is a separator.
 * @c: The character to check.
 * Return: True if c is a separator, otherwise false.
 */
bool is_separator(char c)
{
    char separators[] = " \t\n,;.!?\"(){}";

    for (int i = 0; separators[i] != '\0'; i++)
    {
        if (separators[i] == c)
            return true;
    }

    return false;
}

/**
 * cap_string - Capitalizes all words of a string.
 * @s: The input string.
 * Return: Pointer to the modified string s.
 */
char *cap_string(char *s)
{
    bool new_word = true;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (is_separator(s[i]))
        {
            new_word = true;
        }
        else if (new_word)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
            
            new_word = false;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }

    return s;
}
