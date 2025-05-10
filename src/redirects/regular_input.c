/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Redirects
*/

#include "minishell.h"

int child_file(ast_t *ast, int pipefd[2])
{
    char *filename = single_word(ast->command);
    char buffer[PIPE_BUF + 1] = {0};
    int file_fd = 0;
    int chars = 0;

    if (!filename)
        return 1;
    close(pipefd[0]);
    dup2(pipefd[1], 1);
    file_fd = open(filename, O_RDONLY);
    if (file_fd < 0)
        return perror(filename), close(pipefd[1]), 1;
    chars = read(file_fd, buffer, PIPE_BUF);
    while (chars > 0) {
        write(pipefd[1], buffer, chars);
        chars = read(file_fd, buffer, PIPE_BUF);
    }
    return close(file_fd), close(pipefd[1]), 1;
}

int regular_input(ast_t *ast1, ast_t *ast2, llist_t **env)
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
        exit(last_result(true, child_file(ast2, pipefd)));
    close(pipefd[1]);
    dup2(pipefd[0], 0);
    res = exec_ast(ast1, env);
    close(pipefd[0]);
    dup2(saved_stdin, 0);
    close(saved_stdin);
    return res;
}
