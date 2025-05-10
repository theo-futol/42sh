/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Pattern matching ?, *, [...]
*/

#include "minishell.h"
/*
bool matches(char *origin, char *entry)
{
    while (*origin && *entry) {
        if (*origin == '?' || *origin == *entry) {
            origin++;
            entry++;
        }
        if (*origin == '*') {
            return matches(origin + 1, entry) || matches(origin, entry + 1);
        }
        break;
    }
    return *origin == *entry;
}*/

llist_t *generate_pattern_match(char *origin)
{
    llist_t *matched = NULL;
    glob_t globbuf = {0};
    int res = origin ? glob(origin,
        GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf) : -1;

    if (res != 0)
        return NULL;
    for (int i = 0; globbuf.gl_pathv[i]; i++)
        push_to_list(&matched, my_strdup(globbuf.gl_pathv[i]));
    globfree(&globbuf);
    return matched;
}
