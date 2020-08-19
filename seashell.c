#include "cshell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * main - function
 * Return: zero
 */
int main(void)
{
	int status;
	size_t size;
	char *buf;
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
			arg[3] = NULL;
			execve(arg[0], arg, envp);
			perror("execve");
			exit(errno);
		}
		else
			wait(NULL);
	}
	free(buf);
	return (0);
}
