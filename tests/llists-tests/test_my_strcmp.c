/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Tests
*/

#include "tests.h"

Test(my_strcmp, my_strcmp)
{
    char *s1 = "ABC";
    char *s2 = "ABJ";
    char *s3 = "AJ";
    char *s4 = "";
    char *s5 = "A";
    char *s6 = "B";

    cr_assert(my_strcmp(s1, s1) == strcmp(s1, s1));
    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
    cr_assert(my_strcmp(s2, s3) == strcmp(s2, s3));
    cr_assert(my_strcmp(s3, s2) == strcmp(s3, s2));
    cr_assert(my_strcmp(s4, s4) == strcmp(s4, s4));
    cr_assert(my_strcmp(s3, s5) == strcmp(s3, s5));
    cr_assert(my_strcmp(s5, s3) == strcmp(s5, s3));
    cr_assert(my_strcmp(s6, s5) == strcmp(s6, s5));
    cr_assert(my_strcmp(s1, s5) == strcmp(s1, s5));
    cr_assert(my_strcmp(s4, s1) == strcmp(s4, s1));
}

Test(my_strcmp, strcmp_missing_value)
{
    char *s1 = "ABC";
    char *s2 = NULL;

    cr_assert(my_strcmp(s1, s2) == s1[0]);
    cr_assert(my_strcmp(s2, s1) == 0 - s1[0]);
    cr_assert(my_strcmp(s2, s2) == 0);
}
