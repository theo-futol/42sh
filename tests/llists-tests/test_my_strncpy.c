/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(my_strncpy, my_strncpy)
{
    char buffer[100] = "";
    char buffer2[100] = "";

    cr_assert_str_eq(my_strncpy(buffer, "works", 3), my_strncpy(buffer2, "works", 3));
    cr_assert_str_eq(my_strncpy(buffer, "folk", 15), my_strncpy(buffer2, "folk", 15));
    cr_assert_str_eq(my_strncpy(buffer, "bobo", 1), my_strncpy(buffer2, "bobo", 1));
    cr_assert_str_eq(my_strncpy(buffer, NULL, 2), my_strncpy(buffer2, NULL, 2));
}
