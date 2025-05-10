/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(my_put_nbr, put_nbr_0_to_10, .init = redirect_all_std)
{
    for (int i = 0; i < 11; i++) {
        my_put_nbr(i);
        write(1, " ", 1);
    }
    cr_assert_stdout_eq_str("0 1 2 3 4 5 6 7 8 9 10 ");
}

Test(my_put_nbr, put_nbr_0_to_minus_10, .init = redirect_all_std)
{
    for (int i = 0; i > -11; i--) {
        my_put_nbr(i);
        write(1, " ", 1);
    }
    cr_assert_stdout_eq_str("0 -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 ");
}

Test(my_put_nbr, put_nbr_e10, .init = redirect_all_std)
{
    for (int i = 1000000000; i > 10; i /= 10) {
        my_put_nbr(i);
    }
    cr_assert_stdout_eq_str("1000000000100000000100000001000000100000100001000100");
}
