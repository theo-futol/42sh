/*
** EPITECH PROJECT, 2025
** semester02
** File description:
** inputs.c
*/

#include "minishell.h"

const input_t inputs[] = {
    {4, &handle_input_left, true},
    {5, &handle_input_right, false},
    {7, &handle_input_del, true},
    {9, &handle_tab, false},
    {153, &handle_input_mouse, true},
    {2, &handle_input_up, true},
    {3, &handle_input_down, true},
    {-1, NULL, false}
};

const int special_char[] = {15, 16, 39, 44,
    27, 18, 20, 21, 22, 24, 6, 25, 8, 11, 5, 10, 14, -1};

static int check_specialchar(int key)
{
    for (int i = 0; special_char[i] != -1; i++)
        if (key == special_char[i])
            return -1;
    return 0;
}

static void automatic_scroll(void)
{
    if (shell()->win.default_index < shell()->win.index_row && shell()->win.
        index_row > shell()->win.height + shell()->win.default_index)
        shell()->win.default_index = shell()->win.index_row;
}

static void set_character(char **line, int *count, int *cursor_pos, int key)
{
    memmove(&(*line)[*cursor_pos + 1], &(*line)[*cursor_pos], *count -
        *cursor_pos + 1);
    (*line)[*cursor_pos] = key;
    (*count)++;
    (*cursor_pos)++;
    (*line)[*count] = 0;
}

static int refresh_cursor(int len, int *cursor_pos, bool move)
{
    if (!move)
        return 0;
    move(shell()->win.index_row, len + *cursor_pos);
    refresh();
    return 0;
}

int get_input(int key, char **line, int *count, int *cursor_pos)
{
    int len = (int)strlen(shell()->win.buf_scroll[shell()->win.index_row]);
    int result = -1;
    int i = 0;

    for (i = 0; inputs[i].fct != NULL; i++)
        if (key == inputs[i].key){
            result = inputs[i].fct(line, count, cursor_pos);
            break;
        }
    if (result != 0 && check_specialchar(key) == 0) {
        automatic_scroll();
        set_character(line, count, cursor_pos, key);
    }
    if (inputs[i].disp_buf || result != 0){
        disp_buf_scroll(&shell()->win);
        if ((*line) && *count > 0)
            mvprintw(getcury(shell()->win.screen), len, "%s", (*line));
    }
    return refresh_cursor(len, cursor_pos, inputs[i].disp_buf);
}
