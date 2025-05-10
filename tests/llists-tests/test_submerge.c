/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** test
*/

#include "tests.h"

Test(submerge, submerging)
 {
    llist_t *list = NULL;
    llist_t *left = NULL;
    llist_t *right = NULL;
    llist_t *end = NULL;

    push_to_list(&left, "Left 3");
    push_to_list(&left, "Left 2");
    push_to_list(&left, "Left 1");
    push_to_list(&right, "Right 2");
    push_to_list(&right, "Right 1");
    submerge(&list, left, right);
    push_to_list(&end, list_head(&list)->data);
    cr_assert_str_eq(end->data, "Left 1");
    push_to_list(&end, list_head(&list)->data);
    cr_assert_str_eq(end->data, "Left 2");
    push_to_list(&end, list_head(&list)->data);
    cr_assert_str_eq(end->data, "Left 3");
    push_to_list(&end, list_head(&list)->data);
    cr_assert_str_eq(end->data, "Right 1");
    push_to_list(&end, list_head(&list)->data);
    cr_assert_str_eq(end->data, "Right 2");
    destroy_list(end, NULL);
}

Test(submerge, submerge_error)
{
    llist_t **error = NULL;

    submerge(error, NULL, NULL);
    cr_assert(error == NULL);
}
