/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(mfree_array, mfree_array_no_subfree_next)
{
    llist_t *subfrees = my_calloc(1, sizeof(llist_t));
    char **wa = str_to_word_array("Get off me", "e ");
    void *popo = NULL;

    cr_assert(subfrees != NULL);
    cr_assert(wa != NULL);
    mfree_array(subfrees, &popo);
    mfree_array(subfrees, (void **)&wa);
}

Test(mfree_array, mfree_array_no_subfree)
{
    char **wa = str_to_word_array("Get off me", "e ");
    void *popo = NULL;

    cr_assert(wa != NULL);
    mfree_array(NULL, &popo);
    mfree_array(NULL, (void **)&wa);
}

