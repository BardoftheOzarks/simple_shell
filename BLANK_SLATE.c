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

int main()
{
    int status = 1;
    size_t size = 0;
    char *buf = NULL;
    char *prompt = "Sea-Shell>> ";
    char *arg[10];
    char *envp[] = {(char *) "PATH=/bin", 0};
    int str = 0;
    pid_t pid;


while (status == 1)
{
    write(STDOUT_FILENO, prompt, 12);
    getline(&buf, &size, stdin);
    str = strlen(buf);
    buf[str - 1] = '\0';
    printf("%s", buf);
 
pid = fork();

if (pid == 0)
{
    arg[0] = "/bin";
    execve (buf, arg, envp);
}
else
{
    wait (NULL);
}



if (strcmp (buf, "exit") == 0 )
{
    printf("%s", "FUCK");
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
    char *envp[] = {(char *) "PATH=/bin", 0};
    char *arg[10];
*else
{
    arg[0] = '\0';
    execve (buf, arg, envp);
}

if (strcmp (buf, "/bin/ls") == 0)
{
    printf("%s", "exec");
    execve (test, arg, envp);
}  
   write(STDOUT_FILENO, buf, 1024);
*   printf("%s", buf);
*   printf("$>");
*/
    continue;
}
return (0);
}
