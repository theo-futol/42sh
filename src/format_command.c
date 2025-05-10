/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Formatting line
*/

#include "minishell.h"

char *replace_alias(char *line)
{
    char *new = my_strdup(line);
    char *formatted = NULL;
    llist_t *node = find_node(shell()->aliases, line, is_alias_var);
    size_t len = 0;

    if (!node)
        return new;
    len = strlen_to(line, ' ');
    formatted = vstr_concat(2, node->data + len + 1, new + len);
    if (formatted) {
        freef("f", &new);
        return formatted;
    }
    return new;
}

char *dup_varname(char *line)
{
    int i = 0;

    if (my_strncmp(line, "?", 0) == 0)
        return strndup(line, 1);
    while (is_alphanumeric_char(line[i]))
        i++;
    if (i > 0)
        return my_strndup(line, i);
    return NULL;
}

static void err(char *name, char *msg)
{
    dprintf(2, "%s: %s.\n", name, msg);
}

/* Env variables and inhibitors one within the ast, not before */
char *replace_env_variables(char *line, char *tmp, bool inhibitor)
{
    char *name = NULL;
    char *content = NULL;

    for (size_t i = 0; line && line[i]; i++) {
        inhibitor = line[i] == '\'' ? !inhibitor : inhibitor;
        if (!inhibitor && line[i] == '$')
            name = dup_varname(line + i + 1);
        if (!name)
            continue;
        content = search_env_var(shell()->env, name);
        if (!content)
            return err(name, "Undefined variable"), free(name), NULL;
        line[i] = 0;
        tmp = line;
        line = vstr_concat(3, line, content, line + i + 1 + strlen(name));
        i += strlen(content) - 1;
        content = NULL;
        freef("f f", &name, &tmp);
    }
    return line;
}

/* Should replace aliases, and environment variables,
     still managing inhibitors */
char *format_command(char *line)
{
    char *formatted = replace_alias(line);
    bool quotes = false;
    bool inhibitor = false;
    int parentheses = 0;

    for (int x = 0; line[x]; x++) {
        quotes = line[x] == '"' ? !quotes : quotes;
        inhibitor = line[x] == '\'' ? !inhibitor : inhibitor;
        parentheses += line[x] == '(' && parentheses >= 0 ? 1 : 0;
        parentheses -= line[x] == ')' ? 1 : 0;
    }
    if (quotes)
        dprintf(2, "Unmatched \'\"\'.\n");
    if (inhibitor)
        dprintf(2, "Unmatched \'\'\'.\n");
    if (parentheses)
        dprintf(2, "Too many %c's.\n", parentheses > 0 ? '(' : ')');
    if (quotes || inhibitor || parentheses)
        freef("f", &formatted);
    return formatted ? replace_env_variables(formatted, NULL, false) : NULL;
}
