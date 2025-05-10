/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Strndup
*/

#include "llists.h"

char *my_strndup(const char *str, int n)
{
    char *new = my_calloc(n + 1, sizeof(char));
    char *new_start = new;

    if (!new)
        return NULL;
    for (; str[0] && n > 0; str++) {
        new[0] = str[0];
        new++;
        n--;
    }
    new[0] = 0;
    return new_start;
}
