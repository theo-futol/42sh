/*
** EPITECH PROJECT, 2025
** Minishell1
** File description:
** Duplicates the env.
*/

#include "minishell.h"

llist_t *dupenv(char **env)
{
    llist_t *env_vars = word_array_to_list(env);

    if (env[0] && !env_vars)
        exit(84);
    return env_vars;
}
