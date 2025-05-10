/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Iskeyvar
*/

#include "minishell.h"

int is_key_var(void const *string, void const *keyname)
{
    size_t varlen = my_strlen(keyname);
    char *line = vstr_concat(2, keyname, "=");
    int res = my_strncmp((char const *)string, (char const *)line, varlen);

    if (line)
        free(line);
    return res;
}
