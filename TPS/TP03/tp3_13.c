#include <stdio.h>
#include "getnum.h"

int main(void){
  int lado;
  do
    lado = getint("Longitud del lado: ");
  while(lado < 0);

  for(int i = 0; i < lado; i++){
    for(int j = 0; j < lado; j++)
      putchar('*');
    putchar('\n');
  }

  putchar('\n');

  for(int i = 0; i < lado*lado; i++)
    printf("%s", (i != 0 && i%lado == 0) ? "\n*" : "*");

  putchar('\n');

  return 0;
}
