#include <stdio.h>
#include "getnum.h"

int main(void){
  int aux, nDigitos = 0, num = getint("Ingrese el numero: ");
  aux = num;
  if(aux < 0)
    aux *= -1;

  // Contar la cantidad de digitos
  for(int n = aux; n !=0; n /= 10)
    nDigitos++;

  while(aux != 0){
    //base = 10^nDigitos
    int top, bottom, base = 1;
    for(int e = 1; e < nDigitos; e++)
      base *= 10;

    if(aux/base != aux%10){
      printf("El numero %d no es capicua\n", num);
      return 0;
    }

    aux -= (aux/base)*base;  //elimino el primer digito
    aux /= 10;  //elimino el ultimo digito 
    nDigitos -= 2;
  }
  
  printf("El numero %d es capicua\n", num);
  return 0;
}
