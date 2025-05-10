/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Searches for an environment variable named var, and returns its content
*/

#include "minishell.h"

char *search_env_var(llist_t *env_vars, char *var)
{
    int var_len = my_strlen(var);
    llist_t *locals = shell()->local_env;
    char *data = NULL;

    if (var_len <= 0)
        return NULL;
    while (locals) {
        data = (char *)(locals->data);
        if (my_strncmp(data, var, var_len - 1) == 0 && data[var_len] == '=')
            return my_strdup(locals->data + var_len + 1);
        locals = locals->next;
    }
    while (env_vars) {
        data = (char *)(env_vars->data);
        if (my_strncmp(data, var, var_len - 1) == 0 && data[var_len] == '=')
            return my_strdup(env_vars->data + var_len + 1);
        env_vars = env_vars->next;
    }
    return NULL;
}
