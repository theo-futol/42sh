/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Path to fullpath for PATH variable.
*/

#include "minishell.h"

void path_to_fullpath(void **path_address)
{
    size_t n = 2048;
    char *path = (char *)(*path_address);
    char *fullpath = NULL;
    char *cwd = NULL;

    if (path[0] == '/' || path[0] == '~')
        fullpath = my_strdup(path);
    else {
        cwd = getcwd(cwd, n);
        fullpath = vstr_concat(3, cwd, "/", path);
        freef("f", &cwd);
    }
    freef("f", path_address);
    *path_address = fullpath;
}
