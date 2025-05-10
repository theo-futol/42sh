/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** SingleWord, modifies the original string by adding a terminating null-byte,
** and returning the beginning of the found word.
*/

#include "minishell.h"

char *single_word(char *str)
{
    size_t i = 0;

    str = skip(str);
    if (!str)
        return NULL;
    while (str[i] && !is_in_str(str[i], SEPARATORS))
        i++;
    str[i] = 0;
    return str;
}
