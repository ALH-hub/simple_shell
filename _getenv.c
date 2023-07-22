#include "shell.h"

/**
 * _getenv - search for an environmental variable
 * @name: the name of the variable looking for
 * Return: the pointer to the variable on succes
 *	NULL if variable not found
 */

char *_getenv(const char *name)
{
	char *value = NULL;
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
		{
			value = *env + strlen(name) + 1;
			break;
		}
		env++;
	}
	return (value);
}
