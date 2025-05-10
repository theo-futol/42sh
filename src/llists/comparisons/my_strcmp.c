/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** Function that compares two strings,
** given as arguments.
*/

#include "llists.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    if (!s1 && !s2)
        return 0;
    if (!s1)
        return 0 - s2[0];
    if (!s2)
        return s1[0];
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            break;
        i++;
    }
    return s1[i] - s2[i];
}

int test_strcmp(const void *s1, const void *s2)
{
    return my_strcmp((const char *)s1, (const char *)s2);
}
