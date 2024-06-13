#include <stdio.h>
#include "getnum.h"

int main(void){
  int s = getint("Segundos: ");
  printf("%02d:%02d:%02d\n", s/(60*60), (s/60)%60, s%60);
  return 0;
}

