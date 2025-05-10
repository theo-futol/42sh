/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Printing the shell prompt.
*/

#include "minishell.h"

int current_time(void)
{
    time_t t = time(NULL);
    struct tm *local = localtime(&t);

    return local->tm_hour * 60 + local->tm_min;
}

char *my_getcwd(char name[], size_t n, llist_t *env)
{
    llist_t *node = find_node(env, "HOME", &is_key_var);
    char *home = node ? (char *)node->data + 5 : NULL;
    int homelen = my_strlen(home);
    int len = 0;

    getcwd(name, n);
    len = my_strlen(name);
    if (homelen > 0 && my_strncmp(home, name, homelen - 1) == 0) {
        name[0] = '~';
        for (int i = 0; i < len; i++)
            name[i + 1] = name[i + homelen];
        name[len - 1] = 0;
    }
    if (name[0] == '/')
        return name + 1;
    return name;
}

int print_prompt(llist_t *env)
{
    size_t n = 2047;
    char name[2048] = "";
    char *user = search_env_var(env, "USERNAME");
    int time = current_time();
    int last_res = last_result(false, 0);
    char *buf = NULL;

    if (!user)
        return 84;
    if (asprintf(&buf, "(%.2d:%.2d) %s@%s[%d] $> ", time / 60, time
        % 60, user, my_getcwd(name, n, env), last_res) < 1)
        return 84;
    if (shell()->win.is_open) {
        add_buf_scroll(&shell()->win, 1, 1, buf);
        shell()->win.index_row--;
        disp_buf_scroll(&shell()->win);
    } else
        printf("%s", buf);
    return freef("f f", &buf, &user), 0;
}
