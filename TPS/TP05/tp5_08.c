#include <assert.h>
#include <math.h>
#include <stdio.h>

#define EPSILON 0.000000001

double redondeo(double numero, unsigned int cifras) {
  long base = pow(10, cifras);
  double cortado;
  cortado = numero * base;
  cortado = (cortado - (int) cortado >= 0.5) ? ceil(cortado) : floor(cortado);
  return cortado / base;
}

/**
 * Funcion auxiliar para comparar si dos doubles son "iguales"
 */
int equals(double x, double y) { return fabs(x - y) < EPSILON; }

int main(void) {

  double x = 1.0;

  for (int i = 0; i < 10; i++)
    assert(redondeo(x, i) == x);

  x = 1.11111;
  assert(equals(redondeo(x, 0), 1.0));
  assert(equals(redondeo(x, 1), 1.1));
  assert(equals(redondeo(x, 2), 1.11));
  assert(equals(redondeo(x, 3), 1.111));
  assert(equals(redondeo(x, 4), 1.1111));
  assert(equals(redondeo(x, 5), 1.11111));
  assert(equals(redondeo(x, 6), 1.11111));
  assert(equals(redondeo(x, 7), 1.11111));

  x = 1.15555;
  assert(equals(redondeo(x, 0), 1.0));
  assert(equals(redondeo(x, 1), 1.2));
  assert(equals(redondeo(x, 2), 1.16));
  assert(equals(redondeo(x, 3), 1.156));

  puts("OK !");
  return 0;
}
