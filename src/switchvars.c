/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Switching variables from env, and writing its content
*/

#include "minishell.h"

void switchvars(char *str, llist_t *env_vars)
{
    llist_t *node = NULL;
    size_t len = my_strlen(str);
    char *line = NULL;

    if (!str || !env_vars)
        return;
    node = find_node(env_vars, str, &is_key_var);
    if (!node)
        dprintf(1, "$%s", str);
    else {
        line = (char *)node->data + 1;
        write(1, line + len, my_strlen(line + len));
    }
}
