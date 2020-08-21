B#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * buf_splitter - tokates input string
 * @buf: input string
 * Return: double pointer to tokated string
 */
char **buf_splitter(char *buf)
{
	char **av = malloc(sizeof(char *) * 10);
	char *cmd, *free_ptr, *temp;
	int i;

	if (buf[0] == '/' || buf[0] == ' ' || buf[0] == '.')
	{	i = 0;
		temp = strtok(buf, " ");
		av[i] = _strdup(temp);
		i++;
		while (i < 10)
		{	temp = strtok(NULL, " ");
			if (temp == NULL)
				break;
			av[i] = _strdup(temp);
			i++;	}
		av[i] = NULL;
		return (av);	}
	i = 0;
	av[i] = strtok(buf, " "); /*write func _strtok*/
	cmd = av[0];
	while (av[i] && i <= ARG_MAX)
		av[++i] = strtok(NULL, " ");
	av[i] = '\0';
	av[0] = env_path(av[0]);
	if (av[0] == '\0' || av[0] == NULL)
	{	free_grid(&av);
		EXIT_FAILURE;	}
	free_ptr = av[0];
	av[0] = _strcat(av[0], "/");
	free(free_ptr);
	free_ptr = av[0];
	av[0] = _strcat(av[0], cmd);
	free(free_ptr);
	return (av);
}
