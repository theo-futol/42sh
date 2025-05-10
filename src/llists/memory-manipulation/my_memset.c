/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Memset
*/

#include "llists.h"

void *my_memset(void *ptr, int value, size_t nbytes)
{
    if (ptr == NULL)
        return NULL;
    for (size_t i = 0; i < nbytes; i++)
        *((char *)ptr + i) = value;
    return ptr;
}
