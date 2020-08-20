#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
* main - It's a shell
* Return: Nothing, it's an empty shell
*/
int main(void)
{
	int status, len, i;
	size_t size = 0;
	char *buf = NULL, **av = malloc(sizeof(char *) * ARG_MAX);
	char *fullcmd, *path, *cmd;
	pid_t pid;

	while (1)
	{
		print("Sea-Shell$ ");
		status = getline(&buf, &size, stdin);

		if (status == -1)
			break;
		len = _strlen(buf);
		buf[len - 1] = '\0';
		if (_strcmp(buf, "exit") == 0)
			break;

		i = 0;
		av[i] = strtok(buf, " "); /*write func _strtok*/
                while (av[i] && i <= ARG_MAX)
                        av[++i] = strtok(NULL, " ");
                av[i] = NULL;

		path = env_path(buf);
		if (path == '\0' || path == NULL)
		{
			free(buf);
			break;
		}
		cmd = buf;

		fullcmd = strcat(path, "/");
		fullcmd = strcat(fullcmd, cmd);

		pid = fork();
		if (pid == 0)
		{
			execve(fullcmd, av, environ);
			exit(0);
		} else
		{
			free(buf);
			buf = NULL;
			free(path);
			path = NULL;
			wait(NULL);
		}
	}
	return (0);
}
