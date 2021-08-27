#include "kernel.h"

void init(){
  init_screen();
  sleep(0x4FFFFFFF);
  _clear();
}

void main()
{
  //setfooter("[ENTER] Login in system", 0x07);
}