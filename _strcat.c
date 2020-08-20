#include "simple_shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * free(dest);
 * Return: dest string
 */
char *_strcat(char *dest, char *src)
{
	char *temp;
	int n, i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	j = _strlen(src);

	temp = malloc(sizeof(char) * (i + j) + 1);
		
	for (n = 0; dest[n] != '\0'; n++)
		temp[n] = dest[n];
	
	for (j = 0; src[j] != '\0'; n++, j++)
		temp[n] = src[j];
	
	temp[n] = '\0';
	
	return (temp);

}
