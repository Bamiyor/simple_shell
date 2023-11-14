#include "shell.h"

/**
* get_history_file: Obtains the history file
* @info: parameter struct
*
* Return: allocated string containg history file
*/

char *get_history_file(info_t *info)
{
char *buf, *dir;

dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
string_copy(buf, dir);
string_concatenate(buf, "/");
string_concatenate(buf, HIST_FILE);
return (buf);
}

/**
* writeHistory - creates a file, or appends to an existing file
* @info: the parameter struct
*
* Return: 1 on success, else -1
*/
int writeHistory(info_t *info)
{
ssize_t file_descriptor;
char *filename = get_history_file(info);
list_t *node = NULL;

if (!filename)
return (-1);

file_descriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (file_descriptor == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, file_descriptor);
_putfd('\n', file_descriptor);
}
_putfd(BUF_FLUSH, fd);
close(file_descriptor);
return (1);
}

/**
* readHistory- reads history from file
* @info: the parameter struct
*
* Return: histcount on success, 0 otherwise
*/
int readHistory(info_t *info)
{
int i, last = 0, linecount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_history_file(info);

if (!filename)
return (0);

file_descriptor = open(filename, O_RDONLY);
free(filename);
if (file_descriptor == -1)
return (0);
if (!fstat(file_descriptor, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(file_descriptor, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(file_descriptor);
for (i = 0; i < fsize; i++)
if (buf[i] == '\n')
{
buf[i] = 0;
build_historyList(info, buf + last, linecount++);
last = i + 1;
}
if (last != i)
build_historyList(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
* build_historyList: Adds entry to a history linked list
* @info: Structure containing potential arguments. Used to maintain
* @buf: buffer
* @linecount: the history linecount, histcount
*
* Return: Always 0
*/
int build_historyList(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
* update_historyNumbers: Updates the history linked list after changes
* @info: Structure containing potential arguments. Used to maintain
*
* Return: the new histcount
*/
int update_historyNumbers(info_t *info)
{
list_t *current_node = info->history;
int i = 0;

while (current_node)
{
current_node->num = i++;
current_node = current_node->next;
}
return (info->histcount = i);
}

