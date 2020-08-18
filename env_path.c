#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>


char *env_path(char *cmd, char **env)
{
    int i = 0, j = 0;
    char *dir[100];
    char *path;

    DIR *dp;
    struct dirent *entry;

printf("start");

while (env[j] != NULL)
{
    if (strncmp("PATH", env[j], 3) == 0)
    {
        path = env[j];

printf("%s", path);

        dir[i] = strtok(path, ":");

     while (dir[i] != NULL)
        {
            i++;
            dir[i] = strtok(NULL, ":");
        }
    
    }
    j++;
}
i = 0;



while (dir[i])
{
    printf("Hello, %d", i);
    dp = opendir(dir[i]);

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(cmd, entry->d_name) == 0)
        {
            return(dir[i]);
        }
    }
    i++;
    closedir(dp);
}
return (NULL);
}