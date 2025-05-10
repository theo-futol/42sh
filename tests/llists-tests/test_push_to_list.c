/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(push_to_list, simple_pushes, .init = redirect_all_std)
{
    llist_t *list = NULL;

    push_to_list(&list, "data");
    cr_assert_str_eq((char *)list->data, "data");
    push_to_list(&list, "value n*2");
    cr_assert_str_eq((char *)list->data, "value n*2");
    cr_assert_str_eq((char *)list->next->data, "data");
    destroy_list(list, NULL);
}

Test(push_to_list, null_list_pointer)
{
    llist_t **list = NULL;

    push_to_list(list, "data");
    cr_assert(list == NULL);
}

Test(push_to_list, failed_alloc_push_to_list)
{
    llist_t *list = NULL;

    calloc_failure_countdown(true, 0);
    push_to_list(&list, "data");
    cr_assert(list == NULL);
    calloc_failure_countdown(true, -1);
}
