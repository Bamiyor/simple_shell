#include "shell.h"

/**
* identify_chain- Checks if the current char in the
* buffer is a chain delimiter.
* @commandInfo: Parameter struct
* @buf: Character buffer
* @p: Address of the current position in buf
* return: 1 if chain delimiter, 0 otherwise
*/

int identify_chain(info_t *commandInfo, char *buf, size_t *p)
{
size_t currentPosition = *p;

if (buf[currentPosition] == '|' && buf[currentPosition + 1] == '|')
{
buf[currentPosition] = 0;
currentPosition++;
commandInfo->cmd_buf_type = CMD_OR;
}
else if (buf[currentPosition] == '&' && buf[currentPosition + 1] == '&')
{
buf[currentPosition] = 0;
currentPosition++;
commandInfo->cmd_buf_type = CMD_AND;
}
else if (buf[currentPosition] == ';')
{
buf[currentPosition] = 0;
commandInfo->cmd_buf_type = CMD_CHAIN;
}
else
{
return (0);
}
*p = currentPosition;
return (1);
}

/**
* evaluate_command_chain- It checks whether to continue chaining
* based on the last command's status.
* @commandInfo: Parameter structure
* @buf: Character buffer
* @p: Address of the current position in buf
* @i: Starting position in buf
* @len: Length of buf
*/
void evaluate_command_chain(info_t *commandInfo,
char *buf, size_t *p, size_t i, size_t len)
{
size_t currentPosition = *p;

if (commandInfo->cmd_buf_type == CMD_AND)
{
if (commandInfo->status)
{
buf[i] = 0;
currentPosition = len;
}
}
if (commandInfo->cmd_buf_type == CMD_OR)
{
if (!commandInfo->status)
{
buf[i] = 0;
currentPosition = len;
}
}

*p = currentPosition;
}

/**
* replace_aliases-Replaces aliases in the tokenized string.
* @commandInfo: Parameter structure
* return: 1 if replaced, 0 otherwise
*/
int replace_aliases(info_t *commandInfo)
{
int iteration;
list_t *aliasNode;
char *p;

for (iteration = 0; iteration < 10; iteration++)
{
aliasNode = node_starts_with(commandInfo->alias, commandInfo->argv[0], '=');
if (!aliasNode)
return (0);
free(commandInfo->argv[0]);
p = _strchr(aliasNode->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/**
* replace_variables- Replaces variables in the tokenized string.
* @commandInfo: Parameter structure
* return: 1 if replaced, 0 otherwise
*/
int replace_variables(info_t *commandInfo)
{
int iteration = 0;
list_t *envNode;

for (iteration = 0; commandInfo->argv[i]; iteration++)
{
if (commandInfo->argv[iteration][0] != '$' || !info->argv[iteration][1])
continue;

if (!_strcmp(commandInfo->argv[iteration], "$?"))
{
replace_string(&(commandInfo->argv[i]), _strdup
(convert_number(commandInfo->status, 10, 0)));
continue;
}
if (!_strcmp(commandInfo->argv[iteration], "$$"))
{
replace_string(&(info->argv[i]), _strdup(convert_number(getpid(), 10, 0)));
continue;
}
envNode = node_starts_with(commandInfo->env, &info->argv[iteration][1], '=');
if (envNode)
{
replace_string(&(commandInfo->argv[i]), _strdup
(_strchr(envNode->str, '=') + 1));
continue;
}
replace_string(&commandInfo->argv[i], _strdup(""));
}
return (0);
}

/**
* replace_string- Replaces a string.
* @old: Address of the old string
* @new: New string
* @return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (new != NULL);
}

