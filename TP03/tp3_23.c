#include <stdio.h>
#include "getnum.h"

int main(void){
  int n,c;
  /* al salir del ciclo n debe ser un número par mayor que cero */
  do
    n = getint("");
  while(!(n > 0 && n%2 == 0));

  /* este ciclo debe incluir la lectura de caracteres y debe ejecutarse  
   * mientras no sea fin de archivo y los caracteres sean  dígitos o minúsculas
   */
  while ((c=getchar()) != EOF && (('0' <= c && c <= '9') || ('a' <= c && c <= 'z')))
    putchar(c);

  return 0;
}
