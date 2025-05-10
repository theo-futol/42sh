/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** test
*/

#include "tests.h"

Test(my_memset, simple_memset)
{
    char *ptr = malloc(10);

    if (ptr == NULL)
        return;
    my_memset(ptr, 0, 10);
    for (int i = 0; i < 10; i++)
        cr_assert_eq(ptr[i], 0);
    free(ptr);
}

Test(my_memset, no_memset)
{
    char *ptr = NULL;

    cr_assert_eq(my_memset(ptr, 1, 10), NULL);
}

Test(my_memset, multiple_memset)
{
    char *ptr = malloc(sizeof(int) * 5);

    if (ptr == NULL)
        return;
    my_memset(ptr, 15, sizeof(int) * 5);
    for (size_t i = 0; i < sizeof(int) * 5; i++)
        cr_assert_eq(ptr[i], 15);
    free(ptr);
}
