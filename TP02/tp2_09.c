#include <stdio.h>
#include "getnum.h"

int main(void){
  int num = getint("Valor entero: ");
  printf("Valor /2: %d\n", num>>1);
  return 0;
}
