#include "simple_shell.h"

/**
* *_calloc - make grid
* description: make array using malloc
* @nmemb: int
* @size: int
* Return: value or error
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int num;
char *grid;

if (nmemb == 0 || size == 0)
return (NULL);

grid = malloc(nmemb * size);
if (grid == NULL)
{
free(grid);
return (NULL);
}
for (num = 0; num < (nmemb * size); num++)
grid[num] = 0;
return ((void *)grid);
}