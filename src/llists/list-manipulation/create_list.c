/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Creates nodes from the given values and function.
*/

#include "llists.h"

llist_t *create_list(void *(*extract)(void *), int nb, ...)
{
    va_list ap;
    llist_t *list = NULL;
    void *data = NULL;

    va_start(ap, nb);
    while (nb > 0) {
        data = va_arg(ap, void *);
        if (extract)
            push_to_list(&list, extract(data));
        else
            push_to_list(&list, data);
        nb -= 1;
    }
    va_end(ap);
    rev_list(&list);
    return list;
}
