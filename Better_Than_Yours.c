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





int main(void)
{
    int status = 1;
    size_t size = 0;
    char *buf = NULL;
    char *prompt = "Sea-Shell>> ";
    char *arg[10];
    int str = 0;
    pid_t pid;
    char *fullcmd;
    char *slash = "/";
    char *path;
    char *cmd; 

while (status == 1)
{
    write(STDOUT_FILENO, prompt, 12);
    getline(&buf, &size, stdin);



    str = strlen(buf);
    buf[str - 1] = '\0';
    
    
    path = env_path(buf);
    if (path == '\0' || path == NULL)
    {
        free(buf);
        break;
    }
    cmd = buf;
          
    fullcmd = strcat(path, slash);
    fullcmd = strcat(fullcmd, cmd);
    
    pid = fork();
    if (pid == 0)
    {
        arg[0] = "Hello";
        arg[1] = '\0';
        execve (fullcmd, arg, environ);
        exit(0);
    }
    
    else
    {
        free(buf);
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
    continue;
}
return (0);
}
