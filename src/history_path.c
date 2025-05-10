/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** History path
*/

#include "minishell.h"

char **history_path(void)
{
    char dir[256] = "";
    size_t n = 255;

    if (!shell()->history_path)
        shell()->history_path = vstr_concat(3, getcwd(dir, n), "/", HISTORY);
    return &shell()->history_path;
}

void write_ast(int fd, ast_t *ast)
{
    if (ast->is_leaf && ast->command) {
        dprintf(fd, "%s", ast->command);
        return;
    }
    write_ast(fd, ast->sub1);
    dprintf(fd, " %s ", find_redirect_string(ast->fct));
    write_ast(fd, ast->sub2);
}

void history_save(ast_t *ast)
{
    int fd = 0;

    fd = open(*history_path(), O_CREAT | O_APPEND | O_WRONLY, 0660);
    if (fd < 0)
        return;
    write_ast(fd, ast);
    write(fd, "\n", 1);
    close(fd);
}
