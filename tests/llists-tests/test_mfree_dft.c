/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(mfree_dft, avoid_freeing_null)
{
    char *space = my_strdup("Allô allô monsieur l'ordinateeeur");

    cr_assert_str_eq(space, "Allô allô monsieur l'ordinateeeur");
    mfree_dft(NULL, (void **)&space);
    mfree_dft(NULL, (void **)&space);
}
