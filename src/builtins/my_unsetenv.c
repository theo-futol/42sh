/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Deleting an environment variable.
*/

#include "minishell.h"

int my_unsetenv(int ac, char **av, llist_t **env_vars)
{
    if (ac < 2){
        my_putstr(2, "unsetenv: Too few arguments.\n");
        return ERR_BUILTIN;
    }
    while (av[1]) {
        delete_in_list(env_vars, av[1], is_key_var);
        av++;
    }
    return 0;
}
