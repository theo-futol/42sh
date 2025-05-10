/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(mergesort_list, single_sort, .init = redirect_all_std)
{
    cmp_fct_t *cmp_list = my_calloc(2, sizeof(cmp_fct_t));
    llist_t *list = NULL;

    cmp_list[0] = &test_strcmp;
    push_to_list(&list, "D");
    push_to_list(&list, "A");
    push_to_list(&list, "C");
    push_to_list(&list, "B");
    list = mergesort_list(list, cmp_list);
    cr_assert(list_eq(list, test_strcmp, 4, "A", "B", "C", "D") == 0);
    free(cmp_list);
    destroy_list(list, NULL);
}

Test(mergesort_list, not_sorting, .init = redirect_all_std)
{
    cmp_fct_t *cmp_list = my_calloc(2, sizeof(cmp_fct_t));
    llist_t *list = NULL;

    cmp_list[0] = &test_strcmp;
    list = mergesort_list(list, cmp_list);
    cr_assert(list == NULL);
    push_to_list(&list, "D");
    list = mergesort_list(list, cmp_list);
    free(cmp_list);
    destroy_list(list, NULL);
}
