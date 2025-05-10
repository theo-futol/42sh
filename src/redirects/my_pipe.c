/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Redirects
*/

#include "minishell.h"

void child_pipe(ast_t *ast, llist_t **env, int pipefd[2])
{
    int res = 0;

    close(pipefd[0]);
    dup2(pipefd[1], 1);
    res = exec_ast(ast, env);
    close(pipefd[1]);
    exit(res);
}

int my_pipe(ast_t *ast1, ast_t *ast2, llist_t **env)
{
    int pipefd[2] = {0, 0};
    int pipe_res = pipe(pipefd);
    int pid = 0;
    int res = 0;
    int saved_stdin = dup(0);

    if (pipe_res != 0)
        return perror("Failed to pipe "), last_result(true, 1);
    pid = fork();
    if (pid < 0)
        return perror("Unable to fork "), last_result(true, 1);
    if (pid == 0)
        child_pipe(ast1, env, pipefd);
    close(pipefd[1]);
    dup2(pipefd[0], 0);
    res = exec_ast(ast2, env);
    close(pipefd[0]);
    dup2(saved_stdin, 0);
    close(saved_stdin);
    return res;
}
