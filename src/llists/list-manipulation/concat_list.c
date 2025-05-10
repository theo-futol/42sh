/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Concat llists, but the src list is inserted in reversed order.
*/

#include "llists.h"

void concat_list(llist_t **dest, llist_t *src)
{
    llist_t *tmp = NULL;

    while (src) {
        tmp = src;
        src = src->next;
        tmp->next = *dest;
        *dest = tmp;
    }
}
