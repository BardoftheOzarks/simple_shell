#include "cshell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>

/**
 * _getpath - extracts and tokates PATH
 * Return: pointer to array of directories
 */
char **_getpath(void)
{
	int i = 0, j = 0;
	char *dir[100];
	char *path;
	char *junk;

	while (environ[j])
	{
		if (_strncmp("PATH", environ[j], 4) == 0)
		{
			path = environ[j];
			break;
		}
		j++;
	}
	junk = strtok(path, "=");
	free(junk);
	dir[i] = strtok(NULL, ":");
	while (dir[i])
	{
		i++;
		dir[i] = strtok(NULL, ":");
	}
	return (dir);
}
