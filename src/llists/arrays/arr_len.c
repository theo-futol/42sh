/*
** EPITECH PROJECT, 2025
** Minishell1
** File description:
** arrlen
*/

int arr_len(void const **arr)
{
    int i = 0;

    if (!arr)
        return 0;
    for (i = 0; arr[i]; i++);
    return i;
}
