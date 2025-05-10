/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Cd
*/

#include "minishell.h"

bool setenv_dir(char *new_cwd, llist_t **evars)
{
    size_t n = 2048;
    char *old_cwd = NULL;
    char *command_1[3] = {"setenv", "OLDPWD", getcwd(old_cwd, n)};
    char *command_2[3] = {"setenv", "PWD", new_cwd};

    if (chdir(new_cwd) == 0 && my_setenv(3, command_1, evars) == 0 &&
        my_setenv(3, command_2, evars) == 0) {
        free(command_1[2]);
        return true;
    }
    if (command_1[2])
        free(command_1[2]);
    return false;
}

static void error_cd(char *path, llist_t *env_vars)
{
    llist_t *node = find_node(shell()->local_env, "OLDPWD", &is_key_var);

    node = node ? node : find_node(env_vars, "OLDPWD", &is_key_var);
    if (my_strcmp(path, "-") == 0 && !node)
        return;
    dprintf(2, "%s: %s.\n", path, strerror(errno));
}

int my_cd(int ac, char **av, llist_t **env_vars)
{
    char *fullpath = NULL;
    bool ch_res = false;
    llist_t *node = NULL;

    if (ac == 1) {
        node = find_node(shell()->local_env, "HOME", &is_key_var);
        node = node ? node : find_node(*env_vars, "HOME", &is_key_var);
        if (!node)
            return 1;
        return setenv_dir((char *)node->data + 5, env_vars) ? 0 : 1;
    }
    if (ac == 2)
        fullpath = get_fullpath(av[1], *env_vars);
    ch_res = fullpath ? setenv_dir(fullpath, env_vars) : false;
    if (fullpath)
        free(fullpath);
    if (!ch_res)
        error_cd(av[1], *env_vars);
    return ch_res ? 0 : ERR_BUILTIN;
}
