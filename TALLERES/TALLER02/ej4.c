#include <stdio.h>

/*
int main(void){
  int c, suma;
  char enDecimal = 0; //flag para saber si esta en la parte decimal
  while((c=getchar()) != '\n'){
    if (enDecimal)
      suma += c - '0';
    if (c == '.' || c == ',') enDecimal = 1;
  }
  printf("La suma es %d\n", suma); 
  return 0;
}
*/

int main(void){
  int c, suma;
  while((c=getchar()) != '.')
    if(c == '\n') return 0;
  while((c=getchar()) != '\n')
    if('0'<=c && c<'9') suma += c - '0';
  printf("La suma es %d\n", suma); 
  return 0;
}
