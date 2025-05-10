/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Setting / overwriting an environment variable.
*/

#include "minishell.h"

static bool verify_variable_name(char *str)
{
    if (!str)
        return false;
    if (!is_alpha_char(str[0])) {
        my_putstr(2, "setenv: Variable name must begin with a letter.\n");
        return false;
    }
    if (!is_alphanumeric(str)) {
        my_putstr(2, "setenv: Variable name must "
        "contain alphanumeric characters.\n");
        return false;
    }
    return true;
}

int my_setenv(int ac, char **av, llist_t **env_vars)
{
    char *line = NULL;

    if (ac < 2)
        return my_env(ac, av, env_vars);
    if (ac > 3) {
        my_putstr(2, "setenv: Too many arguments.\n");
        return ERR_BUILTIN;
    }
    if (!verify_variable_name(av[1])) {
        return ERR_BUILTIN;
    }
    line = vstr_concat(3, av[1], "=", av[2]);
    if (!line)
        return ERR_BUILTIN;
    delete_in_list(env_vars, av[1], is_key_var);
    push_to_list(env_vars, line);
    return 0;
}
