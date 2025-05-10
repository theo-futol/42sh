/*
** EPITECH PROJECT, 2024
** Libs
** File description:
** Llists
*/

#ifndef LLISTS_H_
    #define LLISTS_H_
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdbool.h>
    #define UNUSED __attribute__((unused))

typedef struct llist_s {
    void *data;
    struct llist_s *next;
} llist_t;

typedef struct named_fct_s {
    char *name;
    void (*fct);
} nfct_t;

/* Custom and subdivising functions to free */
typedef void (*mfree_t)(llist_t *, void **);

void mfree_dft(llist_t *subfree, void **target_ptr);
void mfree_array(llist_t *subfrees, void **target_ptr);
void mfree_list(llist_t *subfrees, void **target_ptr);

/* Freeing with formatted string */
void superfree(char *format, void **target_ptr);
__attribute__((hot)) void freef(char *format, ...);
/* Adding new flags to freef() */
void freef_add(char *name, void (*free_fct)());

/* Basic comparison functions */
typedef int (*cmp_fct_t)(const void *, const void *);

int my_strcmp(const char *s1, const char *s2);
int my_strcmp_insensitive(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, size_t n);
int test_strcmp(const void *s1, const void *s2);

/* Advanced comparison functions */
int parts_strcmp(char *string, char *first_part, ...);
int list_eq(llist_t *list, cmp_fct_t cmp, int nb, ...);

/* Recursive comparison functions based on multiple basic criterias */
int fieldscomp(void *elem1, void *elem2, cmp_fct_t *cmp_fct_list);
int multicomp(void *elem1, void *elem2, int nbcomp, ...);

/* Copy */
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, size_t n);

/* Duplicating functions */
char *my_strndup(const char *str, int n);
char *my_strdup(const char *str);
char *concat(size_t flen, char **wa);
char *vstr_concat(int n, ...);

/* Memory allocating functions */
void *my_memset(void *ptr, int value, size_t nbytes);
void *my_calloc(size_t amount, size_t size);

/* List manipulation */
int list_size(llist_t *begin);
bool push_to_list(llist_t **begin, void *data);
void append_to_list(llist_t **begin, void *data);
llist_t *list_head(llist_t **begin);
void concat_list(llist_t **dest, llist_t *src);
llist_t *mergesort_list(llist_t *begin, cmp_fct_t *cmp_fcts);
bool delete_in_list(llist_t **begin, void *ref, cmp_fct_t cmp_fct);
void destroy_list(llist_t *list, void (*destroy_node)(void *));
void my_map(llist_t *list, void (*apply_fct)(void **));
llist_t *find_node(llist_t *node, void *ref, cmp_fct_t cmp_fct);
llist_t *rev_list(llist_t **list_ptr);

/* List sorting subfunctions, those can be used for other purposes too */
llist_t *find_list_half(llist_t *begin);
void submerge(llist_t **res, llist_t *l1, llist_t *l2);
llist_t *merge(llist_t *l1, llist_t *l2, cmp_fct_t *cmp_fcts);

/* List showcase */
void dft_putnode(void *s);
void newline_putnode(void *s);
void display_list(llist_t *begin, void(*disp_fct)(void *));

/* List transformations */
llist_t *str_to_word_list(char *av, char *seps);
void **list_to_array(llist_t **begin);
void **revlist_to_array(llist_t **begin);
char **str_to_word_array(char *str, char *seps);
llist_t *word_array_to_list(char **wa);
llist_t *create_list(void *(*extract)(void *), int nb, ...);

/* Utils */
int get_nbr(char *str);
char *skip(char *str);
bool is_numeric_char(char c);
bool is_alpha_char(char c);
bool is_alphanumeric_char(char c);
bool is_numeric(char *str);
bool is_alphanumeric(char *str);
bool is_in_str(char c, const char *str);
size_t my_strlen(char const *str);
int arr_len(void const **arr);
void my_putstr(int fd, char *str);
void my_put_nbr(int nb);
void vput_str(int fd, int n, ...);

/* Do not use, only here for testing purposes. */
void freeflags_free(void);
llist_t **freeflags_get(void);
void free_nfct(void *flag);
int *calloc_failure_countdown(bool change, int new_countdown);
#endif
