#include <stdio.h>
#include "getnum.h"

int main(void){
  /*
  int c, suma;
  while((c=getchar()) != '\n')
    suma += c - '0';
  printf("La suma es %d\n", suma); 
  return 0;
  */

  int suma, num = getint("Escribe un numero entero: ");
  if(num < 0) num *= -1;
  while(num != 0){
    suma += num%10;
    num /= 10;
  }
  printf("La suma es %d\n", suma);
  return 0;
}
