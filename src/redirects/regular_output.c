/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Redirects
*/

#include "minishell.h"

int output_to_file(char *command)
{
    char *filename = single_word(command);
    int file_fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0664);
    int res = 0;

    if (file_fd <= 0)
        return perror(filename), 1;
    res = dup2(file_fd, STDOUT_FILENO);
    if (res == -1)
        return close(file_fd), -1;
    return file_fd;
}

int regular_output(ast_t *ast1, ast_t *ast2, llist_t **env)
{
    int pid = 0;
    int res = 0;
    int status = 0;
    int fd = 0;

    pid = fork();
    if (pid < 0)
        return perror("Unable to fork "), last_result(true, 1);
    if (pid == 0) {
        fd = output_to_file(ast2->command);
        res = fd != -1 ? exec_ast(ast1, env) : 1;
        if (fd != 1)
            close(fd);
        exit(res);
    }
    waitpid(pid, &status, 0);
    return last_result(true, status);
}
