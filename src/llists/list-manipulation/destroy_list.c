/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Deallocates a linked_list structure.
*/

#include "llists.h"

void destroy_list(llist_t *list, void (*destroy_node)(void *))
{
    if (!list)
        return;
    if (list->next == NULL) {
        if (destroy_node)
            destroy_node(list->data);
        free(list);
        return;
    }
    destroy_list(list->next, destroy_node);
    if (destroy_node)
        destroy_node(list->data);
    free(list);
}
