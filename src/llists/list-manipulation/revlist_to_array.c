/*
** EPITECH PROJECT, 2025
** Lib
** File description:
** Reversed list to array.
*/

#include "llists.h"

void **revlist_to_array(llist_t **begin)
{
    llist_t *list = *begin;
    llist_t *tmp = NULL;
    int len = list_size(*begin);
    void **array = NULL;

    if (len == 0)
        return NULL;
    array = my_calloc(len + 1, sizeof(void *));
    if (array == NULL)
        return NULL;
    while (list != NULL) {
        array[len - 1] = list->data;
        tmp = list;
        list = list->next;
        free(tmp);
        len--;
    }
    *begin = NULL;
    return array;
}
