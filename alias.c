#include "shell.h"

/**
* displayCommandHistory - Display the command history with line numbers.
* @commandInfo: Structure containing potential arguments.
* Return: Always 0
*/

int displayCommandHistory(info_t *commandInfo)
{
printListWithLineNumbers(commandInfo->history);
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

p = findCharacter(aliasStr, '=');
if (!p)
return (1);
c = *p;
*p = 0;
<<<<<<< HEAD
result = deleteAliasNode(&(commandInfo->alias))
int index = nodeStartsWith(commandInfo->alias, aliasStr, -1);
=======
result = deleteAliasNode(&(commandInfo->alias)),
getAliasNodeIndex(commandInfo->alias, nodeStartsWith
(commandInfo->alias, aliasStr, -1));
>>>>>>> 6e8d29b63eeb3ec6e561935ab5129e02a19e17b0
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

p = findCharacter(aliasStr, '=');
if (!p)
return (1);
if (!*++p)
return (removeAlias(commandInfo, aliasStr));

removeAlias(info, aliasStr);
return (addAliasNodeEnd(&(commandInfo->alias), aliasStr, 0) == NULL);
}
/**
* printAliasString - Print an alias string.
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
* manageAliases - mimic the behavior of the alias built-in command.
* @commandInfo: Structure containing potential arguments.
*
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
<<<<<<< HEAD
printf("%d", P(nodeS(commandInfo->alias, commandInfo->argv[i], '=')));
=======
printAliasString(nodeStartsWith(commandInfo->alias,
commandInfo->argv[i], '='));
>>>>>>> 6e8d29b63eeb3ec6e561935ab5129e02a19e17b0
}
return (0);
}
