/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(list_eq, equalities)
{
    llist_t *list = NULL;
    llist_t *left = NULL;
    llist_t *right = NULL;
    int res = 1;

    push_to_list(&left, "L3");
    push_to_list(&left, "L2");
    push_to_list(&left, "L1");
    push_to_list(&right, "R2");
    push_to_list(&right, "R1");
    submerge(&list, left, right);
    res = list_eq(list, test_strcmp, 5, "L1", "L2", "L3", "R1", "R2");
    cr_assert(res == 0);
    res = list_eq(list, test_strcmp, 5, "L1", "S2", "L3", "R1", "R2");
    cr_assert(res != 0);
    res = list_eq(NULL, test_strcmp, 5, "L1", "L2", "L3", "R1", "R2");
    cr_assert(res != 0);
    res = list_eq(list, NULL, 5, "L1", "L2", "L3", "R1", "R2");
    cr_assert(res != 0);
}
