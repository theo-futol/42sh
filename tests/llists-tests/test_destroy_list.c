/*
** EPITECH PROJECT, 2025
** Lib lists
** File description:
** Test
*/

#include "tests.h"

Test(destroy_list, simple_destroy)
{
     llist_t *list = NULL;

    append_to_list(&list, "data");
    cr_assert_str_eq((char *)list->data, "data");
    append_to_list(&list, "value n*2");
    cr_assert_str_eq((char *)list->next->data, "value n*2");
    destroy_list(list, NULL);
}

Test(destroy_list, no_destroy)
{
    llist_t *list = NULL;

    destroy_list(list, NULL);
    cr_assert(list == NULL);
}

Test(destroy_list, destroy_node)
{
    llist_t *list = NULL;

    append_to_list(&list, strdup("data"));
    cr_assert_str_eq((char *)list->data, "data");
    append_to_list(&list, strdup("value n*2"));
    cr_assert_str_eq((char *)list->next->data, "value n*2");
    destroy_list(list, free);
}
