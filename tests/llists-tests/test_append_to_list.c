/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** test
*/

#include "tests.h"

Test(append_to_list, simple_add)
{
    llist_t *list = NULL;

    calloc_failure_countdown(true, 0);
    append_to_list(&list, "data");
    calloc_failure_countdown(true, -1);
    append_to_list(&list, "data");
    cr_assert_str_eq((char *)list->data, "data");
    append_to_list(&list, "value n*2");
    cr_assert_str_eq((char *)list->next->data, "value n*2");
    destroy_list(list, NULL);
}
