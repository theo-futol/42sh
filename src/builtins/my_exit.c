/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Exiting minishell.
*/

#include "minishell.h"

int my_exit(int ac UNUSED, char **av UNUSED, llist_t **env_vars UNUSED)
{
    if (isatty(0))
        free_buff_scroll();
    shell()->active = false;
    return 0;
}
