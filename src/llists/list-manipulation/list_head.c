/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Returns the head of a list
*/

#include "llists.h"

llist_t *list_head(llist_t **begin)
{
    llist_t *head = NULL;

    if (!begin)
        return NULL;
    if (!(*begin))
        return NULL;
    head = *begin;
    *begin = (*begin)->next;
    head->next = NULL;
    return head;
}
