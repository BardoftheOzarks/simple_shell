#include "simple_shell.h"
#include <dirent.h>
#include <errno.h>
/**
 * env_path - gets the correct path
 * @cmd: argv[0]
 * Return: string with correct path
 */
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
        dir = strtok(path, de);
        
         while (dir != NULL)
        {
            dir = strtok(NULL, ds);            
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
        return(0);
    }
    j++;
}
  return(0);
}
