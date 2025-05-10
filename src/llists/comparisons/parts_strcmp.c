/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Comparison between multiple strings. The last argument should be NULL.
*/

#include "llists.h"

int parts_strcmp(char *string, char *first_part, ...)
{
    va_list ap;
    size_t len = my_strlen(first_part);
    int cmp_res = 0;

    if (!string)
        return -1;
    va_start(ap, first_part);
    while (first_part) {
        cmp_res = my_strncmp(string, first_part, len - 1);
        if (cmp_res != 0)
            return cmp_res;
        string += len;
        first_part = va_arg(ap, char *);
        len = my_strlen(first_part);
    }
    va_end(ap);
    return 0;
}
