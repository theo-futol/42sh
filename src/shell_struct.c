/*
** EPITECH PROJECT, 2025
** Shell
** File description:
** Shell static
*/

#include "minishell.h"

shell_t *shell(void)
{
    static shell_t *shell = NULL;

    if (!shell) {
        shell = my_calloc(1, sizeof(shell_t));
        push_to_list(&shell->local_env, strdup("PORT=4444"));
        push_to_list(&shell->local_env, strdup("IP=127.0.0.1"));
        push_to_list(&shell->local_env, strdup("?=0"));
    }
    return shell;
}
