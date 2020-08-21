#include "simple_shell.h"

/**
* free_grid - free malloc
* description: free grid
* @grid: int
* @height: int
* Return: value or error
*/

void free_grid(char **av)
{
        int tall;
    printf("x = %d\n", x);
    if (av == NULL)
        return;
    for (tall = x; tall >= 0; tall--)
    {
        printf("tall = %d, av[tall] = %s \n", tall, av[tall]);
        free(av[tall]);
    }
    free(av[0]);
    return;
}


/**
    free(av[5]);
    free(av[4]);
    free(av[3]);
    free(av[2]);
    free(av[1]);
*/