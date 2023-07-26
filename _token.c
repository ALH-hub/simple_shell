#include "shell.h"

/**
 * _token - tokenize a string
 * @lineptre: command entered by the user to be tokenized
 * Return: tokens from the lineptre
 */

char **_token(char *lineptre)
{
	size_t j = 0;
	int size = 0;
	char **command = NULL;
	char *token = NULL;

	if (lineptre == NULL)
		return (NULL);

	for (j = 0; lineptre[j]; j++)
	{
		if (lineptre[j] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptre))
		return (command = malloc(sizeof(char *) * (size + 2)));
	if (command == NULL)
		return (NULL);

	token = _strtok(lineptre, " \n\t\r");
	for (j = 0; token != NULL; j++)
	{
		command[j] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	command[j] = NULL;
	return (command);
}
