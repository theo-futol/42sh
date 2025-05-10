/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Redirects
*/

#include "minishell.h"

int my_semicolon(ast_t *ast1, ast_t *ast2, llist_t **env)
{
    int res = 0;

    if (skip(ast1->command)[0])
        res = exec_ast(ast1, env);
    if (skip(ast2->command)[0])
        res = exec_ast(ast2, env);
    return res;
}
