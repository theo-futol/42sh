/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** init_screen
*/

#include "minishell.h"

int init_screen(void)
{
    struct winsize size_win = {0};

    if (!isatty(0) || SCROLL_MAX == 0)
        return -1;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size_win) == -1)
        return -1;
    shell()->win.width = size_win.ws_col;
    shell()->win.height = size_win.ws_row;
    setlocale(LC_CTYPE, "");
    shell()->win.screen = initscr();
    if (!shell()->win.screen)
        return -1;
    shell()->win.is_open = 1;
    keypad(shell()->win.screen, true);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    cbreak();
    noecho();
    return 0;
}
