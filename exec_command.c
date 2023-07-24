#include "shell.h"

int _puts(char *str);
int search_command(char **argv, char *path);
void exec_command(void);

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
	size_t bufsize = 0;
	char *line = NULL;
	char **env = environ;
	char *argv[ARGS];
	pid_t child_pid;
	int status, i = 1;
	char *token = NULL;
	char *path = _getenv("PATH");

	fflush(stdout);
	_puts("#cisfunc$ ");
	if (getline(&line, &bufsize, stdin) == -1)
	{
		exit(1);
	}

	token = strtok(line, " \n");

	if (token == NULL)
		return;

	argv[0] = token;

	while ((token = strtok(NULL, " \n")) != NULL)
	{
		argv[i] = token;
		i++;
	}
	argv[i] = NULL;

	if ((_strcmp(argv[0], "exit") == 0) && (argv[1] == NULL))
		exit(0);

	i = 0;
	if ((_strcmp(argv[0], "env") == 0) && (argv[1] == NULL))
	{
		while (env[i] != NULL)
		{
			_puts(env[i]);
			_putchar('\n');
			i++;
		}
		return;
	}

	if (search_command(argv, path) == 1)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				perror("Error");
		} else
			wait(&status);
	} else
		if (execve(argv[0], argv, env) == -1)
			perror("Error");

	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
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

/**
 * search_command - search for the presence of a command in a file
 * @argv: the command found at argv[0] of the array
 * @path: the path to search the command in
 * Return: 1 if found and 0 if not found
 */

int search_command(char **argv, char *path)
{
	char *command = argv[0];
	struct stat status;
	char pathc[1024];
	char *token = NULL;

	_strcpy(pathc, path);

	if (pathc == NULL || command == NULL || (pathc[0] == '\0'))
		return (0);

	if (stat(command, &status) == 0)
		return (1);

	token = strtok(pathc, ":");

	while (token != NULL)
	{
		char pathbuf[1024];

		_strcpy(pathbuf, token);
		_strcat(pathbuf, "/");
		_strcat(pathbuf, command);

		if (stat(pathbuf, &status) == 0)
		{
			argv[0] = pathbuf;
			return (1);
		}
		token = strtok(NULL, ":");
	}

	return (0);
}
