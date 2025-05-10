/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Remove quotes from a string
*/

#include "minishell.h"

void remove_quotes(char *str)
{
    while (*str) {
        if (*str == '"' || *str == '\'')
            strcpy(str, str + 1);
        else
            str++;
    }
}
