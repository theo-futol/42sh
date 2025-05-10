/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Executing an ast.
*/

#include "minishell.h"

ast_t *create_ast(char *whole)
{
    ast_t *ast = my_calloc(1, sizeof(ast_t));
    nfct_t nfct = {0};

    if (!ast)
        return NULL;
    ast->command = my_strdup(whole);
    if (!ast->command)
        return free(ast), NULL;
    nfct = cut_on_redirections(whole);
    if (nfct.name) {
        ast->sub1 = create_ast(whole);
        ast->sub2 = create_ast(skip(nfct.name));
        ast->fct = nfct.fct;
        free(nfct.name);
    } else
        ast->is_leaf = true;
    return ast;
}

void free_ast(ast_t **ast)
{
    if (!(*ast))
        return;
    free_ast(&(*ast)->sub1);
    free_ast(&(*ast)->sub2);
    if ((*ast)->command)
        free((*ast)->command);
    free(*ast);
    *ast = NULL;
}
