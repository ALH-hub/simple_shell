#include "shell.h"

int _puts(char *str);

/**
 * exec_command - execute a one word command
 *
 * Description:
 *	execute a command provided on the terminal
 *	takes in account the aguments passed to the command
 *
 * Return: nothing
 */

void exec_command(void)
{
	ssize_t bufsize = 0;
	char *line = NULL;
	char **env = environ;
	char *argv[ARGS];
	pid_t child_pid;
	int status, i = 1;

	_puts("#cisfunc$ ");
	if (getline(&line, &bufsize, stdin) == -1)
	{
		_puts("Usage: simple_shell");
		return;
	}

	char *token = strtok(line, " \n");

	if (token == NULL)
		return;
	argv[0] = token;

	while ((token = strtok(NULL, " \n")) != NULL)
	{
		argv[i] = token;
		i++;
	}
	argv[i] = NULL;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("Error");
		}
	} else
	{
		wait(&status);
	}
	free(line);
	line = NULL;
}

/**
 * _puts - print a given string
 * @str: the string to print
 * Return: the number of characters printed
 */

int _puts(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
	return (count);
}
