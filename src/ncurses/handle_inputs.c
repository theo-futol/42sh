/*
** EPITECH PROJECT, 2025
** semester02
** File description:
** handle_inputs.c
*/

#include "minishell.h"

int handle_input_left(char *line, int *count, int *cursor_pos)
{
    (void)line;
    (void)count;
    if (*cursor_pos > 0) {
        (*cursor_pos)--;
        move(shell()->win.index_row, *cursor_pos);
        refresh();
    }
    return 0;
}

int handle_input_right(char *line, int *count, int *cursor_pos)
{
    (void)line;
    (void)count;
    if (*cursor_pos < *count) {
        (*cursor_pos)++;
        move(shell()->win.index_row, *cursor_pos);
        refresh();
    }
    return 0;
}

int handle_input_del(char *line, int *count, int *cursor_pos)
{
    if (*count > 0 && *cursor_pos > 0) {
        memmove(&line[*cursor_pos - 1], &line[*cursor_pos], *count -
        *cursor_pos + 1);
        (*count)--;
        (*cursor_pos)--;
    }
    return 0;
}
