#include <stdio.h>

int a, b;
void local(void);

int main(void) {
  a = 2;
  b = 3;

  local();
  printf(" a vale : %d\tb vale %d\n", a, b);
  return 0;
}

void local(void) {
  // int a;

  a = -5;
  b = 10;

  return;
}

// Al llamarse local pero dentro de la funcion estar redefiniendo "a" no se está
// sobreescribiendo la variable global
