#include <stdio.h>

int main(void){
  int max, a, b, c;
  a = 45;
  b = 12;
  c = 20;
  max = a>b ? (a>c ? a:c) : (b>c ? b:c);
  printf("El maximo entre %d, %d y %d es %d\n", a, b, c, max);
  return 0;
}
