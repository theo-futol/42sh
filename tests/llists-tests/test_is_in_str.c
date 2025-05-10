/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(is_in_str, is_not_in_str)
{
    cr_assert(!is_in_str('`', "abcdefghijklmnopqrstuvwxyz"));
    cr_assert(!is_in_str('[', "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}

Test(is_in_str, not_in_no_string)
{
    cr_assert(!is_in_str('9', NULL));
    cr_assert(!is_in_str('0', NULL));
}

Test(is_in_str, is_in_string)
{
    cr_assert(is_in_str('E', "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    cr_assert(is_in_str('O', "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    cr_assert(is_in_str('H', "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    cr_assert(is_in_str('1', "0123456789"));
    cr_assert(is_in_str('0', "8527419630"));
}
