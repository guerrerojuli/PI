#include <assert.h>
#include <stdio.h>

int suma(int numero) {
  if (numero < 0)
    numero *= -1;
  return (numero) ? (numero % 10) + suma(numero / 10) : 0;
}

int main(void) {

  assert(suma(0) == 0);
  assert(suma(1) == 1);
  assert(suma(12) == 3);
  assert(suma(100000) == 1);
  assert(suma(123456) == 21);
  assert(suma(-123456) == 21);
  assert(suma(999999) == 54);

  puts("OK!");
  return 0;
}
