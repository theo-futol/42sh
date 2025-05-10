/*
** EPITECH PROJECT, 2025
** Liblists
** File description:
** Puts string
*/

#include "llists.h"

void my_putstr(int fd, char *str)
{
    if (!str)
        return;
    write(fd, str, my_strlen(str));
}
