/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(is_alphanumeric, lower_and_upper_alphabet)
{
    cr_assert(is_alphanumeric("abcdefghijklmnopqrstuvwxyz"));
    cr_assert(is_alphanumeric("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}

Test(is_alphanumeric, not_alphabet)
{
    cr_assert(is_alphanumeric("abqrstuvwxyz"));
    cr_assert(is_alphanumeric("ABCDEFGXYZ"));
}

Test(is_alphanumeric, numeric)
{
    cr_assert(is_alphanumeric("0123456789"));
    cr_assert(is_alphanumeric("8527419630"));
}

Test(is_alphanumeric, mixed_upper_and_lower)
{
    cr_assert(is_alphanumeric("SabqZ"));
    cr_assert(is_alphanumeric("azfCYfrZ"));
}

Test(is_alphanumeric, mixed_letters_and_digits)
{
    cr_assert(is_alphanumeric("0Sab6qZ"));
    cr_assert(is_alphanumeric("azf3CYf5rZ"));
}

Test(is_alphanumeric, not_alphanumeric)
{
    cr_assert(!is_alphanumeric("izfezdsf@"));
    cr_assert(!is_alphanumeric("ZUfhds-"));
    cr_assert(!is_alphanumeric("abqrst:uvwxyz"));
    cr_assert(!is_alphanumeric("ABC!DEFGXYZ"));
    cr_assert(!is_alphanumeric("!=%+"));
    cr_assert(!is_alphanumeric("[quoicoubeh]"));
    cr_assert(!is_alphanumeric("{patate}"));
    cr_assert(!is_alphanumeric("true|false"));
}
