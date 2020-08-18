#include "cshell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * main - function
 * description: print
 * @ac: lists
 * @av: stuff
 * Return: size
 */
int main(void)
{
	int status = 1;
	size_t size = 0;
	char *buf = NULL;
	char *arg[10];
	char *envp[] = {(char *) "PATH=/bin", 0};
	int str = 0;
	pid_t pid;

	while (1)
	{
		print("Sea-Shell$ ");
		status = getline(&buf, &size, stdin);
		if (status == -1 || _strcmp(buf, "exit") == 0)
			break;
		str = strlen(buf);
		buf[str - 1] = '\0';
		pid = fork();
		if (pid == 0)
		{
			arg[0] = "/bin/ls";
			arg[1] = "-l";
			arg[2] = "-a";
			arg[3] = '\0';
			execve (buf, arg, envp);
			perror("execve");
			exit(errno);
		}
		else
			wait (NULL);
	}
	free(buf);
	return (0);
}
