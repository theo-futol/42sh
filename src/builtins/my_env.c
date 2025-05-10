/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Displaying all environment variables.
*/

#include "minishell.h"

int my_env(int ac, char **av, llist_t **env_vars)
{
    (void)av;
    if (ac != 1)
        return ERR_BUILTIN;
    display_list(*env_vars, &newline_putnode);
    return 0;
}
