#include "simple_shell.h"

/**
* free_grid - free malloc
* description: free grid
* @grid: int
* @height: int
* Return: value or error
*/

void free_grid(char ***av)
{
        int i = 0;

    if (*av == NULL)
        return;

    while((*av)[i] != NULL)
    {
        free((*av)[i]);
        i++;
    }

    free(*av);
    return;
}


/**
    free(av[5]);
    free(av[4]);
    free(av[3]);
    free(av[2]);
    free(av[1]);
*/