/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(my_strcpy, my_strcpy)
{
    char buffer[100] = "";
    char buffer2[100] = "";

    cr_assert_str_eq(my_strcpy(buffer, "works"), my_strcpy(buffer2, "works"));
    cr_assert_str_eq(my_strcpy(buffer, "bobo"), my_strcpy(buffer2, "bobo"));
    cr_assert_str_eq(my_strcpy(buffer, NULL), my_strcpy(buffer2, NULL));
}
