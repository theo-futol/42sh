/*
** EPITECH PROJECT, 2025
** Liblists
** File description:
** Concats n strings together.
*/

#include "llists.h"

#include <stdio.h>
char *concat(size_t flen, char **wa)
{
    char *str = wa ? my_calloc(flen + 1, sizeof(char)) : NULL;
    int word_i = 0;
    size_t i = 0;

    if (!str)
        return NULL;
    while (wa[word_i] && i < flen) {
        my_strcpy(str + i, wa[word_i]);
        i += my_strlen(wa[word_i]);
        word_i++;
    }
    freef("a", &wa);
    return str;
}

char *vstr_concat(int n, ...)
{
    va_list ap;
    size_t full_len = 0;
    char **wa = n > 0 ? my_calloc(n + 1, sizeof(char *)) : NULL;
    char *str = NULL;
    int i = 0;

    if (!wa)
        return NULL;
    va_start(ap, n);
    while (i < n) {
        wa[i] = my_strdup(va_arg(ap, char *));
        full_len += my_strlen(wa[i]);
        i++;
    }
    va_end(ap);
    str = concat(full_len, wa);
    return str;
}
