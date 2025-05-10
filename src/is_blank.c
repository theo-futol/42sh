/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Is blank.
*/

#include "minishell.h"

bool is_blank(char *str)
{
    while (str[0] && (is_in_str(str[0], SEPARATORS) || *str == ';'))
        str++;
    if (str[0])
        return false;
    return true;
}
