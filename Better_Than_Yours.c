#include "cshell.h"
/**
* main - It's a shell!
* Return: It doesn't!
*/
int main(void)
{
	int status, len, i;
	size_t size = 0;
	char *buf, **av, *fullcmd, **path, *cmd;
	pid_t pid;

	while (1)
	{
		print("Sea-Shell$ ");
		status = getline(&buf, &size, stdin);
		if(status = -1 || _strcmp(buf, "exit") == 0)
			break;

		len = strlen(buf);
		buf[len - 1] = '\0';

		path = _strdup(strtok(buf, " ");

		path[0] = env_path(cmd);

		fullcmd = strcat(path[0], "/");
		fullcmd = strcat(fullcmd, av[0]);

		pid = fork();
		if (pid == 0)
		{
			arg[0] = path[0];
			arg[1] = '\0';
			execve (fullcmd, arg, environ);
			exit(0);
		} else
			wait (NULL);
		if (strcmp (buf, "exit") == 0 )
		{
			free (buf);
			return (0);
		}

		if (feof(stdin))
		{
			free (buf);
			return(0);
		}
	}
	return (0);
}









/**
char bin_func(char *txt)
{
    char *bin = "/bin/";
    char *cmd;
    int i = 0, j = 0, k = 0;

while (i != 4)
{
cmd[i] = bin[j];
i++;
j++;
}

while (text[k] != '\0')
{
    cmd[i] = txt[k];
    i++;
    k++;
}

cmd[i + 1] = '\0';

return (cmd);
}
*/
/**    
   if (fork () != 0)
    {
       wait(NULL);
    }

    211printf("%s", buf);
  
      printf("%s", "FUCK");
    char *envp[] = {(char *) "PATH=/bin", 0};
    char *arg[10];

    printf("%s", fullcmd);
    printf("%s", buf);

char *fullcmd = "/bin/ls";

*else
{
    arg[0] = '\0';
    execve (buf, arg, envp);
}
arg = strtok(buf, ' ')
if (strcmp (buf, "/bin/ls") == 0)
{
    printf("%s", "exec");
    execve (test, arg, envp);
}  
       char *envp[] = {(char *) "PATH=/bin", 0};
   
   write(STDOUT_FILENO, buf, 1024);
*   printf("%s", buf);
*   printf("$>");
*/

