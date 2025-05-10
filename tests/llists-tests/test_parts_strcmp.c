/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Tests
*/

#include "tests.h"

Test(parts_strcmp, simple_string_cmp)
{
    char str[27] = "This is the whole string.";

    cr_assert(parts_strcmp(str, "This", NULL) == 0);
    cr_assert(parts_strcmp(str, "This is the whole", NULL) == 0);
    cr_assert(parts_strcmp(str, "This is the whole string.", NULL) == 0);
    cr_assert(parts_strcmp(str, "This is the whole thing", NULL) == -1);
    cr_assert(parts_strcmp(str, NULL) == 0);
    cr_assert(parts_strcmp(NULL, NULL) == -1);
    cr_assert(parts_strcmp(NULL, str) == -1);
}
