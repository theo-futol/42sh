/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Setting an alias.
*/

#include "minishell.h"

int my_alias(int ac, char **av, llist_t **env_vars UNUSED)
{
    char *line = NULL;

    if (ac == 1)
        return my_env(ac, av, &shell()->aliases);
    if (ac == 2)
        return my_putstr(2, "alias: Too few arguments.\n"), ERR_BUILTIN;
    if (ac > 3)
        return my_putstr(2, "alias: Too many arguments.\n"), ERR_BUILTIN;
    if (my_strlen(av[1]) != strlen_to(av[1], '='))
        return my_putstr(2, "alias: Bad formatting.\n"), ERR_BUILTIN;
    if (av[2])
    line = vstr_concat(3, av[1], "=", av[2]);
    av[1][strlen_to(av[1], '=')] = 0;
    if (!line)
        return ERR_BUILTIN;
    delete_in_list(&shell()->aliases, av[1], is_key_var);
    push_to_list(&shell()->aliases, line);
    return 0;
}
