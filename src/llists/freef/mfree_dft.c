/*
** EPITECH PROJECT, 2025
** LibFree
** File description:
** Freeing
*/

#include "llists.h"

void mfree_dft(llist_t *subfree, void **target_ptr)
{
    (void)subfree;
    if (!(*target_ptr))
        return;
    free(*target_ptr);
    *target_ptr = NULL;
}
