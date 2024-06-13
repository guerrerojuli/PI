#include <stdio.h>
#include "getnum.h"

int main(void){
  float num = getfloat("Velocidad en m/s: ");
  printf("Velocidad en km/h: %g\n", num * 3.6);
  return 0;
}
