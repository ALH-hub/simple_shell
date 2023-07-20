#include "shell.h"

int _puts(char *str);

/**
 * exec_word_command - execute a one word command
 * Return: nothing
 */

void exec_command(void)
{
	ssize_t bufsize = 0;
	char *line = NULL;
	char **env = environ;
	pid_t child_pid;
	int status;

	_puts("#cisfunc$ ");
	if (getline(&line, &bufsize, stdin) == -1)
	{
		_puts("Usage: simple_shell");
		return;
	}

	char *token = strtok(line, " \n");

	if (token == NULL)
		return;

	char *argv[] = {token, NULL, NULL};

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(token, argv, env) == -1)
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
