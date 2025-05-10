/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(rev_list, rev_list)
{
    llist_t *left = NULL;
    int res = 1;

    push_to_list(&left, "L3");
    push_to_list(&left, "L2");
    push_to_list(&left, "L1");
    res = list_eq(left, test_strcmp, 3, "L1", "L2", "L3");
    cr_assert(res == 0);
    rev_list(&left);
    res = list_eq(left, test_strcmp, 3, "L3", "L2", "L1");
    cr_assert(res == 0);
}

Test(rev_list, rev_null_list_ptr)
{
    llist_t **rights = NULL;

    rev_list(rights);
}
