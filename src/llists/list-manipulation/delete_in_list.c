/*
** EPITECH PROJECT, 2025
** Lib_llists
** File description:
** Removes the first node containing data equal to the reference data.
*/

#include "llists.h"

bool delete_in_list(llist_t **begin, void *ref, cmp_fct_t cmp_fct)
{
    llist_t *previous = begin == NULL ? NULL : *begin;
    llist_t *actual = previous == NULL ? NULL : previous->next;

    if (!previous)
        return false;
    if (cmp_fct(previous->data, ref) == 0) {
        freef("f f", &previous->data, &previous);
        *begin = actual;
        return true;
    }
    while (actual) {
        if (cmp_fct(actual->data, ref) == 0) {
            previous->next = actual->next;
            freef("f f", &actual->data, &actual);
            return true;
        }
        previous = actual;
        actual = actual->next;
    }
    return false;
}
