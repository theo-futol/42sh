/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** l
*/

#include "include/minishell.h"

void minishell(llist_t *env_vars)
{
    char *line = NULL;
    int pipefd[2] = {0};
    int saved_stderr = 0;

    for (int saved_stdout = 0; shell()->active; freef("f", &line)){
        if (pipe(pipefd) == -1 || get_prompt(&line, env_vars) == -1 ||
            saved_stderr == -1 || saved_stdout == -1)
                last_result(true, 1);
        if (redirection_tty(pipefd, &saved_stdout, &saved_stderr) == 84){
            freef("f", &line);
            last_result(true, 1);
        }
        handle_commandline(line, &env_vars);
        if (display_output(pipefd, saved_stdout, saved_stderr) == 84){
            freef("f", &line);
            last_result(true, 1);
        }
    }
    close_ncurse();
}

ssize_t my_getline(char **line, size_t *n)
{
    ssize_t len = getline(line, n, stdin);

    if (len < 1)
        return len;
    (*line)[len - 1] = (*line)[len - 1] == '\n' ? 0 : (*line)[len - 1];
    return len;
}

void minishell_tty(llist_t *env_vars)
{
    size_t n = 0;
    char *line = NULL;
    ssize_t getres = 1;

    while (shell()->active && getres > 0){
        if (isatty(0))
            print_prompt(shell()->env);
        getres = my_getline(&line, &n);
        if (getres == 1)
            continue;
        if (getres < 1)
            break;
        handle_commandline(line, &env_vars);
        freef("f", &line);
    }
}

int main(int ac, char **av UNUSED, char **env)
{
    shell_t *sh = shell();

    if (!sh)
        return 84;
    shell()->active = true;
    shell()->env = dupenv(env);
    if (isatty(0) && ac < 2) {
        if (init_screen() == -1)
            return free(sh), freef("l:f", &shell()->env), 84;
        minishell(shell()->env);
    } else
        minishell_tty(shell()->env);
    freef("l:f l:f l:f f", &sh->env, &sh->local_env,
        &sh->aliases, history_path());
    free(sh);
    if (isatty(0))
        fflush(stdout);
    exit(last_result(false, 0));
}
