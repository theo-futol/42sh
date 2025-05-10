/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Formatting line
*/

#include "minishell.h"

// String can be "ll=ls -la" while aliasname can be "ll ./directory"
int is_alias_var(const void *var, const void *command)
{
    char *varname = my_strndup(var, strlen_to(var, '='));
    char *dup = my_strdup((const char *)command);
    int cmp = my_strcmp(single_word(dup), varname);

    freef("f f", &varname, &dup);
    return cmp;
}
// Imagine cmp equals to 32 but no space...
