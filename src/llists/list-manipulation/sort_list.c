/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Sorting a linked list with merge sort.
*/

#include "llists.h"

llist_t *find_list_half(llist_t *begin)
{
    llist_t *half = NULL;
    llist_t *end = NULL;

    if (!begin)
        return NULL;
    half = begin;
    end = begin->next;
    while (end != NULL && end->next != NULL) {
        half = half->next;
        end = end->next->next;
    }
    return half;
}

void submerge(llist_t **res, llist_t *l1, llist_t *l2)
{
    llist_t *tmp = NULL;

    if (!res)
        return;
    while (l1 != NULL) {
        append_to_list(res, l1->data);
        tmp = l1;
        l1 = l1->next;
        free(tmp);
    }
    while (l2 != NULL) {
        append_to_list(res, l2->data);
        tmp = l2;
        l2 = l2->next;
        free(tmp);
    }
}

llist_t *merge(llist_t *l1, llist_t *l2, cmp_fct_t *cmp_fcts)
{
    llist_t *tmp = NULL;
    llist_t *result = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (fieldscomp(l1->data, l2->data, cmp_fcts) < 0) {
            append_to_list(&result, l1->data);
            tmp = l1;
            l1 = l1->next;
            free(tmp);
        } else {
            append_to_list(&result, l2->data);
            tmp = l2;
            l2 = l2->next;
            free(tmp);
        }
    }
    submerge(&result, l1, l2);
    return result;
}

/* If there's any problem, add "if (!half) {return NULL;} right under half" */
llist_t *mergesort_list(llist_t *begin, cmp_fct_t *cmp_fcts)
{
    llist_t *half = NULL;
    llist_t *first_half = NULL;
    llist_t *second_half = NULL;

    if (begin == NULL || begin->next == NULL)
        return begin;
    half = find_list_half(begin);
    first_half = begin;
    second_half = half->next;
    half->next = NULL;
    first_half = mergesort_list(first_half, cmp_fcts);
    second_half = mergesort_list(second_half, cmp_fcts);
    return merge(first_half, second_half, cmp_fcts);
}
