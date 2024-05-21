#include "../getnum.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define DIVISION 100000
#define EPSILON 0.0000001

typedef double (*tFunction)(double);

typedef struct {
  tFunction function;
  char *name;
} tFunctionInfo;

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

tVector searchRoots(tRange range, tFunction function) {
  int dimAux = 10, dim = 0;
  double step = (double)(range.max - range.min) / DIVISION;
  coord pAux = {0, 0};
  char inRoot = 0;
  tRange *roots = malloc(dimAux * sizeof(*roots));

  for (double x = range.min; x < range.max; x += step) {
    coord p = {x, function(x)};
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

int menu(tFunctionInfo functions[], size_t dim) {
  int option;
  do {
    puts("Seleccione su función");
    for (int i = 0; i < dim; i++) {
      printf("%d- %s\n", i + 1, functions[i].name);
    } 
    option = getint("");
  } while(!(option > 0 && option < dim));
  return option-1;
}

int main(void) {
  tFunctionInfo functions[] = {
    { sin, "sin" },
    { cos, "cos" },
    { log, "log" },
    { tan, "tan" }
  };
  int option = menu(functions, sizeof(functions)/sizeof(*functions));
  tRange range = {getfloat("Comienzo del intervalo: "),
                  getfloat("Final del intervalo: ")};
  tVector roots = searchRoots(range, functions[option].function);
  printRoots(roots);
  free(roots.vec);
  return 0;
}
