#include "shell.h"

/**
 * exit_cmd - close the shell with exit command
 * @arg: argument.
 * @line: command entered by user
 * @_exit: exiting value
 */

void exit_cmd(char **arg, char *line, int _exit)
{
	int status = 0;

	if (!arg[1])
	{
		free(line);
		free(arg);
		exit(_exit);
	}
	status = _atoi(arg[1]);

	free(line);
	free(arg);
	exit(status);
}

/**
 * _printenv - gets the env variable.
 * @env: env variable
 * Return: 0
 */

void _printenv(char **env)
{
	size_t i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
