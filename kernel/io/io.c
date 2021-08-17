#include "io.h"
#include "../libs/string.h"
#include "../screen/screen.h"

unsigned int videoBufferPosition = 0;

void _print(char *str, unsigned char style, unsigned int startPosition)
{
  if (style == -1)
  {
    style = 0x07;
  }
  if (startPosition == -1)
  {
    startPosition = videoBufferPosition;
  }
  int strPosition = 0;
  while (str[strPosition] != '\0')
  {
    getVGA()[startPosition] = str[strPosition];
    getVGA()[startPosition + 1] = style;
    strPosition++;
    startPosition += 2;
  }
}

void _clear()
{
  while (videoBufferPosition > 0)
  {
    getVGA()[videoBufferPosition - 2] = NULL;
    getVGA()[videoBufferPosition - 1] = NULL;
    videoBufferPosition -= 2;
  }
}