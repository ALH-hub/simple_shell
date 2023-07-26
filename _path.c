#include "shell.h"

/**
 * _path - looks for the variable provided
 * @env: environment variable variable.
 * Return: the value of the environment
 */

char *_path(char **env)
{
	char *path = NULL;
	size_t k = 0;
	size_t j = 0;
	size_t i = 5;

	for (k = 0; _strncmp(env[k], "PATH=", 5); k++)
		;
	if (env[k] == NULL)
		return (NULL);
	for (i = 5; env[k][j]; j++, k++)
		;
	path = malloc(sizeof(char) * (i + 1));
	if (path == NULL)
	{
		return (NULL);
	}
	for (j = 5, i = 0; env[k][j];
			j++, i++)
		path[i] = env[k][j];
	path[i] = '\0';

	return (path);
}
