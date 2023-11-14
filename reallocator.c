#include "shell.h"

/**
**_memset - fills memory with a constant byte
*@dest: the pointer to the memory area
*@b: the byte to fill *s with
*@n: the amount of bytes to be filled
*Return: a pointer to the memory area s
*/
char *_memset(char *dest, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
dest[i] = b;
return (dest);
}

/**
*release_string_array: Releases a string of strings
* @str_array: string of strings
*/
void release_string_array(char **str_array)
{
char **a = str_array;

if (!str_array)
return;
while (*str_array)
free(*str_array++);
free(a);
}

/**
* _realloc - reallocates a block of memory
* @ptr: pointer to previous malloc'ated block
* @old_size: byte size of previous block
* @new_size: byte size of new block
*
* Return: pointer to da ol'block nameen.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *newPtr;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

newPtr = malloc(new_size);
if (!newPtr)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
newPtr[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (newPtr);
}

