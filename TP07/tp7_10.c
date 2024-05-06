#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N_PALABRAS 6
#define INICIO_VIDAS 6 // cabeza, cuerpo, piernas, brazos
#define ABC_LEN ('z' - 'a' + 1)
#define CLEAR_BUFFER while (getchar() != '\n')

char *elegirPalabra(char *palabras[], int dim) {
  return palabras[rand() % dim];
}

void imprimirUsadas(char usadas[]) {
  for (int i = 0; i < ABC_LEN; i++)
    if (usadas[i])
      printf("%c ", i + 'a');
  putchar('\n');
}

char solicitarLetra(char usadas[]) {
  char c;
  do {
    printf("\nIngrese una letra no repetida: ");
    c = tolower(getchar());
    CLEAR_BUFFER;
  } while (!isalpha(c) || usadas[c - 'a']);
  usadas[c - 'a']++;
  return c;
}

int checkLetra(char letra, char *palabra) {
  int cantEncontrados = 0;
  for (int i = 0; palabra[i]; i++) {
    cantEncontrados += tolower(palabra[i]) == tolower(letra);
  }
  return cantEncontrados;
}

int checkPalabra(char *palabra, char *usadas) {
  int cantMal = 0;
  for (int i = 0; palabra[i] && !cantMal; i++)
    cantMal = !usadas[palabra[i] - 'a'];
  return !cantMal;
}

void imprimirPalabra(char *palabra, char usadas[]) {
  for (int i = 0; palabra[i]; i++)
    printf("%c", (usadas[palabra[i] - 'a']) ? palabra[i] : '-');
  putchar('\n');
}

void ahogado() {
  char *palabras[N_PALABRAS] = {"almohada",  "palabra", "ejemplo",
                                "membrillo", "mate",    "truco"};
  char *palabra = elegirPalabra(palabras, N_PALABRAS);
  int vidas = INICIO_VIDAS;
  char usadas[ABC_LEN] = {0};
  do {
    printf("Estado actual:\n");
    imprimirPalabra(palabra, usadas);

    printf("Las letras usadas son:\n");
    imprimirUsadas(usadas);

    char c = solicitarLetra(usadas);
    if (checkLetra(c, palabra))
      printf("\nLa letra se encontraba en la palabra!\n");
    else {
      printf("\nLa letra no se encontraba en la palabra!\n");
      vidas--;
    }
    printf("\nVidas restantes: %d\n", vidas);

    putchar('\n');

  } while (!checkPalabra(palabra, usadas) && vidas);

  if (!vidas)
    printf("Te has quedado sin vidas! :(\n");
  else
    printf("Has ganado el juego, felicitaciones!\n");
  printf("La palabra era %s\n", palabra);
}

int main(void) {
  srand(time(NULL));
  ahogado();
  return 0;
}
