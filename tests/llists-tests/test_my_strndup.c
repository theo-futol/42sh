/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(my_strndup, failed_my_strdup)
{
    calloc_failure_countdown(true, 0);
    cr_assert(my_strndup("fail", 2) == NULL);
    calloc_failure_countdown(true, -1);
}
