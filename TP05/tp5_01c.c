#include <stdio.h>

char letra;
void segundo(void);

int main(void) {
  printf("Ingrese un carácter : ");
  letra = getchar();
  segundo();
  printf(" letra es : %c\n", letra);
  return 0;
}

void segundo(void) {
  //char letra;
  letra = 'X';
  return;
}
	
// Al llamarse local pero dentro de la funcion estar redefiniendo "a" no se está
// sobreescribiendo la variable global
