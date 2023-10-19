#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buffer: address of pointer to cmd_buffer, on if chaining
 * @cmd_buffer_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* shell_loop.c */
int h_sh(info_t *, char **av);
int f_builtin(info_t *info);
void cmd_get(info_t *info);
void cmd_fork(info_t *info);

/* parser.c */
int is_command(info_t *info, char *path);
char *duplicates_chars(char *pathstr, int starts, int stop);
char *find_path_string(info_t *info, char *pathstr, char *cmd);

/* loophsh.c */
int loophsh(char **hsh);

/* err.c */
void str_in(char *str);
int str_test(char c);
int fd_str(char c, int fd);
int _putsfd(char *str, int fd);

/* strings.c */
int _strlen(char *str);
int string_comparison(char *str1, char *str2);
char *starts_with_needle(const char *haystack, const char *needle);
char *_strcat(char *destination, char *source);

/* string1.c */
char *string_copy(char *destination, char *source);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

/* exodus.c */
char *char_cp(char *dest, char *src, int n);
char *char_add(char *dest, char *src, int n);
char *char_str(char *s, char c);

/* tokeniz.c */
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);

/* realloc.c */
char *memory_set(char *s, char byte, unsigned int num);
void ffree(char **pp);
void *_reallocate(void *ptr, unsigned int old_size, unsigned int new_size);

/* memory.c */
int bfree(void **ptr);

/* bet_check.c */
int is_interactive(info_t *info);
int is_delimeter(char c, char *delimeter);
int is_alpha(int c);
int bet_check(char *str);

/* err1.c */
int err_check(char *s);
void p_err(info_t *info, char *estr);
int p_int(int input, int fd);
char *num_swipe(long int num, int base, int flags);
void com_rem(char *buf);

/* builtins.c */
int my_exit(info_t *info);
int _mydirectory(info_t *info);
int _myhelp(info_t *info);

/* builtin2.c */
int recent_hist(info_t *info);
int str_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int p_alias(list_t *node);
int curr_alias(info_t *info);

/*_getline.c */
ssize_t input_buffer(info_t *info, char **buffer,size_t *len);
int get_input(info_t *info);
ssize_t read_buffer(info_t *info, char *buffer, size_t *i);
int _getline(info_t *info, char **ptr, size_t *length);

void sigintHandler(int sig_num);

/* getinfo.c */
void clear_information(info_t *info);
void set_information(info_t *info, char **av);
void free_information(info_t *info, int all);

/* get_environ.c */
char **get_environment(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);
int populate_env_list(info_t *info);


/* hist.c */
char *hist_file(info_t *info);
int w_hist(info_t *info);
int r_hist(info_t *info);
int b_hist_list(info_t *info, char *buf, int linecount);
int renum_hist(info_t *info);

/* li.c */
list_t *a_node(list_t **head, const char *str, int num);
list_t *a_end_node(list_t **head, const char *str, int num);
size_t p_list_s(const list_t *h);
int del_index_node(list_t **head, unsigned int index);
void f_list_nodes(list_t **head_ptr);

/* li1.c */
size_t len_of_list(const list_t *h);
char **list_to_strings(list_t *head);
size_t p_list_el(const list_t *h);
list_t *start_of_node(list_t *node, char *prefix, char c);
ssize_t index_of_node(list_t *head, list_t *node);

/* vars.c */
int chain_delimeter(info_t *info, char *buffer, size_t *p);
void check_chain(info_t *info, char *buffer, size_t *p, size_t i, size_t len);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **old, char *new);

#endif
