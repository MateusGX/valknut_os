#include "sys.h"

void sleep(long long int time){
  while (1)
  {
    _nop();
    time--;
    if(time <= 0){
      break;
    }
  }
}