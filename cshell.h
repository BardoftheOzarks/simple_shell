#ifndef CSHELL_H
#define CSHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>
extern char **environ;
char *env_path(char *cmd);
char **buffsplitter(char *str);
int print(char *str);
int _getline(char *buffer, size_t *n, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
int _strlen(char *str);
#endif

#ifndef ARG_MAX
#define ARG_MAX 100
#endif
