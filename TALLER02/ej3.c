#include <stdio.h>
#include "getnum.h"

int main(void){
  float num = getfloat("Escribe tu float: ");
  int suma = 0;
  if(num < 0) num *= -1;
  while(num != 0){
    num -= ((int) num); //recorto la parte entera
    num *= 10;
    suma += ((int) num);
  }
  printf("La suma es %d\n", suma);
  return 0;
}
