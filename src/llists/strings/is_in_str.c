/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Checks if a character is in a string.
*/

#include "llists.h"

bool is_in_str(char c, const char *str)
{
    if (!str)
        return false;
    for (; *str; str++) {
        if (*str == c)
            return true;
    }
    return false;
}
