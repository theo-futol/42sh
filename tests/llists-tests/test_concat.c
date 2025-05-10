/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(concat, concatening_gap_array)
{
    char **arr = calloc(4, sizeof(char *));
    arr[0] = my_strdup("Lol");
    arr[2] = my_strdup("lol");

    cr_assert_str_eq(concat(6, arr), "Lol");
}

Test(concat, concatening_word_array)
{
    char **arr = calloc(3, sizeof(char *));
    arr[0] = my_strdup("Lol");
    arr[1] = my_strdup("lol");

    cr_assert_str_eq(concat(9, arr), "Lollol");
}

Test(concat, concatening_null_array)
{
    char **arr = NULL;

    cr_assert(concat(6, arr) == NULL);
}

Test(concat, concatening_empty_array)
{
    char **arr = calloc(5, sizeof(char *));

    cr_assert_str_eq(concat(10, arr), "");
}
