/*
** EPITECH PROJECT, 2025
** LibLlists
** File description:
** Mapping a list.
*/

#include "llists.h"

void my_map(llist_t *list, void (*apply_fct)(void **))
{
    if (!apply_fct)
        return;
    while (list) {
        apply_fct(&list->data);
        list = list->next;
    }
}
