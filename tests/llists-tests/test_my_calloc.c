/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** test
*/

#include "tests.h"

Test(my_calloc, simple_calloc)
{
    char *ptr = my_calloc(1, sizeof(char));
    int *ptr2 = my_calloc(1, sizeof(char));

    if (!ptr || !ptr2)
        return;
    for (size_t i = 0; i < sizeof(char) * 1; i++)
        cr_assert_eq(ptr[i], 0);
    for (size_t i = 0; i < sizeof(int) * 1; i++)
        cr_assert_eq(ptr[i], 0);
    free(ptr);
    free(ptr2);
}

Test(my_calloc, no_calloc)
{
    char *ptr = my_calloc(20000000000, sizeof(size_t));

    cr_assert_eq(ptr, NULL);
}
