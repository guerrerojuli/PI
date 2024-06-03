#include "ej1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHUNK 10

struct palabraCDT {
  char *palabra;
  size_t size;
  size_t allocSize;
};

palabraADT crearVacia() {
  return calloc(1, sizeof(struct palabraCDT));
}

palabraADT crearDesde(char *s) {
  palabraADT palabra = malloc(sizeof(*palabra));
  palabra->size = palabra->allocSize = strlen(s) + 1;
  palabra->palabra = malloc(palabra->allocSize * sizeof(*palabra->palabra));
  strcpy(palabra->palabra, s);
  return palabra;
}

void destruirPalabra(palabraADT palabra) {
  free(palabra->palabra);
  free(palabra);
}

void mostrarPalabra(palabraADT palabra) {
  for (int i = 0; palabra->palabra[i]; i++)
    putchar(palabra->palabra[i]);
}

palabraADT agregarLetra(palabraADT palabra, char letra) {
  if (palabra->size == palabra->allocSize) {
    palabra->allocSize += CHUNK;
    palabra->palabra = realloc(palabra->palabra, palabra->allocSize * sizeof(*palabra->palabra));
  }
  palabra->palabra[palabra->size++] = letra;
  palabra->palabra[palabra->size] = 0;
  return palabra;
}
