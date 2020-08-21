#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
/**
 * env_path - gets the path
 * @cmd: simple command
 * Return: string with full path
 */
char *env_path(char *cmd)
{
	int j = 0;
	char *path, *dir, *answer;
	DIR *dp;
	struct dirent *entry;

	while (environ[j] != NULL)
	{
		if (_strncmp("PATH", environ[j], 3) == 0)
		{
			path = _strdup(environ[j]);
			dir = strtok(path, "=");

			while (dir != NULL)
			{
				dir = strtok(NULL, ":");
				dp = opendir(dir);
				while ((entry = readdir(dp)) != NULL)
				{
					if (_strcmp(entry->d_name, ".") == 0 || _strcmp(entry->d_name, "..") == 0)
						continue;
					if (_strcmp(cmd, entry->d_name) == 0)
					{
						answer = _strdup(dir);
						free(path);
						closedir(dp);
						return (answer);
					}
				}
				closedir(dp);
			}
			free(path);
			return (0);
		}
		j++;
	}
	return (0);
}
