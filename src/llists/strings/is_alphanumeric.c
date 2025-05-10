/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Var names
*/

#include "llists.h"

bool is_alpha_char(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool is_numeric_char(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_alphanumeric_char(char c)
{
    return is_alpha_char(c) || is_numeric_char(c);
}

bool is_numeric(char *str)
{
    for (; *str; str++)
        if (!is_numeric_char(*str))
            return false;
    return true;
}

bool is_alphanumeric(char *str)
{
    for (; *str; str++) {
        if (!is_alphanumeric_char(*str))
            return false;
    }
    return true;
}
