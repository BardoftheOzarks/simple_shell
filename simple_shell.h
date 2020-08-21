#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
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
char *_strcat(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);
char **buf_splitter(char *buf);
int free_grid(char ***grid);
void print_tokens(char **t);
#endif

#ifndef ARG_MAX
#define ARG_MAX 100
#endif
