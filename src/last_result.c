/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Last Result
*/

#include "minishell.h"

// True is for setting new value, false is for getting it.
int last_result(bool mode, int new_value)
{
    char *variable = NULL;

    if (mode) {
        shell()->res = new_value;
        asprintf(&variable, "?=%d", new_value);
        delete_in_list(&shell()->local_env, "?", is_key_var);
        if (variable && !push_to_list(&shell()->local_env, variable))
            freef("f", &variable);
    }
    return shell()->res;
}
