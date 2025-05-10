/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** close_win.c
*/

#include "minishell.h"

void close_ncurse(void)
{
    endwin();
    free_buff_scroll();
    delwin(shell()->win.screen);
}
