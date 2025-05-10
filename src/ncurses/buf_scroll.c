/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** display_exec.c
*/

#include "minishell.h"

void free_buff_scroll(void)
{
    if (!shell()->win.is_open)
        return;
    for (int i = 0; i < shell()->win.index_row; i++)
        freef("f", &shell()->win.buf_scroll[i]);
    if (shell()->win.buf_scroll[shell()->win.index_row])
        freef("f", &shell()->win.buf_scroll[shell()->win.index_row]);
}

// ptr1 = ptr2 & ptr2 = ptr1
static int swap_buf(char **ptr1, char **ptr2)
{
    char *tmp = ptr1 && ptr2 ? strdup(*ptr1) : NULL;

    if (!tmp)
        return 84;
    freef("f", ptr1);
    *ptr1 = strdup(*ptr2);
    if (!(*ptr1)){
        freef("f", &tmp);
        return 84;
    }
    freef("f", ptr2);
    *ptr2 = tmp;
    return 0;
}

static int realloc_buf(screen_t *win, int new_line)
{
    if (!(win->index_row == SCROLL_MAX && new_line))
        return 0;
    for (int i = 0; i + 1 < win->index_row; i++){
        if (swap_buf(&win->buf_scroll[i], &win->buf_scroll[i + 1]) == 84)
            return 84;
    }
    win->index_row--;
    freef("f", &win->buf_scroll[win->index_row]);
    return 0;
}

static void realloc_buf_index(screen_t *win, char *add)
{
    win->buf_scroll[win->index_row] = realloc(win->buf_scroll[win->index_row],
    (int)strlen(win->buf_scroll[win->index_row]) + (int)strlen(add) + 1);
}

int add_buf_scroll(screen_t *win, int new_line, int nb, ...)
{
    va_list ap = {0};

    va_start(ap, nb);
    if (realloc_buf(win, new_line) == 84)
        return 84;
    for (char *add = NULL; nb > 0; nb--){
        add = va_arg(ap, char *);
        if (new_line == 1){
            win->buf_scroll[win->index_row] = strdup(add);
            new_line = 2;
        } else {
            realloc_buf_index(win, add);
            win->buf_scroll[win->index_row] = win->buf_scroll[win->index_row] ?
            strcat(win->buf_scroll[win->index_row], add) : NULL;
        }
        if (!win->buf_scroll[win->index_row])
            return 84;
    }
    win->index_row += new_line == 2 && win->index_row < SCROLL_MAX ? 1 : 0;
    return va_end(ap), 0;
}

int remove_buf_scroll(screen_t *win, int len)
{
    char *tmp = strndup(win->buf_scroll[win->index_row],
    (int)strlen(win->buf_scroll[win->index_row]) - len);

    if (!tmp)
        return 84;
    freef("f", &win->buf_scroll[win->index_row]);
    win->buf_scroll[win->index_row] = tmp;
    return 0;
}

void disp_buf_scroll(screen_t *win)
{
    int i = win->default_index;

    clear();
    win->index_row++;
    if (i == 0)
        if (win->index_row > win->height)
            i = (win->index_row - win->height) < win->default_index ?
            win->index_row - win->height : win->default_index;
    for (int index = 0; i < win->index_row; i++){
        if (!win->buf_scroll[i])
            continue;
        mvprintw(index, 0, "%s", win->buf_scroll[i]);
        index += (int)strlen(win->buf_scroll[i]) > win->width ? 2 : 1;
    }
    win->index_row--;
    refresh();
}
