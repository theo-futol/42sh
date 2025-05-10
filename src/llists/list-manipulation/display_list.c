/*
** EPITECH PROJECT, 2024
** bs_organized
** File description:
** truc
*/

#include "minishell.h"

void dft_putnode(void *s)
{
    char *str = (char *)((llist_t *)s)->data;

    my_putstr(1, str);
}

void newline_putnode(void *s)
{
    char *str = (char *)((llist_t *)s)->data;

    vput_str(1, 2, str, "\n");
}

void display_list(llist_t *begin, void(*disp_fct)(void *))
{
    if (begin != NULL){
        disp_fct(begin);
        display_list(begin->next, disp_fct);
    }
}
