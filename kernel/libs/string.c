#include "string.h"

int strlen(char const *str)
{
  int len = 0;
  while (str[len] != '\0')
  {
    len++;
  }
  return len;
}