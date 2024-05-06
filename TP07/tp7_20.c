#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *TAlumnos[];

char **aprobados(char *alumnos[], int notas[]) {
  int dim = 0, dimAux = 10, i;
  char **aprob = malloc(dimAux * sizeof(*aprob));
  for (i = 0; *alumnos[i]; i++) {
    if (notas[i] >= 4) {
      if (dim == dimAux) {
        dimAux *= 2;
        aprob = realloc(aprob, dimAux * sizeof(*aprob));
      }
      aprob[dim++] = alumnos[i];
    }
  }
  aprob[dim++] = alumnos[i];
  return realloc(aprob, dim * sizeof(*aprob));
}


int main(void) {
  TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
  int notas[] = {1, 4, 10, 2, 10, 11};

  char **apr = aprobados(alumnos, notas);
  if (apr == NULL) {
    printf("No hay suficiente memoria!\n");
    return 1;
  }
  assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) &&
         !strcmp(alumnos[3], apr[2]));

  puts("OK!");
  // En este programa no liberamos la memoria que utilizamos. Que ocurre si
  // compilamos con "-fsanitize=address"?
  return 0;
}
