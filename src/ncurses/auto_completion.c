/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** auto_completion.c
*/

#include "minishell.h"


void disp_file(void *s)
{
    char *str = (char *)((llist_t *)s)->data;

    mvprintw(getcury(shell()->win.screen) + 1, 0, "%s", str);
}

static char *get_origin(char **arr)
{
    char *tmp = NULL;
    int len = 0;

    if (!arr)
        return NULL;
    tmp = strdup(arr[arr_len((const void **)arr) - 1]);
    if (!tmp)
        return freef("a", &arr), NULL;
    len = strlen(tmp);
    tmp = realloc(tmp, sizeof(char) * (len + 2));
    if (!tmp)
        return freef("a", &arr), NULL;
    tmp[len] = '*';
    tmp[len + 1] = 0;
    freef("a", &arr);
    return tmp;
}

// how free linked list?
int handle_tab(char **line, int *count, int *cursor_pos)
{
    char **arr = str_to_word_array(*line, " ");
    char *origin = get_origin(arr);
    llist_t *list = NULL;

    (void)cursor_pos;
    (void)count;
    if (!origin)
        return 1;
    list = generate_pattern_match(origin);
    if (!list)
        return 1;
    display_list(list, &disp_file);
    return 0;
}
