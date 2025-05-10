/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** mouse.c
*/

#include "minishell.h"

int handle_input_mouse(char **line, int *count)
{
    MEVENT event = {0};

    (void)line;
    (void)count;
    if (getmouse(&event) == OK){
        (*line)[*count] = 0;
        add_buf_scroll(&shell()->win, 0, 1, *line);
        if (event.bstate & BUTTON4_PRESSED)
            shell()->win.default_index -= shell()->win.default_index == 0 ? 0 :
            1;
        if (event.bstate & BUTTON5_PRESSED)
            shell()->win.default_index += shell()->win.default_index < shell()
            ->win.index_row ? 1 : 0;
        disp_buf_scroll(&shell()->win);
        remove_buf_scroll(&shell()->win, (int)strlen((*line)));
    }
    return 0;
}
