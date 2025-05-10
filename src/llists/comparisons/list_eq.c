/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Checking equality of each node with a given function.
** Returns either 1 on inequality or 0 on equality.
*/

#include "llists.h"

int list_eq(llist_t *list, cmp_fct_t cmp, int nb, ...)
{
    va_list ap;
    int cmp_res = 0;

    if (!list || !cmp)
        return 1;
    va_start(ap, nb);
    while (nb > 0) {
        cmp_res = cmp(va_arg(ap, void *), list->data);
        if (cmp_res != 0)
            return cmp_res;
        list = list->next;
        nb -= 1;
    }
    va_end(ap);
    return 0;
}
