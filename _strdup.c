#include "cshell.h"
/**
 * _strdup - duplicates a string
 * @str: a string
 * Return: pointer to new array
 */

char *_strdup(char *str)
{
	char *dup;
	int counter = 0;

	if (str == NULL)
		return (NULL);
	while (str[counter] != '\0')
		counter++;
	dup = malloc(sizeof(char) * counter + 1);
	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	for (counter = 0; str[counter] != '\0'; counter++)
		dup[counter] = str[counter];
	dup[counter] = '\0';
	return (dup);
}
