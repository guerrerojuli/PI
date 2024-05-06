#include <assert.h>
#include <stdio.h>

long factoreo(int factores[]) {
  if (factores[0] == -1)
    return 0;

  int i, j;
  long resultado = factores[0];
  for (i = j = 1; factores[i] != -1; i++) {
    resultado *= factores[i];
    if (factores[i] != factores[i - 1])
      factores[j++] = factores[i];
  }
  factores[j] = -1;
  return resultado;
}

int main(void) {
  int factores[] = {2, 2, 2, 3, 3, 4, 5, 5, 6, 6, 6, 6, 7, -1};
  long resultado = factoreo(factores);
  assert(resultado == 65318400);
  assert(factores[0] == 2);
  assert(factores[1] == 3);
  assert(factores[2] == 4);
  assert(factores[3] == 5);
  assert(factores[4] == 6);
  assert(factores[5] == 7);
  assert(factores[6] == -1);
  int factores2[] = {2, -1};
  resultado = factoreo(factores2);
  assert(resultado == 2);

  assert(factores2[0] == 2);
  assert(factores2[1] == -1);
  int factores3[] = {11, 11, 13, -1};
  resultado = factoreo(factores3);
  assert(resultado == 1573); // 11 * 11 * 13
  assert(factores3[0] == 11);
  assert(factores3[1] == 13);
  assert(factores3[2] == -1);
  int factores4[] = {-1};
  resultado = factoreo(factores4);
  assert(resultado == 0);
  assert(factores4[0] == -1);
  int factores5[] = {1, -1};
  resultado = factoreo(factores5);
  assert(resultado == 1);
  assert(factores5[0] == 1);
  assert(factores5[1] == -1);
  puts("OK!");
  return 0;
}
