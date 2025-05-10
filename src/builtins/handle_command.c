/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Handles either builtin commands or others.
*/

#include "minishell.h"

const builtin_t builtins[] = {
    {"cd", &my_cd},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"env", &my_env},
    {"set", &my_set},
    {"unset", &my_unset},
    {"local", &my_local},
    {"exit", &my_exit},
    {"history", &my_history},
    {"alias", &my_alias},
    {"unalias", &my_unalias},
    {"clear", &my_clear},
    {"which", &my_which},
    {"where", &my_where},
    {"repeat", &my_repeat},
    {0}
};

int is_builtin(char *str)
{
    for (int i = 0; builtins[i].command; i++)
        if (my_strcmp(str, builtins[i].command_name) == 0)
            return 1;
    return 0;
}

int handle_command(char *command, llist_t **env_vars)
{
    char **av = str_to_formatted_argv(command, SEPARATORS);
    int ac = 0;
    int res = 0;

    if (!av)
        return last_result(true, 1);
    for (int i = 0; av[i]; i++)
        remove_quotes(av[i]);
    for (int i = 0; builtins[i].command; i++)
        if (my_strcmp(av[0], builtins[i].command_name) == 0){
            ac = arr_len((void const **)av);
            res = last_result(1, builtins[i].command(ac, av, env_vars));
            freef("a", &av);
            return res;
        }
    res = last_result(true, fork_and_print(av, *env_vars));
    return freef("a", &av), res;
}

int handle_commandline(char *commandline, llist_t **env_vars)
{
    int res = 0;
    ast_t *ast = NULL;
    bool save = false;

    if (!commandline)
        return 84;
    if (!is_blank(commandline)){
        save = commandline[0] != ' ';
        ast = create_ast(commandline);
        res = exec_ast(ast, env_vars);
        if (save)
            history_save(ast);
        free_ast(&ast);
    }
    return res;
}
