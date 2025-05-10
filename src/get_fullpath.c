/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Gets fullpath from the given relative path.
*/

#include "minishell.h"

char *switch_fullpath(char *path, llist_t *env_vars)
{
    size_t n = 2048;
    char *cwd = NULL;
    char *fullpath = NULL;
    llist_t *node = NULL;

    switch (path[0]) {
        case '/' :
            return my_strdup(path);
        case '~' :
            node = find_node(env_vars, "HOME", is_key_var);
            if (node)
                return vstr_concat(2, (char *)node->data + 5, path + 1);
            return NULL;
        default:
            cwd = getcwd(cwd, n);
            fullpath = vstr_concat(3, cwd, "/", path);
            free(cwd);
            return fullpath;
    }
}

char *get_fullpath(char *path, llist_t *env_vars)
{
    llist_t *node = NULL;

    if (!path)
        return NULL;
    if (my_strcmp(path, "-") == 0) {
        node = find_node(env_vars, "OLDPWD", is_key_var);
        if (!node)
            my_putstr(2, ": No such file or directory.\n");
        return node ? my_strdup((char *)node->data + 7) : NULL;
    }
    return switch_fullpath(path, env_vars);
}
