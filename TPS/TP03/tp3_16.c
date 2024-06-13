#include <stdio.h>
#include "getnum.h"

int main(void){
  int binario, decimal = getint("Introduzca su numero decimal: ");

  if(decimal < 0){
    puts("El numero ingresado no es positivo");
    return 0;
  }

  for(int exponente = 0; decimal != 0; exponente++){
    int aux = 1;
    for(int i = 0; i < exponente; i++)
      aux *= 10;
    binario += (decimal%2)*aux;
    decimal /= 2; 
  }

  printf("%d\n", binario);
  return 0;
}
  
