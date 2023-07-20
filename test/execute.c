#include "main.h"

/**
 * execute_command - executes command from stdin
 * @token: Tokenized command
 * @command: Command from stdin
 */
void execute_command(char **token, char *command)
{
	if (execve(token[0], token, NULL) == -1)
	{
		fprintf(stderr, "%s: command is not found\n",command);
		exit(1);
	}
}
