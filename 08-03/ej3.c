#include <stdio.h>

int main(void){
  int n, rta;
  n = 9;
  rta = (n>15 && n>=0) ? n : ((n>9) ? n-10+'A' : n+'0');
  printf("La respuesta es: %c\n", rta);
  return 0;
}
