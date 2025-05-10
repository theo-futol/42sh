/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Len to a specified char
*/

#include "minishell.h"

size_t strlen_to(const char *str, char c)
{
    const char *p = str;

    if (!str)
        return 0;
    while (*p) {
        if (*p == c)
            return p - str;
        p++;
    }
    return p - str;
}
