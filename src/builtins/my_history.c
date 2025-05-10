/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Setting / overwriting an environment variable.
*/

#include "minishell.h"

int cat_file(int fd)
{
    struct stat sbuff = {0};
    int statres = fstat(fd, &sbuff);
    char *buffer = my_calloc(sbuff.st_size + 1, sizeof(char));
    ssize_t bytes = 0;

    if (statres != 0 && !buffer)
        return 84;
    bytes = read(fd, buffer, sbuff.st_size);
    if (bytes < 0) {
        free(buffer);
        return 84;
    }
    write(1, buffer, bytes);
    free(buffer);
    return 0;
}

int my_history(int ac, char **av, llist_t **env_vars)
{
    int fd = 0;

    (void)av;
    (void)env_vars;
    if (ac == 2 && my_strcmp(av[1], "-c") == 0)
        fd = open(*history_path(), O_CREAT | O_TRUNC | O_WRONLY, 0660);
    if (ac == 1) {
        fd = open(*history_path(), O_CREAT | O_RDONLY, 0660);
        if (fd < 0)
            return 84;
        return cat_file(fd);
    }
    if (fd > 0) {
        close(fd);
        return 0;
    }
    return 84;
}
