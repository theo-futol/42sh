/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(mfree_list, mfree_list_no_subfree_next)
{
    llist_t *subfrees = my_calloc(1, sizeof(llist_t));
    llist_t *wl = str_to_word_list("Get off me", "e ");
    void *popo = NULL;

    cr_assert(subfrees != NULL);
    cr_assert(wl != NULL);
    mfree_list(subfrees, &popo);
    mfree_list(subfrees, (void **)&wl);
}

Test(mfree_list, mfree_list_no_subfree)
{
    llist_t *wl = str_to_word_list("Get off me", "e ");
    void *popo = NULL;

    cr_assert(wl != NULL);
    mfree_list(NULL, &popo);
    mfree_list(NULL, (void **)&wl);
}

