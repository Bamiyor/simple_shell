#ifndef _SHELL_H_
#define _SHELL_H_

/*
 * This C program incoporates a set of standard libraries for different
 * functionalities such as string handling,memory allocation,
 * input/output operations and more.
 */

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>

/**
 * They define numeric identifiers for different
 * command types within the shell program.
 * they are used to represent the type of command chaining.
 *
 * CMD_NORM: Standard command execution
 * CMD_OR: Logical OR command chaining
 * CMD_AND:Logical AND command chaining
 * CMD_CHAIN:Generic command chaining
 */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3


/**
 * Buffer size constants for efficient I/O operations.
 * READ_BUF_SIZE: Size for reading input data.
 * WRITE_BUF_SIZE: Size for writing output data.
 * BUF_FLUSH: Signal for flushing the buffer.
 */

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/**
 * External declaration for the 'environ' variable.
 * 'environ' typically holds the program's environment variables.
 */

extern char **environ;

/**
 * for convert_number()
 *
 */

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * 1 if using system getline()
 */

#define USE_GETLINE 0
#define USE_STRTOK 0

/**
 * file i/o constants
 */

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

/**
 *struct liststr -singly linked list
 *@str:a string
 *@num:the number field
 *@next:points to the next node
 */

typedef struct liststr
{
int num;
char *str;
struct liststr *next;
}
list_t;

/**
* Structure passinfo - contains pseudo-arguments to pass into a function,
* allowing a uniform prototype for a function pointer struct.
* @arg: a string generated from getline containing arguments
* @argv: an array of strings generated from arg
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
* @info_t: represents a structure
* @status: the return status of the last exec'd command
* @cmd_buf: address of pointer to cmd_buf, on if chaining
* @cmd_buf_type: CMD_type ||, &&, ;
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
char **cmd_buf;
int cmd_buf_type;
int readfd;
int histcount;
} 
info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - It contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */

typedef struct builtin
{
char *type;
int (*func)(info_t *);
}
builtin_table;

/**
 * shell_loop.c
 */

int shell_loop(info_t *info, char **av);
int locateBuiltInCommand(info_t *info);
void locate_command(info_t *info);
void fork_command(info_t *info);

/**
 * inputParser.c
 */

int is_executableCommand(info_t *info, char *path);
char *copy_chars(char *pathstr, int start, int stop);
char *findPath(info_t *info, char *pathstr, char *cmd);

/**
 * alias.c
 */

int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);

/**
 * environ.c
 */

char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);

/**
 * exec.c
 */

void run_command(const char *command);

/**
 * bamel_print.c
 */

void bamel_print(const char *format);

/**
 * input_command.c
 */

void user_command(char *command, size_t size);

/**
 * string_ops.c
 */

int _string_length(char *s);
int _string_compare(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *string_concatenate(char *dest, char *src);

/**
 * string_ops1.c
 */

char *string_copy(char *dest, char *src);
char *string_duplicate(const char *str);
void print_string(char *str);
int _putchar(char c);

/**
*reallocator.c
*/

char *_memset(char *s, char b, unsigned int n);
void release_string_array(char **str_array);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
*error_code.c
*/

void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/**
 * error_code1.c
 */

int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);

/**
 * var.c
 */

int identify_chain(info_t *commandInfo, char *buf, size_t *p);
void evaluate_command_chain(info_t *commandInfo, char
*buf, size_t *p, size_t i, size_t len);
int replace_aliases(info_t *commandInfo);
int replace_variables(info_t *commandInfo);
int replace_string(char **old, char *new);

/**
 * histfile.c
 */

char *get_history_file(info_t *info);
int writeHistory(info_t *info);
int readHistory(info_t *info);
int build_historyList(info_t *info, char *buf, int linecount);
int update_historyNumbers(info_t *info);

/**
 * memoryUtils.c
 */

int free_andNull(void **ptr);

/**
 * comment.c
 */

int safeAtoi(char *s);
void printError(info_t *commandInfo, char *errorMsg);
int printDecimal(int input, int fileDescriptor);
char *convertNumber(long int num, int outputBase, int flags);
void removeComments(char *text);

/**
  * constant.c
  */

void constant_display(void);

/**
 * exit.c
 */

char *_strncpy(char *dest, const char *src, int n);
char *_strncat(char *dest, const char *src, int n);
char *_strchr(const char *s, int c);

/**
 * getline1.c
 */

ssize_t input_buffer(info_t info, char *buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buffer(info_t *info, char *buf, size_t *i);
int custom_getline(info_t info, char *ptr, size_t *length);
void sigintHandler(__attribute__((unused)) int sig_num);


/**
 * LLops.c
 */

list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

/**
 * LLops1.c
 */

size_t linked_list_length(const list_t *h);
char **linked_list_to_strings(list_t *head);
size_t print_linked_list(const list_t *h);
list_t *findNodeWithPrefixAndChar(list_t *node, char *prefix, char c);
ssize_t indexOfListNode(list_t *head, list_t *node);

/**
 * shell.c
 */

int main(int argc, char **argv[]);

/**
 * tokenizer.c
 */
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);


#endif
