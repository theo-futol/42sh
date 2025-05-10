/*
** EPITECH PROJECT, 2025
** Lib llist
** File description:
** unit test
*/

#include "tests.h"

Test(str_to_word_array, sinmple_words)
{
    char *str = "Aloah mister googa";
    char **array = str_to_word_array(str, " ");

    cr_assert_str_eq(array[0], "Aloah");
    cr_assert_str_eq(array[1], "mister");
    cr_assert_str_eq(array[2], "googa");
    cr_assert(array[3] == NULL);
}

Test(str_to_word_array, many_spaces)
{
    char *str = " Aloah   mister   googa  ";
    char **array = NULL;

    calloc_failure_countdown(true, 0);
    array = str_to_word_array(str, " ");
    cr_assert(array == NULL);
    calloc_failure_countdown(true, -1);
    array = str_to_word_array(str, " ");
    cr_assert_str_eq(array[0], "Aloah");
    cr_assert_str_eq(array[1], "mister");
    cr_assert_str_eq(array[2], "googa");
    cr_assert(array[3] == NULL);
}

Test(str_to_word_array, no_words)
{
    char *str = "  ";
    char *str2 = NULL;
    char **array = str_to_word_array(str2, " ");

    cr_assert(array == NULL);
    array = str_to_word_array(str, " ");
    cr_assert(array == NULL);
    cr_assert(arr_len((void const **)array) == 0);
}

Test(str_to_word_array, separators_within_quotes)
{
    char **array = str_to_word_array("Coconuts \"everywhere\" !", "e");

    cr_assert(arr_len((const void **)array) == 1);
}
