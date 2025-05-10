/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(skip, skipping_blanks)
{
    cr_assert_str_eq(skip("\t   bobo"), "bobo");
}

Test(skip, not_skipping)
{
    cr_assert_str_eq(skip("tata"), "tata");
}

Test(skip, skipping_null_string)
{
    cr_assert(skip(NULL) == NULL);
}
