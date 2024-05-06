#include "../getnum.h"
#include <stdio.h>
#include <stdlib.h>

int *cargarNumeros(int *dim) {
  int dimAux = 10;
  int *numeros = malloc(dimAux * sizeof(*numeros));
  char repetido = 0;
  *dim = 0;
  while (!repetido) {
    int numAux = getint("Inserte un numero entero: ");
    for (int i = 0; i < dimAux && !repetido; i++)
      repetido = numeros[i] == numAux;
    if (!repetido)
      numeros[(*dim)++] = numAux;
    if (*dim == dimAux) {
      dimAux *= 2;
      numeros = realloc(numeros, dimAux * sizeof(*numeros));
    }
  }
  numeros = realloc(numeros, *dim * sizeof(*numeros));
  return numeros;
}

int main(void) {
  int dim;
  int *arr;
  arr = cargarNumeros(&dim);

  for (int i = 0; i < dim; i++)
    printf("%d ", arr[i]);
  putchar('\n');
  free(arr);
  return 0;
}
