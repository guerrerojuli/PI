#include <stdio.h>
#define MAXIMO2(max, x, y)  (max = (x) > (y) ? (x) : (y))
#define MAXIMO3(max, x, y, z) ((x) > (y) ? MAXIMO2((max), (x), (y)) : MAXIMO2((max), (y), (z)))

int main(void){
  int max, x = 0, y = 1, z = 2;
  MAXIMO2(max, x, y);
  printf("El maximo es %d\n", max);
  MAXIMO3(max, x, y, z);
  printf("El maximo es %d\n", max);
  return 0;
}
