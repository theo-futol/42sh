/*
** EPITECH PROJECT, 2025
** Lib
** File description:
** List size, list to array.
*/

#include "llists.h"

int list_size(llist_t *begin)
{
    int i = 0;
    llist_t *list = begin;

    while (list != NULL) {
        list = list->next;
        i++;
    }
    return i;
}

void **list_to_array(llist_t **begin)
{
    llist_t *list = *begin;
    llist_t *tmp = NULL;
    int i = 0;
    int len = list_size(*begin);
    void **array = NULL;

    if (len <= 0)
        return NULL;
    array = my_calloc(len + 1, sizeof(void *));
    if (array == NULL)
        return NULL;
    while (list != NULL) {
        array[i] = list->data;
        tmp = list;
        list = list->next;
        free(tmp);
        i++;
    }
    *begin = NULL;
    return array;
}
