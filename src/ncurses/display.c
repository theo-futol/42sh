/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** display.c
*/

#include "minishell.h"

int redirection_tty(int pipefd[2], int *saved_stdout, int *saved_stderr)
{
    if (!isatty(0))
        return 0;
    *saved_stdout = dup(STDOUT_FILENO);
    *saved_stderr = dup(STDERR_FILENO);
    if (dup2(pipefd[1], STDOUT_FILENO) == -1)
        return 84;
    if (dup2(pipefd[1], STDERR_FILENO) == -1)
        return 84;
    close(pipefd[1]);
    return 0;
}

int display_output(int pipefd[2], int saved_stdout, int saved_stderr)
{
    char *line = NULL;
    FILE *stream = isatty(0) ? fdopen(pipefd[0], "r") : NULL;
    size_t len = 0;

    if (!stream)
        return 84;
    close(pipefd[1]);
    if (dup2(saved_stdout, STDOUT_FILENO) == -1)
        return 84;
    if (dup2(saved_stderr, STDERR_FILENO) == -1)
        return 84;
    close(saved_stdout);
    while (getline(&line, &len, stream) > 0)
        add_buf_scroll(&shell()->win, 1, 1, line);
    fclose(stream);
    freef("f", &line);
    close(pipefd[0]);
    return 0;
}
