#ifndef MAIN_H
#define MAIN_H

/* Standard libraries included */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Defined variables */
#define MAX_COMMAND 100


/* Prototypes of functions created */
void execute_command(char **token, char *command);

#endif
