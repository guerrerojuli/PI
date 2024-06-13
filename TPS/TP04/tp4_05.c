#include <stdio.h>
#define MAXIMO2(max, x, y)  (max = (x) > (y) ? (x) : (y))

int main(void){
  int max, x = 0, y = 1;
  MAXIMO2(max, x, y);
  printf("El maximo es %d\n", max);
  return 0;
}
