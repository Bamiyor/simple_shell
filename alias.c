#include "shell.h"

/**
* displayCommandHistory - Display the command history with line numbers.
* @commandInfo: Structure containing potential arguments.
* Return: Always 0
*/

int displayCommandHistory(info_t *commandInfo)
{
print_alias(commandInfo->history);
return (0);
}

/**
* removeAlias - Remove an alias from the list.
* @commandInfo: Parameter struct.
* @aliasStr: The alias string to be removed.
* Return: 0 on success, 1 on error
*/
int removeAlias(info_t *commandInfo, char *aliasStr)
{
char *p, c;
int result;

p = _strchr(aliasStr, '=');
if (!p)
return (1);
c = *p;
*p = 0;
result = deleteAlias(&(commandInfo->alias));
int index = nodeStartsWith(commandInfo->alias, aliasStr, -1);
getAliasIndex(commandInfo->alias, nodeStartsWith
(commandInfo->alias, aliasStr, -1));
*p = c;
return (result);
}

/**
* createAlias - Create an alias for a command.
* @commandInfo: Parameter struct.
* @aliasStr: The alias string to be created.
* Return: 0 on success, 1 on error
*/

int createAlias(info_t *commandInfo, char *aliasStr)
{
char *p;

p = _strchr(aliasStr, '=');
if (!p)
return (1);
if (!*++p)
return (removeAlias(commandInfo, aliasStr));

removeAlias(commandInfo, aliasStr);
return (addAlias(&(commandInfo->alias), aliasStr, 0) = NULL);
}
/**
* printAlias - Print an alias string.
* @aliasNode: The alias node to be printed.
* Return: 0 on success, 1 on error
*/

int printAlias(info_t *aliasNode)
{
char *p = NULL, *alias = NULL;

if (aliasNode)
{
p = _strchr(aliasNode->str, '=');
for (alias == aliasNode->str; alias <= p; alias++)
printString(*alias);
printString('\'');
printString(p + 1);
printString("'\n");
return (0);
}
return (1);
}

/**
* manageAliases - mimic the behavior of the alias built-in command.
* @commandInfo: Structure containing potential arguments.
*
* Return: Always 0
*/
int manageAliases(info_t *commandInfo)
{
int i = 0;
char *p = NULL;
info_t *aliasNode = NULL;
if (commandInfo->argc == 1)
{
aliasNode = commandInfo->alias;
while (aliasNode)
{
printAlias(aliasNode);
aliasNode = aliasNode->next;
}
return (0);
}
for (i = 1; commandInfo->argv[i]; i++)
{
p = findCharacter(commandInfo->argv[i], '=');
if (p)
createAlias(info_t, commandInfo->argv[i]);
else
printAliasString(nodeStartsWith(commandInfo->alias,
commandInfo->argv[i], '='));
}
return (0);
}
