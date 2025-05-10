/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

void *dupone(void *data)
{
    char *str = my_strndup((char *)data, 1);
    return (void *)str;
}

Test(create_list, creating_list_from_simple_elements)
{
    llist_t *list = create_list(NULL, 3, "Lol", "Damn", "Gotcha");

    cr_assert(list_eq(list, &test_strcmp, 3, "Lol", "Damn", "Gotcha") == 0);
}

Test(create_list, creating_list_from_extract_function)
{
    llist_t *list = create_list(&dupone, 3, "Lol", "Damn", "Gotcha");

    cr_assert(list_eq(list, &test_strcmp, 3, "L", "D", "G") == 0);
}
