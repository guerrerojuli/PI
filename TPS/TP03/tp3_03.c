#include <stdio.h>
#include "getnum.h"

int main(void){
  int totalVendido, porcentaje;
  do
    totalVendido = getint("Ingrese el total vendido: ");
  while (totalVendido < 0);
  if (totalVendido <= 1000)
    porcentaje = 0;
  else if (totalVendido <= 2000)
    porcentaje = 5;
  else if (totalVendido <= 4000)
    porcentaje = 7;
  else
    porcentaje = 9;
  printf("%g\n", 300 + totalVendido * (double) porcentaje/100);

  return 0;
}
