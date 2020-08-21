#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * no_path - tokates a string
 * @buf: string to token
 * Return: Nothing, it kills a child
 */
char no_path(char *buf)
{
	char **av = _calloc(ARG_MAX, sizeof(char *));
	int i = 0;

	av[i] = strtok(buf, " "); /*write func _strtok*/
	while (av[i] && i <= ARG_MAX)
		av[++i] = strtok(NULL, " ");
	av[i] = '\0';
	execve(av[0], av, environ);
	exit(0);
}
