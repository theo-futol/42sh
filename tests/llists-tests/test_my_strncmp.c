/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Tests
*/

#include "tests.h"

Test(my_strncmp, my_strncmp)
{
    char *s1 = "ABC";
    char *s2 = "ABJ";
    char *s3 = "AJ";
    char *s4 = "";
    char *s5 = "A";
    char *s6 = "B";

    cr_assert(my_strncmp(s1, s1, 2) == strncmp(s1, s1, 2));
    cr_assert(my_strncmp(s1, s2, 1) == strncmp(s1, s2, 1));
    cr_assert(my_strncmp(s2, s3, 0) == strncmp(s2, s3, 0));
    cr_assert(my_strncmp(s3, s2, 3) == strncmp(s3, s2, 3));
    cr_assert(my_strncmp(s4, s4, 9) == strncmp(s4, s4, 9));
    cr_assert(my_strncmp(s3, s5, 2) == strncmp(s3, s5, 2));
    cr_assert(my_strncmp(s6, s5, 3) == strncmp(s6, s5, 3));
}

Test(my_strncmp, strncmp_missing_value)
{
    char *s1 = "ABC";
    char *s2 = NULL;

    cr_assert(my_strncmp(s1, s2, 10) == s1[0]);
    cr_assert(my_strncmp(s2, s1, 10) == 0 - s1[0]);
    cr_assert(my_strncmp(s2, s2, 2) == 0);
}
