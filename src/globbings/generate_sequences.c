/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Braces expansion {...}
*/

#include "minishell.h"

static bool same_case(char c, char d)
{
    if (!is_alpha_char(c) || !is_alpha_char(d))
        return false;
    if (c >= 'A' && c <= 'Z' && d >= 'A' && d <= 'Z')
        return true;
    if (c >= 'a' && c <= 'z' && d >= 'a' && d <= 'z')
        return true;
    return false;
}

static llist_t *range_chars(llist_t *chars,
    char *start_str, char *end_str, char *step_str)
{
    char *tmp = NULL;
    char start = 0;
    char end = 0;
    int step = step_str ? atoi(step_str) : 1;

    if (!same_case(*start_str, *end_str) ||
        my_strlen(start_str) != 1 || my_strlen(end_str) != 1 ||
        (step_str && !is_number(step_str)))
        return NULL;
    start = *start_str;
    end = *end_str;
    step = (start < end) == (step > 0) ? step : -step;
    do {
        asprintf(&tmp, "%c", start);
        if (tmp)
            push_to_list(&chars, tmp);
        start += step;
    } while ((step > 0 && start <= end) || (step < 0 && start >= end));
    return chars;
}

static llist_t *range_nums(llist_t *nums,
    char *start_str, char *end_str, char *step_str)
{
    char *tmp = NULL;
    int start = 0;
    int end = 0;
    int step = step_str ? atoi(step_str) : 1;

    if (!is_number(start_str) || !is_number(end_str) ||
        (step_str && !is_number(step_str)))
        return NULL;
    start = atoi(start_str);
    end = atoi(end_str);
    step = (start < end) == (step > 0) ? step : -step;
    do {
        asprintf(&tmp, "%d", start);
        if (tmp)
            push_to_list(&nums, tmp);
        start += step;
    } while ((step > 0 && start <= end) || (step < 0 && start >= end));
    return nums;
}

static char **braces_range_format(char *format)
{
    llist_t *res = NULL;
    char *start = format;
    char *end = strstr(format, "..");
    char *step = end ? strstr(end + 1, "..") : NULL;

    if (!end)
        return NULL;
    *end = 0;
    end += 2;
    if (step) {
        *step = 0;
        step += 2;
    }
    res = range_nums(res, start, end, step);
    res = res ? res : range_chars(res, start, end, step);
    return (char **)list_to_array(&res);
}

static void assemble_format(llist_t **sequences,
    char *origin, char *entrypoint, char *exitpoint)
{
    char **formats = str_to_word_array(entrypoint, ",");
    char **instances = NULL;
    char *full = NULL;

    if (!formats)
        return;
    for (int i = 0; formats[i]; i++) {
        instances = braces_range_format(formats[i]);
        if (!instances) {
            full = vstr_concat(3, origin, formats[i], exitpoint);
            push_to_list(sequences, full);
            continue;
        }
        for (int j = 0; instances[j]; j++) {
            full = vstr_concat(3, origin, instances[j], exitpoint);
            append_to_list(sequences, full);
        }
        freef("a", &instances);
    }
    return freef("a", &formats);
}

// Format before handling : origin{entrypoint}exitpoint
llist_t *generate_sequences(char *origin)
{
    llist_t *sequences = NULL;
    char *entrypoint = origin ? strchr(origin, '{') : NULL;
    char *exitpoint = entrypoint ? strchr(entrypoint, '}') : NULL;

    if (!exitpoint)
        return NULL;
    if (exitpoint - entrypoint < 2)
        return NULL;
    origin[exitpoint - origin] = 0;
    origin[entrypoint - origin] = 0;
    exitpoint++;
    entrypoint++;
    assemble_format(&sequences, origin, entrypoint, exitpoint);
    return sequences;
}
