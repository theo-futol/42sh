/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Setting an alias.
*/

#include "minishell.h"

int my_unalias(int ac UNUSED, char **av, llist_t **env_vars UNUSED)
{
    av++;
    while (*av) {
        delete_in_list(&shell()->aliases, av[0], is_alias_var);
        av++;
    }
    return 0;
}
