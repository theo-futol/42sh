/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Redirects
*/

#include "minishell.h"

int my_and(ast_t *ast1, ast_t *ast2, llist_t **env)
{
    int res = exec_ast(ast1, env);

    return res == 0 ? exec_ast(ast2, env) : res;
}
