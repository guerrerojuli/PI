#include <stdio.h>

int main(void){
  int c1 = getchar(), c2 = getchar();
  if (c1 != c2)
    (c1 > c2) ? 
      printf("El caracter \'%c\' es mayor que el caracter \'%c\'\n", c1, c2) : 
      printf("El caracter \'%c\' es mayor que el caracter \'%c\'\n", c2, c1); 
  else
    puts("Son iguales\n");
  return 0;
}
