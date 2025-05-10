/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(multicomp, no_comp_, .init = redirect_all_std)
{
    void *one = NULL;
    void *two = NULL;

    cr_assert(multicomp(one, two, 0) == 0);
}

Test(multicomp, simple_comp_, .init = redirect_all_std)
{
    char *one = "ABJ";
    void *two = "ABC";

    cr_assert(multicomp(one, two, 1, strcmp) == 7);
}

Test(multicomp, multiple_comp_, .init = redirect_all_std)
{
    char *one = "ABC";
    char *two = "ABC";

    cr_assert(multicomp(one, two, 1, test_strcmp) == 0);
    cr_assert(multicomp(one, two, 2, test_strcmp, NULL) == 0);
    cr_assert(multicomp(one, "ABJ", 0, test_strcmp) == 0);
}
