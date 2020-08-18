#include "cshell.h"
/**
 * print - prints the input string as the command prompt
 * @str: input string
 * Return: length
 */
int print(char *str)
{
	unsigned int size = 0;

	while (str[size])
		size++;
	write(STDOUT_FILENO, str, size);
	return (size);
}
