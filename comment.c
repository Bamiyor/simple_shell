#include "shell.h"

/**
* Function: safeAtoi - Converts a string to an integer with error handling.
* @s: The string to be converted.
* Return: 0 if no numbers in string, converted number otherwise, -1 on error.
*/
int safeAtoi(char *s)
{
int i = 0;
unsigned long int result = 0;

if (*s == '+')
s++;
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= (10);
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);

}
else
{
return (-1);
}
}
return (result);
}

/**
* Function: printError - It prints an error message.
* @commandInfo: The parameter & return info struct.
* @errorString: String containing specified error type.
*/
void printError(info_t *commandInfo, char *errorMsg)
{
_eputs(commandInfo->filename);
_eputs(": ");
printDecimal(commandInfo->lineCount, STDERR_FILENO);
_eputs(": ");
_eputs(commandInfo->argv[0]);
_eputs(": ");
_eputs(errorMsg);
}

/**
* Function: printDecimal - It prints a decimal (integer) number (base 10).
* @input: The input.
* @fileDescriptor: The file descriptor to write to.
* Return: Number of characters printed.
*/
int printDecimal(int input, int fileDescriptor)
{
int (*outputChar)(char) = _putchar;
int i, count = 0;
unsigned int absolute, current;

if (fileDescriptor == STDERR_FILENO)
outputChar = _eputchar;

if (input < 0)
{
absolute = -input;
outputChar('-');
count++;
}
else
{
absolute = input;
}
current = absolute;
for (i = 1000000000; i > 1; i /= 10)
{
if (absolute / i)
{
outputChar('0' + current / i);
count++;
}
current %= i;
}
outputChar('0' + current);
count++;

return (count);
}

/**
* Function: convertNumber - Converter function, a clone of itoa.
* @num: Number.
* @base: Base.
* @flags: Argument flags.
* Return: String.
*/
char *convertNumber(long int num, int outputBase, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}

char *characterSet = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
* Function: removeComments - Replaces the first instance of '#' with '\0'.
* @buf: Address of the string to modify.
*/
void removeComments(char *text)
{
int i;

for (i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
}
