#include "cshell.h"
/**
* main - it's a shell. Live with it.
* Return: always 0
*/
int main(void)
{
	int status, len, i;
	size_t size = 0;
	char *buf, *buffer, *fullcmd, *path;
	char **av = malloc(sizeof(char *) * ARG_MAX);
	pid_t pid;


	while (1)
	{
		print("Sea-Shell$ ");
		status = getline(&buf, &size, stdin);/*write _getline*/
		if (status == -1 || _strcmp(buf, "exit") == 0)
			break;
		len = _strlen(buf);
		buf[len - 1] = '\0';
		buffer = malloc(sizeof(char) * len);
		buffer = buf;
		av[0] = strtok(buffer, " ");
		for (i = 1; i < ARG_MAX; i++)
			av[i] = strtok(NULL, " ");
		av[i] = NULL;
		path = env_path(av[0]);
		fullcmd = strcat(path, "/"); /*write _strcat*/
		fullcmd = strcat(fullcmd, av[0]);
		pid = fork();
		if (pid == 0)
		{
			av[0] = "Fuck this";
			av[1] = NULL;
			execve(fullcmd, av, environ);
			exit(0);
		} else
			wait(NULL);
	}
	return (0);
}
