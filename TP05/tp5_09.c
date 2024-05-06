#include <math.h>
#include <stdio.h>
#define FUNCION(x) sin(x)
// #define FUNCION(x)  cos(x)
#define MAX 4
#define MIN -4
#define EPSILON 0.0000001

int main(void) {
  double valorAnterior = 0, anteriorRaiz = 0;
  for (double i = MIN; i < MAX; i += 0.001) {
    if ((fabs(FUNCION(i)) < EPSILON || FUNCION(i) * valorAnterior < 0) &&  !anteriorRaiz) {
      printf("El valor %.5f es raiz\n", i);
      anteriorRaiz = 1;
    } else
      anteriorRaiz = 0;
    valorAnterior = FUNCION(i);
  }
  return 0;
}
