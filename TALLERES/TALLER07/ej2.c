#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INCREMENTO 2
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIM(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
  int x;
  int y;
} tPunto2D;

typedef struct {
  int dx;
  int dy;
} tIncremento2D;

tPunto2D actualizarPosicion(tPunto2D punto) {
  tIncremento2D incremento;
  srand(time(NULL));
  incremento.dx = (rand() % (2 * MAX_INCREMENTO)) - MAX_INCREMENTO;
  incremento.dy = (rand() % (2 * MAX_INCREMENTO)) - MAX_INCREMENTO;
  punto.x += incremento.dx;
  punto.y += incremento.dy;
  return punto;
}

int main(void) {
  int dimAux = 10, dim = 0;
  tPunto2D *puntos = malloc(dimAux * sizeof(*puntos));
  tPunto2D posicion = {0, 0};
  puntos[dim++] = posicion;
  do {
    posicion = actualizarPosicion(posicion);
    if (dim == dimAux) {
      dimAux *= 2;
      puntos = realloc(puntos, dimAux * sizeof(*puntos));
    }
    puntos[dim++] = posicion;
    printf("(%d, %d)\n", posicion.x, posicion.y);
  } while (posicion.x != 0 || posicion.y != 0);
  puntos = realloc(puntos, dim * sizeof(*puntos));
  for (int i = 0; i < dim; i++)
    printf("(%d, %d)\n", puntos[i].x, puntos[i].y);
  return 0;
}
