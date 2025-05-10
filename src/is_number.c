/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Strings is an integer ?
*/

#include "minishell.h"

bool is_number(char *str)
{
    if (!str)
        return false;
    if (*str != '-' && !is_numeric_char(*str))
        return false;
    return is_numeric(str + 1);
}
