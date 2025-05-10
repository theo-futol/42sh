/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

void mapping(void **data)
{
    *data = my_strndup(*(char **)data, 1);
}

Test(my_map, mapping_function_over_list_elements)
{
    llist_t *list = create_list(NULL, 3, "Lol", "Damn", "Gotcha");

    my_map(list, &mapping);
    cr_assert(list_eq(list, &test_strcmp, 3, "L", "D", "G") == 0);
}

Test(my_map, not_mapping_null_function)
{
    llist_t *list = create_list(NULL, 3, "Lol", "Damn", "Gotcha");

    my_map(list, NULL);
    cr_assert(list_eq(list, &test_strcmp, 3, "Lol", "Damn", "Gotcha") == 0);
}
