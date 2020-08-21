#include "simple_shell.h"

/**
 * print_tokens - it prints tokens
 * @t: an array of strings
 */
void print_tokens(char **t)
{
	int i = 0;

	while (t[i] != NULL)
		printf("%s\n", t[i++]);
}
