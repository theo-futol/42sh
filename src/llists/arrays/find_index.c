/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Finds index of a ref value within an array,
** using a given comparison function.
*/

#include "llists.h"

int find_index(cmp_fct_t cmp_fct, void *ref, void **array)
{
    if (!array)
        return -1;
    for (int i = 0; array[i]; i++)
        if (cmp_fct(ref, array[i]) == 0)
            return i;
    return -1;
}
