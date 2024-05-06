#include <stdio.h>
#include "getnum.h"

int main(void){
  int nCinco = 0, entero = getint("Inserte un numero entero: ");
  while(entero != 0){
    if(entero%10 == 5)
      nCinco++;
    entero /= 10;
  }
  printf("Tiene %d cincos\n", nCinco);


  int c;
  nCinco =0;
  printf("Ingresa tu numero real: ");
  while((c=getchar()) != '\n' ){
    if(!(c == '.' || ('0' <= c && c <= '9'))){
        puts("El valor ingresado no es un numero real");
        return 1;
    }
    if(c == '5')
      nCinco++;
  }
  printf("Tiene %d cincos\n", nCinco);

  return 0;
}
