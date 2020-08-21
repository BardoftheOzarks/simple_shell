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
	int status, len;
	size_t size = 0;
	char *buf = NULL, **av;
	pid_t pid;

	while (1)
	{
		if (isatty(0))
			print("$ ");
		status = getline(&buf, &size, stdin);
		if (status == -1 || _strncmp(buf, "exit", 4) == 0)
			break;
		len = _strlen(buf);
		buf[len - 1] = '\0';
		av = buf_splitter(buf);
		pid = fork();
		if (pid == 0)
		{
			execve(av[0], av, environ);
			exit(0);
		}
		else
			wait(NULL);
		free(buf);
		free_grid(&av);
	}
	return (0);
}
