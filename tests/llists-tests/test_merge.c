/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(merge, concat_sorted)
{
    llist_t *res = NULL;
    llist_t *left = NULL;
    llist_t *right = NULL;
    cmp_fct_t *fcts = my_calloc(2, sizeof(cmp_fct_t));

    fcts[0] = test_strcmp;
    push_to_list(&left, "F");
    push_to_list(&left, "B");
    push_to_list(&left, "A");
    push_to_list(&right, "E");
    push_to_list(&right, "C");
    res = merge(left, right, fcts);
    cr_assert(list_eq(res, test_strcmp, 5, "A", "B", "C", "E", "F") == 0);
    free(fcts);
    destroy_list(res, NULL);
}
