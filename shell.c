#include "shell.h"

/**
 * exec_command - execute the command from user
 * @env: environment variable.
 * @av: arguments of the command
 * @path: path to the command
 * Return: _exit.
 */

int exec_command(char **env, char **av, int path)
{
	char *command = NULL;
	char **user_command = NULL;
	int _exit = 0;
	int k = 0;

	command = get_command();
	if (command)
	{
		path++;
		user_command = _token(command);
		if (!user_command)
		{
			free(command);
			return (_exit);
		}
		if (!(_strcmp(user_command[0], "exit")) && user_command[1] == NULL)
			exit_cmd(user_command, command, _exit);

		if (!_strcmp(user_command[0], "env"))
			_printenv(env);
		else
		{
			k = sep_path(&user_command[0], env);
			_exit = _fork(user_command, av, env, command, path, k);
			if (k == 0)
				free(user_command[0]);
		}
		free(user_command);
	}
	else
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(_exit);
	}
	free(command);
	return (_exit);
}



/**
 * main - shell main function
 * @ac: argument counter.
 * @av: argument variables
 * @env: environment variables
 * Return: exit.
 */

int main(int ac, char **av, char **env)
{

	int path = 0;
	int exit = 0;
	(void)ac;

	while (1)
	{
		exit = exec_command(env, av, path);
	}
	return (exit);
}
