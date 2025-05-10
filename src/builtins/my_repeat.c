/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Repeating a command.
*/

#include "minishell.h"

char *concat_av(int ac, char **av)
{
    char *tmp = "";
    char *line = NULL;

    for (int i = 0; i < ac; i++) {
        tmp = vstr_concat(3, tmp, " ", av[i]);
        if (!tmp)
            freef("f", &line);
        line = tmp;
        if (!line)
            break;
    }
    return line;
}

int my_repeat(int ac, char **av, llist_t **env_vars UNUSED)
{
    char *line = NULL;
    int nbr = -1;
    int res = 0;

    if (ac < 3)
        return my_putstr(2, "repeat: Too few arguments.\n"), ERR_BUILTIN;
    nbr = get_nbr(av[1]);
    if (nbr < 0 && !(av[1][0] == '-' && get_nbr(av[1] + 1) >= 0))
        return dprintf(2, "repeat: Badly formed number.\n"), ERR_BUILTIN;
    line = concat_av(ac - 2, av + 2);
    if (!line)
        return ERR_BUILTIN;
    nbr = atoi(av[1]);
    for (int i = 0; i < nbr; i++)
        res = handle_commandline(line, env_vars);
    return res;
}
