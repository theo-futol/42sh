/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** ncurses
*/

#ifndef INCLUDED_NCURSES_H
    #define INCLUDED_NCURSES_H
    #include <ncurses.h>
    #define SCROLL_MAX 100

typedef struct screen_s {
    WINDOW *screen;
    int height;
    int width;
    int is_open;
    int index_row;
    int default_index;
    char *buf_scroll[SCROLL_MAX];
} screen_t;

typedef struct input_s {
    int key;
    int (*fct)();
    bool disp_buf;
} input_t;

//      LINE EDITING        //
extern const input_t inputs[];

int handle_input_left(char **line, int *count, int *cursor_pos);
int handle_input_right(char **line, int *count, int *cursor_pos);
int handle_input_del(char **line, int *count, int *cursor_pos);
int handle_input_up(char **line, int *count, int *cursor_pos);
int handle_input_down(char **line, int *count, int *cursor_pos);
int handle_input_mouse(char **line, int *count);
int handle_tab(char **line, int *count, int *cursor_pos);
int get_input(int key, char **line, int *count, int *cursor_pos);
int get_prompt(char **line, llist_t *env);
void disp_buf_scroll(screen_t *win);
int add_buf_scroll(screen_t *win, int new_line, int nb, ...);
void free_buff_scroll(void);
int remove_buf_scroll(screen_t *win, int len);
int print_prompt(llist_t *env);
int display_output(int pipefd[2], int saved_stdout, int saved_stderr);
int redirection_tty(int pipefd[2], int *saved_stdout, int *saved_stderr);
void close_ncurse(void);
#endif
