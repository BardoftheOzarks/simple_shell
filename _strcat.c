#include "simple_shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: dest string
 */
char *_strcat(char *dest, char *src)
{
	int n, i = 0;

	while (dest[i] != '\0')
		i++;
	for (n = 0; src[n] != '\0'; n++, i++)
		dest[i] = src[n];
	dest[i] = '\0';
	return (dest);
}
