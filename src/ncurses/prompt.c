/*
** EPITECH PROJECT, 2025
** semester02
** File description:
** display.c
*/

#include "minishell.h"

int get_prompt(char **line, llist_t *env)
{
    int count = 0;
    int buff_size = 50;
    int cursor_pos = 0;

    *line = line ? malloc(sizeof(char) * (buff_size + 1)) : NULL;
    if (!line || !(*line) || print_prompt(env) == 84)
        return -1;
    for (unsigned char ch = 0; (ch = getch()) != '\n';){
        if (count >= buff_size && buff_size * 2 <= INT_MAX){
            buff_size *= 2;
            *line = realloc(*line, sizeof(char) * (buff_size + 1));
        }
        if (!(*line) || buff_size > INT_MAX)
            return 0;
        get_input(ch, line, &count, &cursor_pos);
    }
    (*line)[count] = 0;
    add_buf_scroll(&shell()->win, 0, count != 0 ? 1 : 0, *line);
    shell()->win.index_row++;
    return count + 1;
}
