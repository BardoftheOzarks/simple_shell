#include "simple_shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
* main - It's a shell
* Return: Nothing, it's an empty shell
*/

char **buf_splitter(char *buf)
{
    char **av = _calloc(ARG_MAX, sizeof(char *));
    char *cmd, *free_ptr;
    int i; 

        if (buf[0] == '/' || buf[0] == ' ' || buf[0] == '.')
		{
            i = 0;
        
            av[i] = strtok(buf, " "); /*write func _strtok*/
		    while (av[i] && i <= ARG_MAX)
            {
                av[++i] = strtok(NULL, " ");
            }
		    av[i] = '\0';
            x = i;
            return(av);
		}
		
        i = 0;
		
        av[i] = strtok(buf, " "); /*write func _strtok*/
        cmd = av[0];
		while (av[i] && i <= ARG_MAX)
        {
            av[++i] = strtok(NULL, " ");
            
        }
		av[i] = '\0';
        
		av[0] = env_path(av[0]);
        
		if (av[0] == '\0' || av[0] == NULL)
		{	
            free_grid(av);
			EXIT_FAILURE; 
        }
        
        free_ptr = av[0];

		av[0] = _strcat(av[0], "/");
        free(free_ptr);
        free_ptr = av[0];
		av[0] = _strcat(av[0], cmd);
        free(free_ptr);
        x = i;
        return(av);
}

/**
 av[i] = _calloc(j, sizeof(char));
 j = _strlen(temp);
 */