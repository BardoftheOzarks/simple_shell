#include "simple_shell.h"

void print_tokens(char **t)
{
    int i = 0;
    while (t[i] != NULL)
        printf("%s\n", t[i++]);

}