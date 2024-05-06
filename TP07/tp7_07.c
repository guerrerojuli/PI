#include "../getnum.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generaAleatorio(int dim) {
  char apariciones[10] = {0};
  int *incognita = malloc(dim * sizeof(*incognita));
  int r;
  for (int i = 0; i < dim; i++) {
    do {
      r = rand() % 10;
    } while (apariciones[r]);
    apariciones[r]++;
    incognita[i] = r;
  }
  return incognita;
}

int elegirNivel() { return (rand() % 10) + 1; }

int elegirTamano() {
  int x;
  do
    x = getint("Elije el tamaño del numero (hasta 10): ");
  while (x < 1 || x > 10);
  return x;
}

int *leerNumero(int *numero, int dim) {
  int num;
  numero = realloc(numero, dim * sizeof(*numero));
  char msg[100] = "";
  sprintf(msg, "Inserte un numero positivo de %d digitos no repetidos: ", dim);
  char repetido, negativo;
  do {
    repetido = negativo = 0;
    char apariciones[10] = {0};
    num = getint(msg);
    if (num < 0)
      negativo = 1;
    if (!negativo)
      for (int i = 0; i < dim; i++) {
        if (apariciones[num % 10]++)
          repetido = 1;
        numero[dim - i - 1] = num % 10;
        num /= 10;
      }
  } while (num || repetido || negativo);
  return numero;
}

int cantidadBien(int incognita[], int numero[], int dim) {
  char bien = 0;
  for (int i = 0; i < dim; i++)
    if (numero[i] == incognita[i])
      bien++;
  return bien;
}

int cantidadRegular(int incognita[], int numero[], int dim) {
  char regular = 0;
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++)
      if (numero[i] == incognita[j] && i != j)
        regular++;
  return regular;
}

int coincideNumero(int incognita[], int numero[], int dim) {
  char bien = cantidadBien(incognita, numero, dim),
       regular = cantidadRegular(incognita, numero, dim);
  printf("%d BIEN, %d REGULAR\n", bien, regular);
  return (bien == dim);
}

void mastermind() {
  srand(time(NULL));
  int dim = elegirTamano();
  int *incognita = generaAleatorio(dim), *numero = NULL;
  int nivel = elegirNivel();
  for (int i = 0; i < nivel; i++) {
    numero = leerNumero(numero, dim);
    if (coincideNumero(incognita, numero, dim)) {
      printf("Has adiviando el numero, felicidades!\n");
      return;
    }
  }
  printf("Lo siento, el numero es ");
  for (int i = 0; i < dim; i++)
    printf("%d", incognita[i]);
  putchar('\n');
  free(incognita);
  free(numero);
}

int main(void) {
  mastermind();
  return 0;
}
