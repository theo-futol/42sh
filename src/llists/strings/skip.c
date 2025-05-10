/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Skips tabs, spaces and newlines from a string.
*/

#include "llists.h"

char *skip(char *str)
{
    if (!str)
        return str;
    while (is_in_str(*str, " \t\n"))
        str++;
    return str;
}
