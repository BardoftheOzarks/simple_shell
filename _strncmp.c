#include "cshell.h"
/**
 * _strncmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: 1 if match, -1 if not
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (s1[i] && s2[i] && i <= n)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
