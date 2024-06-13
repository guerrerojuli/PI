#include <stdio.h>
#include "getnum.h"

int main(void){
  int suma, exponente = 0, binario = getint("Introduzca su numero binario: ");

  if(binario < 0){
    puts("El numero ingresado no es binario");
    return 0;
  }

  while(binario != 0){
    int currentDigit = binario%10;
    if(currentDigit > 1){
      puts("El numero ingresado no es binario");
      return 0;
    }

    if(currentDigit){
      int aux = 1;
      for(int i = 0; i < exponente; i++) 
        aux *= 2;

      suma += aux;
    } 
    binario /= 10; 
    exponente++;
  }

  printf("%d\n", suma);
  return 0;
}
  
