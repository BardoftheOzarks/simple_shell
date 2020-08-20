#include "simple_shell.h"



char *_strcat(char *first, char *second)
{

  _strcpy(first + _strlen(first), second);

  return(first);
}
