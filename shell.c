#include "shell.h"

/**
 * main - test code
 * Return: nothing
 */

int main(int ac, char **av)
{
	if (ac < 0)
		exit(1);

	while (1)
	{
		exec_command(av);
	}
}
