#include "simple_shell.h"
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


















int main(int ac, char** av, char **env)
{
    int status = 1;
    size_t size = 0;
    char *buf = NULL;
    char *prompt = "Sea-Shell>> ";
    char *arg[10];
    int str = 0;
    pid_t pid;
    char *path;
    char *fullcmd;
    (void)ac;
    (void)av;
    

while (status == 1)
{
    write(STDOUT_FILENO, prompt, 12);
    getline(&buf, &size, stdin);
    str = strlen(buf);
    buf[str - 1] = '\0';    

printf("before fork");
pid = fork();
printf("after fork");

if (pid == 0)
{
printf("child fork");
    path = env_path(buf, env);
    fullcmd = strcat(path, buf);
    arg[0] = path; 
    arg[1] = '\0';
    printf("%s", fullcmd);
    execve (fullcmd, arg, env);
    exit(0);
}
else
{
    wait (NULL);
}



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











/**    
*
*
*   if (fork () != 0)
*    {
 *   wait(NULL);
  *  }
*
  printf("%s", buf);
  
      printf("%s", "FUCK");
    char *envp[] = {(char *) "PATH=/bin", 0};
    char *arg[10];



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
    continue;
}
return (0);
}
