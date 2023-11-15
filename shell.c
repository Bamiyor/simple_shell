#include "shell.h"

/**
 * main - this is the entry point of the shell program.
 *
 * Description: This function initializes the shell
 * @argv: is n array of strings containing command-line arguments
 * @argc: shows the count of command-line arguments.
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
info_t info[] = { INFO_INIT };
int fd = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd));

if (argc == 2)
{
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = fd;
}

char command[150];

while (TRUE)
{
input_command();
user_command(command, sizeof(command));
run_command(command);
}

return (EXIT_SUCCESS);
}
