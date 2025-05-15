/*
** EPITECH PROJECT, 2025
** Minishell1
** File description:
** Forks and execute, while printing some informations.
*/

#include "minishell.h"

char **full_path_vars(char *path_var)
{
    llist_t *paths = str_to_word_list(path_var, ":");

    my_map(paths, &path_to_fullpath);
    return (char **)revlist_to_array(&paths);
}

char *find_correct_path(char *command, char *path_var)
{
    struct stat statbuf = {0};
    char **paths = full_path_vars(path_var);
    char *testpath = command[0] == '/' ? "" : ".";
    char *filepath = NULL;
    int i = -1;

    do {
        filepath = vstr_concat(3, testpath, "/", command);
        i++;
        if (!filepath)
            continue;
        if (stat(filepath, &statbuf) == 0) {
            freef("a", &paths);
            return filepath;
        }
        free(filepath);
        testpath = paths ? paths[i] : NULL;
    } while (testpath);
    freef("a", &paths);
    return testpath;
}

static void error_execve(char *command)
{
    dprintf(2, "%s: %s", command, strerror(errno));
    if (errno == ENOEXEC)
        dprintf(2, ". Binary file not executable");
    dprintf(2, ".\n");
    exit(84);
}

void my_paths_exec(char **command, llist_t *env_vars, char *filepath)
{
    char **env = filepath ? (char **)list_to_array(&env_vars) : NULL;

    if (filepath && access(filepath, X_OK) == 0){
        if (execve(filepath, command, env) < 0)
            error_execve(command[0]);
    } else {
        vput_str(2, 2, command[0], ": Command not found.\n");
        freef("a", &env);
        exit(ERR_NOT_FOUND);
    }
}

static void disp_signal(int wstatus)
{
    if (!shell()->win.is_open)
        vput_str(2, 2, strsignal(WTERMSIG(wstatus)), "\n");
    add_buf_scroll(&shell()->win, 1, 1, strsignal(WTERMSIG(wstatus)));
}

int parent_wait(pid_t cpid)
{
    int wstatus = 0;
    pid_t wpid = -1;

    do {
        wpid = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
        if (wpid == -1)
            exit(84);
        if (WIFEXITED(wstatus))
            continue;
        if (WIFSIGNALED(wstatus))
            disp_signal(wstatus);
    } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
    return WEXITSTATUS(wstatus);
}

static char *verify_path(char **command, llist_t *env_vars)
{
    char *path_var = search_env_var(env_vars, "PATH");
    char *filepath = NULL;

    if (!path_var)
        return dprintf(2, "%s: Command not found.\n", command[0]), NULL;
    filepath = find_correct_path(command[0], path_var);
    free(path_var);
    if (filepath && access(filepath, X_OK) == 0)
        return filepath;
    dprintf(2, "%s: Command not found.\n", command[0]);
    return NULL;
}

int fork_and_print(char **command, llist_t *env_vars)
{
    pid_t cpid = 0;
    char *filepath = verify_path(command, env_vars);

    if (!filepath)
        return 1;
    cpid = fork();
    if (cpid < 0)
        return free(filepath), 84;
    if (cpid == 0)
        my_paths_exec(command, env_vars, filepath);
    else
        return free(filepath), parent_wait(cpid);
    free(filepath);
    return 0;
}
