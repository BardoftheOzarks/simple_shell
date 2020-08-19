#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>



char *env_path(char *cmd)
{
    int j = 0;
    char *path;
    const char de[2] = "=";
    const char ds[2] = ":";
    char *dir;
    DIR *dp;
    struct dirent *entry;



while (environ[j] != NULL)
{
    if (strncmp("PATH", environ[j], 3) == 0)
    {
        path = environ[j];
        printf("%s\n", path);
        dir = strtok(path, de);
        
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
                        return(dir);
                    }
                    continue;
            }
            closedir(dp);
        }
        
    }
    j++;
}
return (0);
}


/** 
    int i = 0; 
    char **dir;


    DIR *dp;
    struct dirent *entry;
    char *trial = "/bin/ls";
    #include "simple_shell.h"
    cmd = "/ls";
*/
/**
dir = malloc(sizeof(char *) * 10);
*dir = strtok(path, "=");
*/
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
char *env_path(char *cmd, char **env)
*/



char **buffsplitter(char *str)
{
    const  char delim[2] = " ";
    char **token;
    char *temp;



    temp = strtok(str, delim);
    
    token[0] = strdup(temp);
    printf("%s", token[0]);
    temp = strtok(NULL, delim);
    token[1] = strdup(temp);


token[2] = '\0';
return(token);
}


/**
     while(token[t] != NULL)
    {
        temp = strtok(NULL, delim);
        token[t] = strdup(temp);
        t++;
    }
*/