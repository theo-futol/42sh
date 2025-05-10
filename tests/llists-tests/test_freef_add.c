/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(freef_add, freeing_with_custom_flags)
{
    char *str = calloc(100, sizeof(char));
    char ***arr = calloc(4, sizeof(char **));
    arr[0] = str_to_word_array("Va cuire un oeuf", " ");
    arr[1] = str_to_word_array("o z e f", " ");
    arr[2] = str_to_word_array(" ok lm ", " ");

    for (int i = 0; i < 3; i++) {
        calloc_failure_countdown(true, i);
        freef_add("2025", NULL);
        freeflags_free();
    }
    calloc_failure_countdown(true, -1);
    freef_add("2025", NULL);
    calloc_failure_countdown(true, 1);
    freef_add("calimero", &mfree_array);
    freef_add("calimero", &mfree_array);
    calloc_failure_countdown(true, -1);
    freef_add(NULL, NULL);
    freef_add("2025", NULL);
    freef_add(NULL, &mfree_array);
    freef_add("calimero", &mfree_array);
    freef("2025 calimero:a:k47", &str, &arr);
    freeflags_free();
}
