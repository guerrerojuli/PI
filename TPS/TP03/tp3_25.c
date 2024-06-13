#include <stdio.h>
#include "getnum.h"

int main(void){
  int cant1, num = getint("Inserte un numero entero: "), numCopia = num;
  if(num < 0){
    puts("El numero debe ser positivo");
    return 1;
  }
  while(num != 0){
    cant1 += num%2;
    num /= 2;
  }
  printf("La expresion binaria de %d tiene %d unos\n", numCopia, cant1);
  return 0;
}
    
