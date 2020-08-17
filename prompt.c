#include "cshell.h"
int main(void)
{
	char **av, *buffer = NULL, *token;
	int test;
	pid_t pid;
	size_t size = 1024;

	while (1)
	{
		print("C-Shell$ ");
		buffer = malloc(sizeof(char) * 1024);
		test = getline(&buffer, &size, stdin);/*write func _getline*/
		if (test == -1)
			break;
		token = strtok(buffer, " "); /*write func _strtok*/
		test = 0;
		pid = fork();
		if (pid == 0)/*Child process*/
		{
			if (execve(token, &token, environ) == -1)
				perror("Error");
			exit(-1);
		} else if (pid < 0)/*Error forking*/
			perror("Error");
		else
			wait(NULL);
	}
	free(buffer);
	return (0);
}
