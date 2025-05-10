/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(delete_in_list, simple_del, .init = redirect_all_std)
{
    llist_t *list = NULL;
    char *v1 = my_strdup("1");
    char *v2 = my_strdup("2");
    char *n = "lol";

    append_to_list(&list, v1);
    cr_assert_eq((char *)list->data, v1);
    append_to_list(&list, v2);
    cr_assert_str_eq((char *)list->next->data, v2);
    cr_assert(delete_in_list(&list, n, test_strcmp) == false);
    cr_assert(delete_in_list(&list, v2, test_strcmp));
    cr_assert_eq(list->data, v1);
    cr_assert(list->next == NULL);
    cr_assert(delete_in_list(&list, v1, test_strcmp));
    cr_assert(list == NULL);
}

Test(delete_in_list, no_del_match)
{
    llist_t *list = NULL;
    llist_t **error = NULL;

    cr_assert(delete_in_list(&list, NULL, test_strcmp) == false);
    cr_assert(delete_in_list(error, NULL, test_strcmp) == false);
    push_to_list(&list, my_strdup("3"));
    cr_assert(delete_in_list(&list, "12", test_strcmp) == false);
    cr_assert(delete_in_list(&list, "3", test_strcmp));
}

Test(delete_in_list, del_match_further)
{
    llist_t *list = NULL;
    char *v1 = "1";

    append_to_list(&list, "1");
    cr_assert_eq((char *)list->data, v1);
    append_to_list(&list, "2");
    append_to_list(&list, "3");
    append_to_list(&list, strdup("4"));
    append_to_list(&list, "5");
    cr_assert(delete_in_list(&list, "4", test_strcmp));
    destroy_list(list, NULL);
}
