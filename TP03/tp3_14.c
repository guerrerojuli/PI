#include <stdio.h>

int main(void){
  int c, menor, deltaMenor = -1, deltaAux;
  while((c = getchar()) == ' ' || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')){
    if (c != ' '){
      deltaAux = (c <= 'z') ? c - 'a' :  c - 'A';

      if(deltaMenor >  deltaAux || deltaMenor == -1){
        deltaMenor = deltaAux;
        menor = c;
      }
    }
  }
  printf("%c\n", menor);
  return 0;
}
