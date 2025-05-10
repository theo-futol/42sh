/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(fieldscomp, no_comp, .init = redirect_all_std)
{
    void *one = NULL;
    void *two = NULL;

    cr_assert(fieldscomp(one, two, NULL) == 0);
}

Test(fieldscomp, simple_comp, .init = redirect_all_std)
{
    char *one = "ABJ";
    void *two = "ABC";
    cmp_fct_t *cmp_list = my_calloc(2, sizeof(cmp_fct_t));

    cmp_list[0] = &test_strcmp;
    cr_assert(fieldscomp(one, two, cmp_list) == 7);
    free(cmp_list);
}

Test(fieldscomp, multiple_comp, .init = redirect_all_std)
{
    char *one = "ABC";
    void *two = "ABC";
    cmp_fct_t *cmp_list = my_calloc(2, sizeof(cmp_fct_t));

    cmp_list[0] = &test_strcmp;
    cr_assert(fieldscomp(one, two, cmp_list) == 0);
    free(cmp_list);
}
