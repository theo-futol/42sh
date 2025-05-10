/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Executing an ast.
*/

#include "minishell.h"

int error_ast(ast_t *ast)
{
    if (ast->fct == &regular_output)
        return dprintf(2, "Missing name for redirect.\n");
    if (ast->fct == &regular_output_append)
        return dprintf(2, "Missing name for redirect.\n");
    if (ast->fct == &regular_input)
        return dprintf(2, "Missing name for redirect.\n");
    return dprintf(2, "Invalid null command.\n");
}

int exec_ast(ast_t *ast, llist_t **env_vars)
{
    if (!ast)
        return 0;
    if (skip(ast->command)[0] == 0 && ast->fct != &my_semicolon) {
        my_putstr(2, "Invalid null command.\n");
        return last_result(true, 1);
    }
    if (ast->is_leaf)
        return handle_command(ast->command, env_vars);
    else {
        if (ast->sub1->command && ast->sub2->command &&
            (skip(ast->sub1->command)[0] == 0 ||
            skip(ast->sub2->command)[0] == 0) && ast->fct != &my_semicolon) {
            error_ast(ast);
            return last_result(true, 1);
        }
        return ast->fct(ast->sub1, ast->sub2, env_vars);
    }
}
