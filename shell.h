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

/*
 * This module encompasses a set of functions for user interaction and command
 */

void constant_display(void);
void bamel_print(const char *format);
void run_command(const char *command);
void user_command(char *command, size_t size);

#endif
