/*
** EPITECH PROJECT, 2025
** LibLlists
** File description:
** Freeeee
*/

#include "llists.h"

char *my_strdup(const char *str)
{
    int n = my_strlen(str);
    char *new = str ? my_calloc(n + 1, sizeof(char)) : NULL;
    char *new_start = new;

    if (!new)
        return NULL;
    for (; str[0]; str++) {
        new[0] = str[0];
        new++;
    }
    new[0] = 0;
    return new_start;
}
