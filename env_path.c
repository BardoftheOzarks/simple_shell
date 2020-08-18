
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>



int main (int ac, char** av, char **env)
{
    int j = 0;
    char *path;
    const char de[2] = "=";
    const char ds[2] = ":";
    char *dir;
    DIR *dp;
    struct dirent *entry;
    char *cmd = "ls";

    (void)ac;
    (void)av;

/** 
    int i = 0; 
    char **dir;


    DIR *dp;
    struct dirent *entry;
    char *trial = "/bin/ls";
    #include "simple_shell.h"
    cmd = "/ls";
*/

while (env[j] != NULL)
{
    if (strncmp("PATH", env[j], 3) == 0)
    {
        path = env[j];
        
        dir = strtok(path, de);
        printf("%s\n", dir);
        /**
        dir = malloc(sizeof(char *) * 10);
        *dir = strtok(path, "=");
        */
       
     while (dir != NULL)
        {
            dir = strtok(NULL, ds);
            printf("%s\n", dir);
                           
            dp = opendir(dir);
            while ((entry = readdir(dp)) != NULL)
            {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                    continue;
                if (strcmp(cmd, entry->d_name) == 0)
                    {
                        return(printf("%s", "FOUND"));
                    }
                    continue;
            }
            closedir(dp);
        }
        
    }
    j++;
}


/**
dir[0] = "/usr/local/sbin";
dir[1] = "/usr/local/bin";
dir[2] = "/usr/sbin";
dir[3] = "/usr/bin";
dir[4] = "/sbin";
dir[5] = "/bin";
dir[6] = "/usr/games";
dir[7] = NULL;
*/

/**
while (i < 10)
{
    printf("Hello");
    dp = opendir(dir[i]);

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        if (strcmp(cmd, entry->d_name) == 0)
        {
            return(printf("%s", "FOUND"));
        }
        continue;
    }
    i++;
    closedir(dp);

}
printf("envpath loop failure");
*/

return (0);
}





/**
 char *env_path(char *cmd, char **env)





 */