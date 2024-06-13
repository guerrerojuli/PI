#include <stdio.h>
#include "getnum.h"

int main(void){
  int num1 = getint("Primer numero: "), num2 = getint("Segundo numero: ");
  printf("Promedio: %g\n", (double) (num1 + num2)/2);
  printf("Suma: %d\n", num1 + num2);
  num1 == num2 ? printf("Son iguales\n") : printf("El mayor es: %d\n", num1 > num2 ? num1 : num2);
  return 0;
}
