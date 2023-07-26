#include "shell.h"
/**
 * _getpath - get the environment variable PATH
 * @env: environment variable
 * Return: value of PATH environment
 */

char *_getpath(char **env)
{
	size_t ex = 0, ar = 0, count = 5;
	char *path = NULL;

	for (ex = 0; _strncmp(env[ex], "PATH=", 5); ex++)
		;
	if (env[ex] == NULL)
		return (NULL);

	for (count = 5; env[ex][ar]; ar++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (ar = 5, count = 0; env[ex][ar]; ar++, count++)
		path[count] = env[ex][ar];

	path[count] = '\0';
	return (path);
}

/**
 * _get_command - get the user's command
 * Return: the command entered by user
 */

char *get_command (void)
{
	char *line = NULL;
	size_t _user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$: ", 3);

	if (getline(&line, &_user, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
