/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(dft_putnode, no_string, .init = redirect_all_std)
{
    llist_t *l = my_calloc(1, sizeof(llist_t));

    dft_putnode(l);
    cr_assert_stdout_eq_str("");
}
