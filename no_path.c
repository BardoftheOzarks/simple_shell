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
    char **av = _calloc(ARG_MAX, sizeof(char *));
    int i, j = 0;


        i = 0;
        j = _strlen(buf);
        
        av[i] = strtok(buf, " "); /*write func _strtok*/
        printf("%d\n", j);
		while (av[i] && i <= ARG_MAX)
        {
            
			av[++i] = strtok(NULL, " ");
        }
		av[i] = '\0';

            execve(av[0], av, environ);
			exit(0);
			
}

/**
 av[i] = malloc(sizeof(char) * j);
 av[i] = malloc(sizeof(char) * j);
 */
