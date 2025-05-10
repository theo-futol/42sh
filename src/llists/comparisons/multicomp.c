/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Takes function pointers as arguments
*/

#include "llists.h"

static int rec_comp(void *elem1, void *elem2, int nbcomp, va_list ap)
{
    int (*cmp_fct)(void *, void *) = NULL;
    int cmp_result = 0;

    if (nbcomp > 0) {
        cmp_fct = va_arg(ap, int (*)(void *, void *));
        if (!cmp_fct)
            return 0;
        cmp_result = cmp_fct(elem1, elem2);
        if (cmp_result == 0) {
            return rec_comp(elem1, elem2, nbcomp - 1, ap);
        }
    }
    return cmp_result;
}

int multicomp(void *elem1, void *elem2, int nbcomp, ...)
{
    va_list ap;
    int res = 1;

    va_start(ap, nbcomp);
    res = rec_comp(elem1, elem2, nbcomp, ap);
    va_end(ap);
    return res;
}
