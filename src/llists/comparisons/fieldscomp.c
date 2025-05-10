/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Takes function pointers as arguments
*/

#include "llists.h"

static int rec_comp(void *elem1, void *elem2, cmp_fct_t *cmp_fcts)
{
    cmp_fct_t cmp_fct = cmp_fcts == NULL ? NULL : cmp_fcts[0];
    int cmp_result = 0;

    if (cmp_fct != NULL) {
        cmp_result = cmp_fct(elem1, elem2);
        if (cmp_result == 0) {
            return rec_comp(elem1, elem2, cmp_fcts + 1);
        }
    }
    return cmp_result;
}

int fieldscomp(void *elem1, void *elem2, cmp_fct_t *cmp_fct_list)
{
    return rec_comp(elem1, elem2, cmp_fct_list);
}

// cmp_fct_list is an array of function pointers, each of them comparing data.
