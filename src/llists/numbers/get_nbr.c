/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Gets a number from string. Returns -1 in error cases.
*/

#include "llists.h"

int get_nbr(char *line)
{
    int res = 0;

    if (!line)
        return -1;
    while (is_numeric_char(*line)) {
        res *= 10;
        res += *line - '0';
        line++;
    }
    if (*line)
        return -1;
    return res;
}
