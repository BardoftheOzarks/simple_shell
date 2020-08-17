#ifndef CSHELL_H
#define CSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
int print(char *str);
int _getline(char *buffer, size_t *n, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
#endif
