#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define ARGS 20

extern char **environ;

void exec_command(void);
int _putchar(char c);
char *_getenv(const char *name);

#endif
