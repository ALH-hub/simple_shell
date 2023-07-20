#include "main.h"

/**
 * main - Entry of the program
 *
 * Return: 1 (Success)
 */
int main()
{
	char *command[MAX_COMMAND];
	char *token;
	char *args[2];
	char prompt[] = "Simple_shell$ ";
	pid_t pid;
	int status;

	while (true)
	{
		printf("%s", prompt);
		fflush(stdout);

		/* gets input from stdin and breaks if input is Ctrl+D */
		if (fgets(command, sizeof(command), stdin) == -1)
		{
			printf("\n");
			break;
		}

		/* Removes trailing spaces from command */
		command[strcspn(command, "\n")] = '\0';

		/* Using a while space delimeter to get token */
		token = strtok(command, " ");

		/* Continue if no command entered */
		if (token == NULL)
			continue;

		/* Get process id and execute */
		pid = fork();
		if (pid < 0)
		{
			fprintf(stderr, "Fork failed\n");
			continue;
		}
		else if (pid == 0)
		{
			args[0] = token;
			args[1] = NULL;
			execute_command(args, command);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(command);
	return (0);
}
