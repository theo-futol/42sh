/*
** EPITECH PROJECT, 2025
** Minishell1
** File description:
** Header
*/

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_
    #define _GNU_SOURCE
    #include "llists.h"
    #include "screen.h"
    #include <sys/wait.h>
    #include <sys/resource.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <limits.h>
    #include <form.h>
    #include <sys/ioctl.h>
    #include <locale.h>
    #include <pthread.h>

    #include <dirent.h>
    #include <glob.h>
    #define SEPARATORS " \t\r\n"
    #define PCOLOR "\e[1;36m"
    #define DCOLOR "\e[1;33m"
    #define TCOLOR "\e[1;35m"
    #define UCOLOR "\e[1;32m"
    #define ECOLOR "\e[1;31m"
    #define WHITE "\e[0;39m"
    #define HISTORY ".minihistory"
    #define ERR_NOT_FOUND 1
    #define ERR_BUILTIN 1
    #define LOCALTIME 4

typedef struct builtin_function_s {
    char *command_name;
    int (*command)(int ac, char **av, llist_t **env_vars);
} builtin_t;

typedef struct ast_s ast_t;

struct ast_s {
    int (*fct)(ast_t *, ast_t *, llist_t **);
    char *command;
    struct ast_s *sub1;
    struct ast_s *sub2;
    bool is_leaf;
};

typedef struct shell_s {
    llist_t *env;
    llist_t *local_env; // Is the same as env but not given to child process
    llist_t *aliases;
    char **history; // In-memory-loaded history, to acces them with '!'.
    char *history_path; // Should be a local environment variable, within RC
    int res;
    bool active;
    screen_t win;
} shell_t;

size_t strlen_to(const char *str, char c);
bool is_number(char *str);
void my_put_nbr(int nb);
int is_key_var(void const *string, void const *keyname);
int is_alias_var(void const *string, void const *aliasname);
char **full_path_vars(char *path_var);
void disp_which_where(char *filepath);
void path_to_fullpath(void **path_address);
bool is_blank(char *str);
char *skip(char *str);
char *single_word(char *str);

/*                      Statics                     */
char **history_path(void);
int last_result(bool mode, int new_value);
shell_t *shell(void);


/*                     Using env                    */
llist_t *dupenv(char **env);
char *search_env_var(llist_t *env_vars, char *var);


/*                     Builtins                     */
int is_builtin(char *str);
int my_cd(int ac, char **av, llist_t **env_vars);
int my_env(int ac, char **av, llist_t **env_vars);
int my_unsetenv(int ac, char **av, llist_t **env_vars);
int my_setenv(int ac, char **av, llist_t **env_vars);
int my_local(int ac, char **av, llist_t **env_vars UNUSED);
int my_set(int ac, char **av, llist_t **env_vars);
int my_unset(int ac, char **av, llist_t **env_vars);
int my_exit(int ac, char **av, llist_t **env_vars);
int my_history(int ac, char **av, llist_t **env_vars);
int my_alias(int ac, char **av, llist_t **env_vars UNUSED);
int my_unalias(int ac UNUSED, char **av, llist_t **env_vars UNUSED);
int my_repeat(int ac, char **av, llist_t **env_vars UNUSED);
int my_clear(int ac, char **av, llist_t **env_vars);
int my_where(int ac, char **av, llist_t **env_vars);
int my_which(int ac, char **av, llist_t **env_vars);

/*                  Handling command                */
int fork_and_print(char **command, llist_t *env_vars);
char *get_fullpath(char *path, llist_t *env_vars);
void remove_quotes(char *str);
char *format_command(char *line);
char **str_to_formatted_argv(char *line, char *separators);
int handle_command(char *command, llist_t **env_vars);
int handle_commandline(char *commands, llist_t **env_vars);
ssize_t my_getline(char **line, size_t *n);
void history_save(ast_t *ast);

/*                       AST                        */
int exec_ast(ast_t *ast, llist_t **env_vars);
ast_t *create_ast(char *whole);
void write_ast(int fd, ast_t *ast);
void free_ast(ast_t **ast);
nfct_t cut_on_redirections(char *line);

/*                  Redirections                    */
int my_semicolon(ast_t *ast1, ast_t *ast2, llist_t **env);
int my_or(ast_t *ast1, ast_t *ast2, llist_t **env);
int my_and(ast_t *ast1, ast_t *ast2, llist_t **env);
int my_pipe(ast_t *ast1, ast_t *ast2, llist_t **env);
int regular_input(ast_t *ast1, ast_t *ast2, llist_t **env);
int regular_output(ast_t *ast1, ast_t *ast2, llist_t **env);
int regular_output_append(ast_t *ast1, ast_t *ast2, llist_t **env);
char *find_redirect_string(int (*fct)(ast_t *, ast_t *, llist_t **));
void child_pipe(ast_t *ast, llist_t **env, int pipefd[2]);

/*                  Ncurses                    */
int init_screen(void);

/*                  Globbings                       */
llist_t *generate_sequences(char *origin);
llist_t *generate_pattern_match(char *origin);
#endif
