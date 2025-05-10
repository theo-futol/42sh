/*
** EPITECH PROJECT, 2025
** FreeF
** File description:
** FREEEEE
*/

#include "llists.h"

const nfct_t freef_defaults[] = {
    {"f", &mfree_dft},
    {"a", &mfree_array},
    {"l", &mfree_list},
    {0}
};

llist_t __attribute__((constructor)) **freeflags_get(void)
{
    static llist_t *freeflags = NULL;
    nfct_t *flag = NULL;

    if (freeflags)
        return &freeflags;
    for (int i = 0; freef_defaults[i].name; i++) {
        flag = my_calloc(1, sizeof(nfct_t));
        if (!flag)
            return &freeflags;
        flag->name = my_strdup(freef_defaults[i].name);
        if (!flag->name)
            return &freeflags;
        flag->fct = freef_defaults[i].fct;
        push_to_list(&freeflags, flag);
    }
    return &freeflags;
}

void free_nfct(void *flag)
{
    if (!flag)
        return;
    free(((nfct_t *)flag)->name);
    free(flag);
}

void __attribute__((destructor)) freeflags_free(void)
{
    llist_t **freeflags = freeflags_get();

    destroy_list(*freeflags, &free_nfct);
    *freeflags = NULL;
}
