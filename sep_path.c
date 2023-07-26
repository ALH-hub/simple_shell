#include "shell.h"
/**
 * sep_path - tokenize the path environment
 * @arg: the command
 * @env: environment variable
 * Return: -1 on failue, 0 on success
 */
int sep_path(char **arg, char **env)
{
	char *token = NULL;
	char *path1 = NULL, *path2 = NULL;
	size_t _path;
	size_t command;
	struct stat lineptre;

	if (stat(*arg, &lineptre) == 0)
		return (-1);
	
	path1 = _getpath(env);
	if (!path1)
		return (-1);
	
	token = _strtok(path1, ":");
	command = _strlen(*arg);
	while (token)
	{
		_path = _strlen(token);
		path2 = malloc(sizeof(char) * (_path + command + 2));
		if (!path2)
		{
			free(path1);
			return (-1);
		}
		path2 = _strcpy(path2, token);
		_strcat(path2, "/");
		_strcat(path2, *arg);

		if (stat(path2, &lineptre) == 0)
		{
			*arg = path2;
			free(path1);
			return (0);
		}
		free(path2);
		token = _strtok(NULL, ":");
	}
	free(path1);
	return (-1);
}
