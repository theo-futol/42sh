/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Str to word array including globbings
*/

#include "minishell.h"

/* If 'generate_expansions' returns NULL,
 * the 'origin' string stays.
 * tmp is never NULL when used */
__attribute__((nonnull)) void expand_args(llist_t **args,
    llist_t *(*generate_expansions)(char *origin), bool rematch)
{
    llist_t *expansions = NULL;
    llist_t *tmp = NULL;

    args = &(*args)->next;
    while (*args) {
        if (!(*args))
            break;
        expansions = generate_expansions((char *)(*args)->data);
        if (!expansions) {
            args = &(*args)->next;
            continue;
        }
        tmp = list_head(args);
        freef("f f", &tmp->data, &tmp);
        concat_list(args, expansions);
        if (!rematch)
            args = &(*args)->next;
    }
}

/* Cutting on argvs, expanding braces, expanding with pattern matching */
char **str_to_formatted_argv(char *line, char *separators)
{
    char *formatted = format_command(line);
    llist_t *args = str_to_word_list(formatted, separators);

    freef("f", &formatted);
    if (!args)
        return NULL;
    expand_args(&args, &generate_sequences, true);
    expand_args(&args, &generate_pattern_match, false);
    return (char **)list_to_array(&args);
}
