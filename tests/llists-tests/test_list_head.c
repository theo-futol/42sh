/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** test
*/

#include "tests.h"

Test(list_head, head)
{
    llist_t **error = NULL;
    llist_t *list = NULL;
    llist_t *tmp = NULL;

    cr_assert(list_head(error) == NULL);
    cr_assert(list_head(&list) == NULL);
    push_to_list(&list, "2");
    push_to_list(&list, "1");
    tmp = list_head(&list);
    cr_assert_str_eq((char *)tmp->data, "1");
    cr_assert_str_eq((char *)list->data, "2");
    destroy_list(tmp, NULL);
    destroy_list(list, NULL);
}
