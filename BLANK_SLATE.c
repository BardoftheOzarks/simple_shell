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
    char *prompt = "$ ";

while (status == 1)
{
    write(STDOUT_FILENO, prompt, 2);
    getline(&buf, &size, stdin);
    if (feof(stdin))
    {
        return (0);
    }
    write(STDOUT_FILENO, buf, 1024);

/**    
*        printf("%s", buf);
*   printf("$>");
*/
    continue;
}
return (0);
}
