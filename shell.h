#ifndef SHELL_H
#define SHELL_H

/*
 * This C program incoporates a set of standard libraries for different functionalities such as string handling,memory allocation,input/output operations and more.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stst.h>
#include <limits.h>

/**
 * They define numeric identifiers for different command types within the shell program.
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


/** Buffer size constants for efficient I/O operations.
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
#define USE STRTOK 0

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
chat *str;
struct liststr *next;
}
list_t;


/*
 * This module encompasses a set of functions for user interaction and command
 */

void constant_display(void);
void bamel_print(const char *format);
void run_command(const char *command);
void user_command(char *command, size_t size);
void display_environs(char **env);
ssize_t input_buffer(info_t *info, char **buf, size_t *len);
void removeComments(char *text);
void printError(info_t *commandInfo, char *errorMsg);
void evaluate_command_chain(info_t *commandInfo,char *buf,size_t i,size_t len);

#endif
