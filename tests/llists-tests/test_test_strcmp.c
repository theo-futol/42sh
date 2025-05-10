/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** test
*/

#include "tests.h"

Test(test_strcmp, void_strcmp)
{
    char *s1 = "ABC";
    char *s2 = "ABJ";

    cr_assert(test_strcmp(s1, s2) == strcmp(s1, s2));
}
