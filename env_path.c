#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>


char env_path(char *cmd, char **env)
{
    int i = 0, j = 0;
    char *dir[100];
    char *path;
    char *;

    DIR *


while (env[j] != '\0')
{
    if (strncmp ("PATH", env[j], 3) == 0)
    {
        path = env[j];

        dir[i] = strtok (path, ':');

     while (dir[i] != NULL)
        {
            i++;
            dir[i] = strtok (NULL, ':');
        }
    
    }
    j++;
}
i = 0;

while (())

}