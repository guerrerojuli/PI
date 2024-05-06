#include "getnum.h"
#include <stdio.h>

int main(void) {
  int i, j, n = 0, suma = 0;

  while (n <= 0)
    n = getint("Ingrese cantidad de elementos:");

  for (i = 1; i <= n; i++) {
    j = getint("Ingrese valor %d:", i);
    suma += j;
  }

  printf("El resultado es : %.2f\n", suma / (float)j);
  return 0;
}
