#include "simple_shell.h"
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
	int i = 0;

	if (buf[0] == '/' || buf[0] == ' ' || buf[0] == '.')
	{	temp = strtok(buf, " ");
		av[i] = _strdup(temp);
		while (++i < 10)
		{	temp = strtok(NULL, " ");
			if (temp == NULL)
				break;
			av[i] = _strdup(temp);
			i++;	}
		av[i] = NULL;
		return (av);	}
	i = 0;
	temp = strtok(buf, " ");
	av[i] = _strdup(temp);
	cmd = av[i];
	while (++i < 10)
	{	temp = strtok(NULL, " ");
		if (temp == NULL)
			break;
		av[i] = _strdup(temp);	}
	av[i] = NULL;
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
	free(cmd);
	free(temp);
	return (av);
}
