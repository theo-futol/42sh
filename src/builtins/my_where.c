/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** my_which.c
*/

#include "minishell.h"

void disp_which_where(char *filepath)
{
    if (isatty(0))
        add_buf_scroll(&shell()->win, 1, 1, filepath);
    puts(filepath);
}

static void disp_builtin_where(char *filepath)
{
    char *disp = NULL;

    if (asprintf(&disp, "%s is a shell built-in", filepath) < 1)
        return;
    if (isatty(0))
        add_buf_scroll(&shell()->win, 1, 1, disp);
    puts(disp);
    freef("f", &disp);
}

static void get_av_in_path(char **full_path, char *av)
{
    char *testpath = av[0] == '/' ? "" : ".";
    char *filepath = NULL;
    int i = arr_len((void const **)full_path);

    do {
        filepath = vstr_concat(3, testpath, "/", av);
        i--;
        if (!filepath)
            continue;
        if (filepath && access(filepath, X_OK) == 0 && filepath[0] != '.')
            disp_which_where(filepath);
        free(filepath);
        testpath = full_path ? full_path[i] : NULL;
    } while (testpath && i > -1);
}

static void disp_error_sense(void)
{
    if (isatty(0))
        add_buf_scroll(&shell()->win, 1, 1,
        "where: / in command makes no sense");
    puts("where: / in command makes no sense");
    last_result(true, 1);
}

int my_where(int ac, char **av, llist_t **env_vars)
{
    char *path_var = av == NULL ? NULL : search_env_var(*env_vars, "PATH");
    char **full_path = path_var ? full_path_vars(path_var) : NULL;

    if (ac < 2)
        return my_putstr(2, "where: Too few arguments.\n"), ERR_BUILTIN;
    if (!full_path)
        return ERR_BUILTIN;
    for (int i = 1; av[i]; i++){
        if (av[i][0] == '/'){
            disp_error_sense();
            continue;
        }
        if (is_builtin(av[i]))
            disp_builtin_where(av[i]);
        else
            get_av_in_path(full_path, av[i]);
    }
    freef("a", &full_path);
    return last_result(false, 0);
}
