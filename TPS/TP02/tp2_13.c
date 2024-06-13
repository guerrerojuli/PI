#include <stdio.h>
#include "getnum.h"

int main(void){
  int num1 = getint("Primer numero: "), num2 = getint("Segundo numero: ");
  printf("%s\n", num1%num2 ? "No es multiplo" : "Es multiplo");
  return 0;
}
