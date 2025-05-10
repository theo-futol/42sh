/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Putstr
*/

#include "llists.h"

void vput_str(int fd, int nb, ...)
{
    char *tmp = NULL;
    va_list ap;

    va_start(ap, nb);
    while (nb > 0) {
        tmp = va_arg(ap, char *);
        my_putstr(fd, tmp);
        nb--;
    }
    va_end(ap);
}
