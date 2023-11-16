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
* @str: The alias string to be removed.
* Return: 0 on success, 1 on error
*/
int removeAlias(info_t *commandInfo, char *str)
{
char *p, c;
int result;

<<<<<<< HEAD
p = _strchr(str, '=');
=======
p = _strchr(aliasStr, '=');
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
if (!p)
return (1);
c = *p;
*p = 0;
<<<<<<< HEAD
result = delete_node_at_index(&(commandInfo->alias),
get_node_index(commandInfo->alias, starts_with
(commandInfo->alias, str, -1)));
=======
result = deleteAlias(&(commandInfo->alias));
int index = nodeStartsWith(commandInfo->alias, aliasStr, -1);
getAliasIndex(commandInfo->alias, nodeStartsWith
(commandInfo->alias, aliasStr, -1));
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
*p = c;
return (result);
}

/**
* createAlias - Create an alias for a command.
* @commandInfo: Parameter struct.
* @str: The alias string to be created.
* Return: 0 on success, 1 on error
*/

int createAlias(info_t *commandInfo, char *str)
{
char *p;

<<<<<<< HEAD
p = _strchr(str, '=');
=======
p = _strchr(aliasStr, '=');
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
if (!p)
return (1);
if (!*++p)
return (remove_alias(commandInfo, str));

<<<<<<< HEAD
remove_alias(commandInfo, str);
return (add_node_end(&(commandInfo->alias), str, 0) == NULL);
}
/**
* printAliasString - Print an alias string.
* @node: The alias node to be printed.
* Return: 0 on success, 1 on error
*/

int printAliasString(list_t *node)
=======
removeAlias(commandInfo, aliasStr);
return (addAlias(&(commandInfo->alias), aliasStr, 0) = NULL);
}
/**
* printAlias - Print an alias string.
* @aliasNode: The alias node to be printed.
* Return: 0 on success, 1 on error
*/

int printAlias(info_t *aliasNode)
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
{
char *p = NULL, *alias = NULL;

if (node)
{
<<<<<<< HEAD
p = _strchr(node->str, '=');
for (alias = node->str; alias <= p; alias++)
_putchar(*alias);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
=======
p = _strchr(aliasNode->str, '=');
for (alias == aliasNode->str; alias <= p; alias++)
printString(*alias);
printString('\'');
printString(p + 1);
printString("'\n");
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
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
<<<<<<< HEAD
list_t *node = NULL;
=======
info_t *aliasNode = NULL;
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
if (commandInfo->argc == 1)
{
node = commandInfo->alias;
while (node)
{
<<<<<<< HEAD
printAlias_string(node);
node = node->next;
=======
printAlias(aliasNode);
aliasNode = aliasNode->next;
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
}
return (0);
}
for (i = 1; commandInfo->argv[i]; i++)
{
p = _strchr(commandInfo->argv[i], '=');
if (p)
createAlias(commandInfo, commandInfo->argv[i]);
else
<<<<<<< HEAD
{
print_alias(nodeStartsWith(commandInfo->alias,
=======
printAliasString(nodeStartsWith(commandInfo->alias,
>>>>>>> 9247e40a69bceaccab3625a9dd09ffadd7c6d1d8
commandInfo->argv[i], '='));
}
return (0);
}
