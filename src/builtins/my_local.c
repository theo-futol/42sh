/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Displaying all environment variables.
*/

#include "minishell.h"

int my_local(int ac, char **av, llist_t **env_vars UNUSED)
{
    (void)av;
    if (ac != 1)
        return ERR_BUILTIN;
    display_list(shell()->local_env, &newline_putnode);
    return 0;
}
