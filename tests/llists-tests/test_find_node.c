/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(find_node, research_in_list)
{
    llist_t *list = NULL;
    char *str = "This is the key";
    char *str2 = "This is another one";

    append_to_list(&list, str);
    cr_assert(find_node(list, "This is another one", &test_strcmp) == NULL);
    append_to_list(&list, str2);
    cr_assert(find_node(list, "This is the key", &test_strcmp) != NULL);
    cr_assert(find_node(list, "This isn't", &test_strcmp) == NULL);
    cr_assert(find_node(list, "This is a key", &test_strcmp) == NULL);
    cr_assert(find_node(list, "This is another one", &test_strcmp) != NULL);
    destroy_list(list, NULL);
}
