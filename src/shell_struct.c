/*
** EPITECH PROJECT, 2025
** Shell
** File description:
** Shell static
*/

#include "minishell.h"

shell_t *shell(void)
{
    static shell_t *shell = NULL;

    if (!shell)
        shell = my_calloc(1, sizeof(shell_t));
    return shell;
}
