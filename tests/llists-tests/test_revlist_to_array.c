/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(revlist_to_array, revlist_simple_nodes)
{
    llist_t *list = create_list(NULL, 3, 0, 0, 7);
    void **array = revlist_to_array(&list);

    cr_assert(array[0] == (void *)7);
    cr_assert(array[1] == (void *)0);
    cr_assert(array[2] == (void *)0);
    cr_assert(array[3] == NULL);
}

Test(revlist_to_array, revlist_no_nodes)
{
    llist_t *list = NULL;
    char **array = (char **)revlist_to_array(&list);

    cr_assert(array == NULL);
}

Test(revlist_to_array, failed_revlist_to_array)
{
    llist_t *list = NULL;
    char **array = NULL;

    append_to_list(&list, "data");
    cr_assert_str_eq((char *)list->data, "data");
    calloc_failure_countdown(true, 0);
    array = (char **)revlist_to_array(&list);
    cr_assert(array == NULL);
    calloc_failure_countdown(true, -1);
}
