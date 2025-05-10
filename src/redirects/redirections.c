/*
** EPITECH PROJECT, 2025
** Minishell2
** File description:
** Redirects
*/

#include "minishell.h"

const nfct_t redirections[] = {
    {";", &my_semicolon},
    {"||", &my_or},
    {"&&", &my_and},
    {"|", &my_pipe},
    {">>", &regular_output_append},
//    {"<<", &regular_input_append},
    {">", &regular_output},
    {"<", &regular_input},
    {0}
};

bool check_redirection(nfct_t *buffer, nfct_t redirection, char *line)
{
    char *c_ptr = line - 1;
    bool quotes = false;

    for (int x = 0; line[x]; x++) {
        quotes = line[x] == '"' ? !quotes : quotes;
        if (quotes)
            continue;
        if (line[x] != redirection.name[0] &&
            line[x] != ' ' && line[x] != '\t')
            c_ptr = line + x;
        if (my_strncmp(redirection.name, line + x,
            my_strlen(redirection.name) - 1) == 0) {
            *(c_ptr + 1) = 0;
            buffer->fct = redirection.fct;
            buffer->name = my_strdup(line + x + my_strlen(redirection.name));
            return buffer->name != NULL;
        }
    }
    return false;
}

nfct_t cut_on_redirections(char *line)
{
    nfct_t buff = {0};

    for (int i = 0; redirections[i].name; i++)
        if (check_redirection(&buff, redirections[i], line))
            return buff;
    return (nfct_t){0};
}

char *find_redirect_string(int (*fct)(ast_t *, ast_t *, llist_t **))
{
    for (int i = 0; redirections[i].name; i++)
        if (redirections[i].fct == fct)
            return redirections[i].name;
    return NULL;
}
