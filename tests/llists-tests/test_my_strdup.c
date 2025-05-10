/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(my_strdup, my_strdup)
{
    cr_assert_str_eq(my_strdup("String"), "String");
}

Test(my_strdup, failed_my_strdup)
{
    cr_assert(my_strdup(NULL) == NULL);
    calloc_failure_countdown(true, 0);
    cr_assert(my_strdup("String") == NULL);
    calloc_failure_countdown(true, -1);
}
