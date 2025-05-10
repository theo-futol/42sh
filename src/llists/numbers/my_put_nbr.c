/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** machin
*/

#include "llists.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    int y = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb / y >= 10) {
        y = y * 10;
    }
    while (y != 1) {
        my_putchar(48 + (nb / y) % 10);
        y = y / 10;
    }
    my_putchar(48 + nb % 10);
}
