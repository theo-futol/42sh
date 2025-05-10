/*
** EPITECH PROJECT, 2025
** Liblist
** File description:
** Dups every item of a string array into a list.
*/

#include "llists.h"

llist_t *word_array_to_list(char **wa)
{
    llist_t *list = NULL;
    char *tmp = NULL;
    int i = 0;

    if (!wa)
        return NULL;
    while (wa[i]) {
        tmp = my_strdup(wa[i]);
        if (!tmp)
            return NULL;
        push_to_list(&list, tmp);
        i++;
    }
    return list;
}
