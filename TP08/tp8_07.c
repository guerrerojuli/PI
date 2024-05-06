#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 7
#define FILS 6

typedef enum { DER = 0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

struct posicion {
  char *palabra;
  size_t fila;
  size_t columna;
  Tdireccion direccion;
};

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar
// diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra
//       se busca en la sopa de letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si
//hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que
//       coincida con el orden en que se encuentran.

struct posicion *resolverSopa(char *diccionario[], char matriz[FILS][COLS]) {
  int dimAux = 10, dim = 0;
  struct posicion *res = malloc(dimAux * sizeof(*res));
  for (int i = 0; *diccionario[i]; i++) {
    for (int j = 0; 
  }
  return realloc(res, dim * sizeof(*res));
}

int main(void) {
  char *diccionario[] = {"ARRE",  "CANCION",  "CAPA", "ERROR", "ORCO",
                         "PERRO", "PERTINAZ", "REA",  "RIO",   ""};

  char sopa[FILS][COLS] = {
      {'X', 'X', 'X', 'O', 'X', 'X', 'X'}, {'A', 'P', 'A', 'C', 'Y', 'Y', 'O'},
      {'Z', 'E', 'Z', 'R', 'Z', 'C', 'X'}, {'E', 'R', 'R', 'O', 'R', 'X', 'X'},
      {'X', 'R', 'I', 'O', 'I', 'E', 'X'}, {'X', 'O', 'X', 'X', 'O', 'X', 'X'}};

  struct posicion *res = resolverSopa(diccionario, sopa);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while (res[count].palabra != NULL)
    printf("%s\n", res[count++].palabra);
  assert(count == expected);

  assert(strcmp(res[0].palabra, "ARRE") == 0);
  assert(res[0].fila == 1);
  assert(res[0].columna == 2);
  assert(res[0].direccion == D_AB);

  assert(strcmp(res[3].palabra, "ORCO") == 0);
  assert(res[3].fila == 3);
  assert(res[3].columna == 3);
  printf("%d\n", res[3].direccion);
  assert(res[3].direccion == ARR);

  assert(strcmp(res[4].palabra, "ORCO") == 0);
  assert(res[4].fila == 4);
  assert(res[4].columna == 3);
  assert(res[4].direccion == D_AR);

  assert(strcmp(res[6].palabra, "REA") == 0);
  assert(res[6].fila == 3);
  assert(res[6].columna == 2);
  assert(res[6].direccion == I_AR);

  puts("OK");
  return 0;
}
