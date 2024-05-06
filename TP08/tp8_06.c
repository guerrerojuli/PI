#include "../getnum.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define DIVISION 100000
#define EPSILON 0.0000001
#define FUNCTION(x) cos(x)

typedef struct {
  double min;
  double max;
} tRange;

typedef struct {
  int dim;
  tRange *vec;
} tVector;

typedef struct {
  double x;
  double y;
} coord;

tVector searchRoots(tRange range) {
  int dimAux = 10, dim = 0;
  double step = (double)(range.max - range.min) / DIVISION;
  coord pAux = {0, 0};
  char inRoot = 0;
  tRange *roots = malloc(dimAux * sizeof(*roots));

  for (double x = range.min; x < range.max; x += step) {
    coord p = {x, FUNCTION(x)};
    if (fabs(p.y) < EPSILON && !inRoot) {
      inRoot = 1;
      if (dim == dimAux) {
        dimAux *= 2;
        roots = realloc(roots, dimAux * sizeof(*roots));
      }
      roots[dim].min = pAux.x;
    } else if (fabs(p.y) > EPSILON && inRoot) {
      inRoot = 0;
      roots[dim++].max = p.x;
    }

    if (p.y * pAux.y < 0) {
      if (dim == dimAux) {
        dimAux *= 2;
        roots = realloc(roots, dimAux * sizeof(*roots));
      }
      roots[dim].min = pAux.x;
      roots[dim++].max = p.x;
    }

    pAux = p;
  }

  tVector res = {dim, realloc(roots, dim * sizeof(*roots))};
  return res;
}

void printRoots(tVector roots) {
  for (int i = 0; i < roots.dim; i++)
    printf("%5.8g\t%5.8g\n", roots.vec[i].min, roots.vec[i].max);
}

int main(void) {
  tRange range = {getfloat("Comienzo del intervalo: "),
                  getfloat("Final del intervalo: ")};
  tVector roots = searchRoots(range);
  printRoots(roots);
  free(roots.vec);
  return 0;
}
