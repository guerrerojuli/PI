#include <stdio.h>

int main(void){
  char c1 = getchar(), c2 = getchar();
  c1 == c2 ? printf("Son iguales\n") : printf("%c es mayor\n", c1 > c2 ? c1 : c2);
  return 0;
}
