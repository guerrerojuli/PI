#include "getnum.h"
#include <stdio.h>

float f1(float);
float f2(float);
float funAuxiliar(float);

int main(void) {
  float x, y, z;
  x = getfloat("Ingrese un número real :");
  putchar('\n');

  y = f1(x);
  z = f2(x);

  printf("El doble absoluto de %g es %g\n", x, y);
  printf("El triple absoluto de %g es %g\n", x, z);
  return 0;
}

float f1(float x) { return 2 * funAuxiliar(x); }
