/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(freef, freeing_everything_and_nothing_with_lambda)
{
    llist_t *list = NULL;
    char ***arr = calloc(4, sizeof(char **));
    arr[0] = str_to_word_array("Va cuire un oeuf", " ");
    arr[1] = str_to_word_array("o z e f", " ");
    arr[2] = str_to_word_array(" ok lm ", " ");
    char ***arr2 = calloc(4, sizeof(char **));
    char ***arr3 = calloc(4, sizeof(char **));
    char ****MVP = calloc(4, sizeof(char ***));
    arr2[0] = str_to_word_array("Va cuire un oeuf", " ");
    arr2[1] = str_to_word_array("o z e f", " ");
    arr2[2] = str_to_word_array(" ok lm ", " ");
    arr3[0] = str_to_word_array("Va cuire un oeuf", " ");
    arr3[1] = str_to_word_array("o z e f", " ");
    arr3[2] = str_to_word_array(" ok lm ", " ");
    MVP[0] = arr;
    MVP[1] = arr2;
    MVP[2] = arr3;

    push_to_list(&list, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, str_to_word_array("J'aime le cochon", " "));
    push_to_list((llist_t **)&list->data, str_to_word_array("Pas de jambon ici", " "));
    push_to_list(&list, NULL);
    push_to_list(&list, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, str_to_word_array("Adieu la chouquette", " "));
    push_to_list((llist_t **)&list->data, str_to_word_array("ORJEUBUfzhdygagff f", "f"));
    push_to_list(&list, NULL);
    push_to_list(&list, NULL);
    push_to_list(&list, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, str_to_word_array("Popolopopopoooo po", " "));
    push_to_list(&list, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, NULL);
    push_to_list((llist_t **)&list->data, NULL);

    char *str = malloc(sizeof(char)* 1000);
    freef_add("y", &mfree_array);
    freef("l:l:y f a:a:a:f", &list, &str, &MVP);
    freeflags_free();
}

Test(freef, stop_freeing_where_null)
{
    char **arr = str_to_word_array("I got a headhache", " ");
    char *str = NULL;
    char *u = malloc(1);

    freef("a f f", &arr, &str, &u);
    freef("a f f", &arr, &str, NULL);
    cr_assert(arr == NULL);
    cr_assert(str == NULL);
    cr_assert(u == NULL);
    freeflags_free();
}

Test(freef, null_format)
{
    freef(NULL, 1);
}
