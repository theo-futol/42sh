/*
** EPITECH PROJECT, 2025
** LibFree
** File description:
** Freeing
*/

#include "llists.h"

void mfree_array(llist_t *subfrees, void **target_ptr)
{
    mfree_t sfree = subfrees && subfrees->next ?
        ((mfree_t)(subfrees->data)) : &mfree_dft;
    llist_t *sub = subfrees ? subfrees->next : NULL;
    void **arr = (void **)(*target_ptr);

    if (!arr)
        return;
    while (*arr) {
        sfree(sub, arr);
        arr++;
    }
    free(*target_ptr);
    *target_ptr = NULL;
}
