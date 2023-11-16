#include "shell.h"

void user_command(char *command, size_t size)
{
if (fgets(command, size, stdin) == NULL)
{
if (feof(stdin))
{
bamel_print("\n");
exit(EXIT_FAILURE);
}
else
{
bamel_print("Error encountered while reading input.\n");
exit(EXIT_FAILURE);
}
command[strcspn(command, "\n")] = '\0';
}
}
