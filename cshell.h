#ifndef CSHELL_H
#define CSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>
extern char **environ;
int print(char *str);
int _getline(char *buffer, size_t *n, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *str);
#endif

#ifndef ARG_MAX
#define ARG_MAX sysconf(_SC_ARG_MAX)
#endif
