#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
* main - It's a shell
* Return: Nothing, it's an empty shell
*/
char no_path(char *buf)
{
    char **av = malloc(sizeof(char *) * ARG_MAX);
    int i;


        i = 0;
        av[i] = strtok(buf, " "); /*write func _strtok*/
		while (av[i] && i <= ARG_MAX)
			av[++i] = strtok(NULL, " ");
		av[i] = NULL;

            execve(av[0], av, environ);
			exit(0);
			
}