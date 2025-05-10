/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Takes adress of a list, reverses it and returns it.
** Returns NULL on failure.
*/

#include "llists.h"

llist_t *rev_list(llist_t **list_ptr)
{
    llist_t *tmp = list_ptr ? *list_ptr : NULL;
    llist_t *list = NULL;

    if (!tmp)
        return NULL;
    while (tmp) {
        push_to_list(&list, tmp->data);
        tmp = tmp->next;
    }
    destroy_list(*list_ptr, NULL);
    *list_ptr = list;
    return *list_ptr;
}
