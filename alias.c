#include "shell.h"

/**
* Function: displayCommandHistory
* Description: Display the command history with line numbers.
* @info: Structure containing potential arguments.
* Return: Always 0
*/
int displayCommandHistory(info_t *commandInfo)
{
printListWithLineNumbers(commandInfo->history);
return (0);
}

/**
* Function: removeAlias
* Description: Remove an alias from the list.
* @info: Parameter struct.
* @aliasStr: The alias string to be removed.
* Return: 0 on success, 1 on error
*/
int removeAlias(info_t *commandInfo, char *aliasStr)
{
char *p, c;
int result;

p = findCharacter(aliasStr, '=');
if (!p)
return (1);
c = *p;
*p = 0;
result = deleteAliasNode(&(commandInfo->alias)),
getAliasNodeIndex(commandInfo->alias, nodeStartsWith(commandInfo->alias, aliasStr, -1));
*p = c;
return (result);
}

/**
* Function: createAlias
* Description: Create an alias for a command.
* @info: Parameter struct.
* @aliasStr: The alias string to be created.
* Return: 0 on success, 1 on error
*/
int createAlias(info_t *commandInfo, char *aliasStr)
{
char *p;

p = findCharacter(aliasStr, '=');
if (!p)
return (1);
if (!*++p)
return (removeAlias(commandInfo, aliasStr));

removeAlias(info, aliasStr);
return (addAliasNodeEnd(&(commandInfo->alias), aliasStr, 0) == NULL);
}
/**
* Function: printAliasString
* Description: Print an alias string.
* @aliasNode: The alias node to be printed.
* Return: 0 on success, 1 on error
*/
int printAliasString(aliasNode_t *aliasNode)
{
char *p = NULL, *alias = NULL;

if (aliasNode)
{
p = findCharacter(aliasNode->str, '=');
for (alias = aliasNode->str; alias <= p; alias++)
printCharacter(*alias);
printCharacter('\'');
printString(p + 1);
printString("'\n");
return (0);
}
return (1);
}

/**
* Function: manageAliases
* Description: Mimic the behavior of the alias built-in command.
* @info: Structure containing potential arguments.
* Return: Always 0
*/
int manageAliases(info_t *commandInfo)
{
int i = 0;
char *p = NULL;
aliasNode_t *aliasNode = NULL;
if (commandInfo->argc == 1)
{
aliasNode = commandInfo->alias;
while (aliasNode)
{
printAliasString(aliasNode);
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
printAliasString(nodeStartsWith(commandInfo->alias, commandInfo->argv[i], '='));
}
return (0);
}
