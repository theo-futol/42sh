/*
** EPITECH PROJECT, 2025
** semester02
** File description:
** inputs.c
*/

#include "minishell.h"

const input_t inputs[] = {
    {4, &handle_input_left},
    {5, &handle_input_right},
    {7, &handle_input_del},
    {153, &handle_input_mouse},
    {-1, NULL}
};

static int get_pos_y(void)
{
    int y = 0;
    int x = 0;

    (void)x;
    getyx(shell()->win.screen, y, x);
    return y;
}

static void automatic_scroll(void)
{
    if (shell()->win.default_index < shell()->win.index_row && shell()->win.
        index_row > shell()->win.height + shell()->win.default_index)
        shell()->win.default_index = shell()->win.index_row;
}

int get_input(int key, char *line, int *count, int *cursor_pos)
{
    int len = (int)strlen(shell()->win.buf_scroll[shell()->win.index_row]);
    int result = -1;

    for (int i = 0; inputs[i].fct != NULL; i++)
        if (key == inputs[i].key)
            result = inputs[i].fct(line, count, cursor_pos);
    if (result != 0) {
        automatic_scroll();
        memmove(&line[*cursor_pos + 1], &line[*cursor_pos], *count -
        *cursor_pos + 1);
        line[*cursor_pos] = key;
        (*count)++;
        (*cursor_pos)++;
        line[*count] = 0;
        move(shell()->win.index_row, len + *cursor_pos);
    }
    disp_buf_scroll(&shell()->win);
    if (line && *count > 0)
        mvprintw(get_pos_y(), len, "%s", line);
    return move(shell()->win.index_row, len + *cursor_pos), refresh(), 0;
}
