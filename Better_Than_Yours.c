#include "cshell.h"
/**
* main - it's a shell. Live with it.
* Return: always 0
*/
int main(void)
{
	int status, len, i;
	size_t size = 50;
	char *buf = malloc(sizeof(char) * 150), *fullcmd, *path;
	char **av = malloc(sizeof(char *) * 50);
	pid_t pid;


	while (1)
	{
		print("Sea-Shell$ ");
		status = getline(&buf, &size, stdin);/*write _getline*/
		if (status == -1 || _strcmp(buf, "exit") == 0)
			break;
		len = _strlen(buf);
		buf[len - 1] = '\0';
		av[0] = _strdup(strtok(buf, " "));
		for (i = 1; i < 50; i++)
			av[i] = _strdup(strtok(NULL, " "));
		av[i] = NULL;
		path = env_path(av[0]);
		fullcmd = malloc(sizeof(char) * 100);
		fullcmd = strcat(fullcmd, path); /*write _strcat*/
		fullcmd = strcat(fullcmd, "/");
		fullcmd = strcat(fullcmd, av[0]);
		pid = fork();
		if (pid == 0)
		{
			execve(fullcmd, av, environ);
			exit(0);
		} else
			wait(NULL);
	}
	return (0);
}
