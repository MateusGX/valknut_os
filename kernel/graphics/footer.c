#include "../screen/screen.h"
#include "footer.h"
#include "../io/io.h"
#include "../libs/string.h"

void setfooter(char* text, unsigned char style){
  _print(text, style, 2 * ((23 * 80) + 2));
}