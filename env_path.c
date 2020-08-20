#include "cshell.h"
#include <dirent.h>
#include <errno.h>
/**
 * env_path - gets the correct path
 * @cmd: argv[0]
 * Return: string with correct path
 */
char *env_path(char *cmd)
{
	int j = 0;
	char *path;
	char *dir;
	DIR *dp;
	struct dirent *entry;

	for (j = 0; environ[j] != NULL; j++)
		if (_strncmp("PATH", environ[j], 4) == 0)
		{
			path = _strdup(environ[j]);
			break;
		}
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
				closedir(dp);
				free(path);
				return (dir);
			}
			closedir(dp);
		}
	}
	return (0);
}
/**
 * buffsplitter - tokates the buffer
 * @str: input string
 * Return: tokated array of strings
 */
char **buffsplitter(char *str)
{
	const  char delim[2] = " ";
	char **token = malloc(sizeof(char *) * ARG_MAX);
	char *temp;

	temp = strtok(str, delim);
	token[0] = strdup(temp);
	printf("%s", token[0]);
	temp = strtok(NULL, delim);
	token[1] = strdup(temp);
	token[2] = '\0';
	return (token);
}
