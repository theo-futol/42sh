/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Calloc function
*/

#include "llists.h"

int *calloc_failure_countdown(bool change, int new_countdown)
{
    static int countdown = -1;

    if (change)
        countdown = new_countdown;
    return &countdown;
}

__attribute__((malloc)) void *my_calloc(size_t amount, size_t size)
{
    int *countdown = calloc_failure_countdown(false, 0);
    void *ptr = NULL;

    if (*countdown != 0)
        ptr = malloc(size * amount);
    else
        my_putstr(2, "Failed to calloc.\n");
    if (*countdown > 0)
        (*countdown) -= 1;
    if (ptr == NULL)
        return NULL;
    my_memset(ptr, 0, (size) * amount);
    return ptr;
}
