#include <stdio.h>
#include "getnum.h"

int main(void){
  int num = getint("Numero: ");
  int factorial = 1;
  for (int i = 2; i <= num; i++){
    factorial *= i;
    if(factorial < 0){
      printf("El numero tiene que ser menor a %d\n", i);
      i=num;
    }
  }
  if(factorial > 0)
    printf("%d\n", factorial); 
  return 0;
}
