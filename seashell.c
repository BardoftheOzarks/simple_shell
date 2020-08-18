#include "cshell.h"
int main(void)
{
	char **av = malloc(sizeof(char *) * (ARG_MAX + 1));
	char *buffer;
	int test, i = 0;
	pid_t pid;
	size_t size;

	if (!av)
		perror("malloc");
	while (1)
	{
		print("C-Shell$ ");
		test = getline(&buffer, &size, stdin);/*write func _getline*/
		if (test == -1 || _strcmp(buffer, "exit") == 0)
			break;
		size = _strlen(buffer);
		buffer[size - 1] = '\0';
		av[i] = strtok(buffer, " "); /*write func _strtok*/
		while (av[i] && i <= ARG_MAX)
			av[++i] = strtok(NULL, " ");
		av[i] = NULL;
		pid = fork();
		if (pid == 0)/*Child process*/
		{
			if (execve(buffer, av, environ) == -1)
				perror("execve");
			exit(errno);
		} else if (pid < 0)/*Error forking*/
			perror("fork");
		else
			wait(NULL);
		free(buffer);
		free(av);
	}
	free(buffer);
	free(av);
	return (0);
}
