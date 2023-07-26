#include "shell.h"
/**
 * _fork - creates forked processes
 *@arg: arguments.
 *@av: program's name.
 *@env: environment variable
 *@lineptre: command entered by user
 *@id: id of current process
 *@count: new task added.
 *Return: 0 on success
 */

int _fork(char **arg, char **av,
		char **env, char *lineptre, int id, int count)
{
	int status;
	pid_t child;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], id, arg[0]);
			if (!count)
				free(arg[0]);
			free(arg);
			free(lineptre);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
