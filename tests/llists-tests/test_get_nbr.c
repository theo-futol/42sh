/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(get_nbr, converting_string_to_integer)
{
    cr_assert(get_nbr("21") == 21);
    cr_assert(get_nbr("42") == 42);
    cr_assert(get_nbr("84") == 84);
}

Test(get_nbr, get_nbr_null_string)
{
    cr_assert(get_nbr(NULL) == -1);
}
