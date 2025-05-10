/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-theo.futol
** File description:
** handle_up_and_down_input
*/
#include "minishell.h"

int stock_value(int index, int new_value, bool modif)
{
    static int history_size = 0;
    static int current_index = -1;
    static int history_loaded = 0;

    if (index == 0) {
        if (modif)
            history_size = new_value;
        return history_size;
    }
    if (index == 1) {
        if (modif)
            current_index = new_value;
        return current_index;
    }
    if (index == 2) {
        if (modif)
            history_loaded = new_value;
        return history_loaded;
    }
    return 0;
}

void free_history(void)
{
    if (shell()->history != NULL) {
        for (int i = 0; i < stock_value(0, 0, false); i++)
            free(shell()->history[i]);
        free(shell()->history);
        shell()->history = NULL;
        stock_value(0, 0, true);
        stock_value(1, -1, true);
        stock_value(2, 0, true);
    }
}

static int count_hist_size(char **line, size_t *len, FILE *file)
{
    ssize_t read = getline(line, len, file);

    stock_value(0, 0, true);
    while (read != -1) {
        stock_value(0, stock_value(0, 0, false) + 1, true);
        read = getline(line, len, file);
    }
    if (stock_value(0, 0, false) == 0) {
        shell()->history = malloc(sizeof(char *));
        if (shell()->history == NULL) {
            fclose(file);
            return free(*line), -1;
        }
        shell()->history[0] = NULL;
        stock_value(1, stock_value(0, 0, false), true);
        stock_value(2, 1, true);
        fclose(file);
        free(*line);
    }
    return 0;
}

static int stock_loop(char **line, size_t *len, FILE *file)
{
    ssize_t read = getline(line, len, file);
    int i = 0;

    for (*len = 0; read != -1; read = getline(line, len, file)) {
        if (read > 0 && (*line)[read - 1] == '\n')
            (*line)[read - 1] = '\0';
        shell()->history[i] = strdup(*line);
        if (shell()->history[i] == NULL) {
            freef("a", &shell()->history);
            shell()->history = NULL;
            fclose(file);
            freef("f", line);
            return -1;
        }
        i++;
    }
    shell()->history[i] = NULL;
    return 0;
}

static int stock_hist(char **line, size_t *len, FILE *file)
{
    *line = NULL;
    *len = 0;
    if (stock_loop(line, len, file) == -1)
        return -1;
    fclose(file);
    freef("f", line);
    stock_value(1, stock_value(0, 0, false), true);
    stock_value(2, 1, true);
    return 0;
}

int load_history(void)
{
    FILE *file = NULL;
    char *line = NULL;
    size_t len = 0;

    if (stock_value(2, 0, false))
        free_history();
    file = fopen(HISTORY, "r");
    if (file == NULL)
        return -1;
    if (count_hist_size(&line, &len, file) == -1)
        return -1;
    if (stock_value(0, 0, false) == 0)
        return 0;
    rewind(file);
    shell()->history = malloc(sizeof(char *) * (stock_value(0, 0, false) + 1));
    if (shell()->history == NULL) {
        fclose(file);
        return freef("f", line), -1;
    }
    return stock_hist(&line, &len, file);
}

static int replace_line(char **line, int *count, int *cursor_pos,
    const char *history_line)
{
    int len = 0;

    if (!history_line)
        return -1;
    len = strlen(history_line);
    memset(*line, 0, *count);
    strcpy(*line, history_line);
    *count = len;
    *cursor_pos = len;
    return 0;
}

int handle_input_down(char **line, int *count, int *cursor_pos)
{
    if (!stock_value(2, 0, false) && load_history() != 0)
        return -1;
    if (stock_value(0, 0, false) == 0)
        return 0;
    if (stock_value(1, 0, false) <= 0)
        return 0;
    stock_value(1, stock_value(1, 0, false) - 1, true);
    return replace_line(line, count, cursor_pos,
        shell()->history[stock_value(1, 0, false)]);
}

int handle_input_up(char **line, int *count, int *cursor_pos)
{
    if (!stock_value(2, 0, false) && load_history() != 0)
        return -1;
    if (stock_value(0, 0, false) == 0 ||
        stock_value(1, 0, false) >= stock_value(0, 0, false) - 1)
            return 0;
    stock_value(1, stock_value(1, 0, false) + 1, true);
    return replace_line(line, count, cursor_pos,
        shell()->history[stock_value(1, 0, false)]);
}
