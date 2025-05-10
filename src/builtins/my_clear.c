/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** my_clear.c
*/

#include "minishell.h"

int my_clear(int ac, char **av, llist_t **env_vars)
{
    (void)env_vars;
    (void)av;
    (void)ac;
    if (!shell()->win.is_open)
        return 0;
    free_buff_scroll();
    shell()->win.default_index = 0;
    shell()->win.index_row = 0;
    return 0;
}
