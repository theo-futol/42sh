/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(vput_str, simple_vput_str, .init = redirect_all_std)
{
    vput_str(1, 1, "Amen");
    vput_str(1, 2, " to", " the neighbors");
    cr_assert_stdout_eq_str("Amen to the neighbors");
}

Test(vput_str, null_not_ending_print, .init = redirect_all_std)
{
    vput_str(1, 3, "Bonsoir", NULL, " marchal");
    vput_str(1, 3, NULL, "chef", " marchal");
    cr_assert_stdout_eq_str("Bonsoir marchalchef marchal");
}

Test(vput_str, many_put_str, .init = redirect_all_std)
{
    vput_str(1, 5, "A", "m", "en", "\n", NULL);
    cr_assert_stdout_eq_str("Amen\n");
}
