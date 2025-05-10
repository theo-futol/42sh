/*
** EPITECH PROJECT, 2025
** Lib_llists
** File description:
** Returns the first node containing data equal to the reference data.
*/

#include "llists.h"

llist_t *find_node(llist_t *node, void *ref, cmp_fct_t cmp_fct)
{
    while (node) {
        if (cmp_fct(node->data, ref) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
