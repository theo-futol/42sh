/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** test
*/

#include "tests.h"

Test(find_list_half, single_node_half)
{
    llist_t *list = NULL;
    char *data = "Lmao";
    char *data2 = "Beginning";

    cr_assert(find_list_half(list) == NULL);
    append_to_list(&list, data);
    cr_assert(find_list_half(list)->data == data);
    push_to_list(&list, data2);
    cr_assert(find_list_half(list) == list);
    cr_assert(find_list_half(list)->data == data2);
    destroy_list(list, NULL);
}

Test(find_list_half, many_nodes_half)
{
    llist_t *list = NULL;
    char *data1 = "1";
    char *data2 = "2";
    char *data3 = "3";
    char *data4 = "4";
    char *data5 = "5";
    char *data6 = "6";

    push_to_list(&list, data1);
    cr_assert(find_list_half(list)->data == data1);
    push_to_list(&list, data2);
    cr_assert(find_list_half(list)->data == data2);
    push_to_list(&list, data3);
    cr_assert(find_list_half(list)->data == data2);
    push_to_list(&list, data4);
    cr_assert(find_list_half(list)->data == data3);
    push_to_list(&list, data5);
    cr_assert(find_list_half(list)->data == data3);
    push_to_list(&list, data6);
    cr_assert(find_list_half(list)->data == data4);
    destroy_list(list, NULL);
}
