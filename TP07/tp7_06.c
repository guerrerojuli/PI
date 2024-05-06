#include "../getnum.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 5

void generaAleatorio(int incognita[]) {
  char numeros[10];
  for (int i = 0; i < 10; i++)
    numeros[i] = i;
  for (int i = 0; i < X; i++) {
    int r = rand()%10;
    int aux = numeros[r];
    numeros[r] = numeros[i];
    numeros[i] = aux;
  }
  for (int i = 0; i < X; i++)
    incognita[i] = numeros[i];
}

int elegirNivel() { return (rand() % 10) + 1; }

void leerNumero(int numero[]) {
  int num;
  char msg[100] = "";
  sprintf(msg, "Inserte un numero positivo de %d digitos no repetidos: ", X);
  char repetido, negativo;
  do {
    repetido = negativo = 0;
    char apariciones[10] = {0};
    num = getint(msg);
    if (num < 0)
      negativo = 1;
    if (!negativo)
      for (int i = 0; i < X; i++) {
        if (apariciones[num % 10]++)
          repetido = 1;
        numero[X-i-1] = num % 10;
        num /= 10;
      }
  } while (num || repetido || negativo);
}

int cantidadBien(int incognita[], int numero[]) {
  char bien = 0;
  for (int i = 0; i < X; i++)
    if (numero[i] == incognita[i])
      bien++;
  return bien;
}

int cantidadRegular(int incognita[], int numero[]) {
  char regular = 0;
  for (int i = 0; i < X; i++)
    for (int j = 0; j < X; j++)
      if (numero[i] == incognita[j] && i != j)
        regular++;
  return regular;
}

int coincideNumero(int incognita[], int numero[]) {
  char bien = cantidadBien(incognita, numero),
       regular = cantidadRegular(incognita, numero);
  printf("%d BIEN, %d REGULAR\n", bien, regular);
  return (bien == X);
}

void mastermind() {
  srand(time(NULL));
  int incognita[X], numero[X];
  int nivel;
  generaAleatorio(incognita);
  nivel = elegirNivel();
  for (int i = 0; i < nivel; i++) {
    leerNumero(numero);
    if (coincideNumero(incognita, numero)) {
      printf("Has adiviando el numero, felicidades!\n");
      return;
    }
  }
  printf("Lo siento, el numero es ");
  for (int i = 0; i < X; i++)
    printf("%d", incognita[i]);
  putchar('\n');
}

int main(void) {
  mastermind();
  return 0;
}
