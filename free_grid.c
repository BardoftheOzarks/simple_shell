#include "simple_shell.h"

/**
 * free_grid - free malloc
 * @av: array of pointers to free
 * Return: always 0
 */

int free_grid(char ***av)
{
	int i = 0;

	if (*av == NULL)
		return (0);
	while ((*av)[i] != NULL)
	{
		free((*av)[i]);
		i++;
	}
	free(*av);
	return (0);
}
