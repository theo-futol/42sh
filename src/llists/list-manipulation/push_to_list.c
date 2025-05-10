/*
** EPITECH PROJECT, 2024
** bs_organized
** File description:
** push_to_list
*/

#include "llists.h"
#include <stdio.h>
bool push_to_list(llist_t **begin, void *data)
{
    llist_t *node = begin ? my_calloc(1, sizeof(llist_t)) : NULL;

    if (node == NULL)
        return false;
    node->data = data;
    node->next = *begin;
    *begin = node;
    return true;
}
