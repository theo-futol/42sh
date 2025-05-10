/*
** EPITECH PROJECT, 2025
** lib llists
** File description:
** Test
*/

#include "tests.h"

Test(display_list, simple_disp, .init = redirect_all_std)
{
    llist_t *list = NULL;

    append_to_list(&list, "data");
    cr_assert_str_eq((char *)list->data, "data");
    append_to_list(&list, "value n*2");
    cr_assert_str_eq((char *)list->next->data, "value n*2");
    display_list(list, dft_putnode);
    destroy_list(list, NULL);
    cr_assert_stdout_eq_str("datavalue n*2");
}
