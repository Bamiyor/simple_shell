#include "shell.h"

/*
 * @brief prototype of the bamel_print.
 * bamel_print : function was designed  for formated data output.
 */

void bamel_print(const char *format)
{
write(STDOUT_FILENO, format, strlen(format));
}

