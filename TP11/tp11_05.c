#include "tp11_05.h"
#include <assert.h>
#include <stdlib.h>

struct complejoCDT {
  double real;
  double imag;
};

complejoADT nuevoComp(double real, double imag) {
  complejoADT comp = malloc(sizeof(*comp));
  comp->real = real;
  comp->imag = imag;
  return comp;
}

double parteRealComp(complejoADT comp) {
  assert(comp != NULL);
  return comp->real;
}

double parteImagComp(complejoADT comp) {
  assert(comp != NULL);
  return comp->imag;
}

complejoADT conjugadoComp(complejoADT comp) {
  assert(comp != NULL);
  complejoADT conj = nuevoComp(comp->real, -comp->imag);
  return conj;
}

complejoADT sumaComp(complejoADT comp1, complejoADT comp2) {
  assert(comp1 != NULL && comp2 != NULL);
  complejoADT ans = malloc(sizeof(*ans));
  ans->real = comp1->real + comp2->real;
  ans->imag = comp1->imag + comp2->imag;
  return ans;
}

complejoADT restaComp(complejoADT comp1, complejoADT comp2) {
  assert(comp1 != NULL && comp2 != NULL);
  complejoADT ans = malloc(sizeof(*ans));
  ans->real = comp1->real - comp2->real;
  ans->imag = comp1->imag - comp2->imag;
  return ans;
}

// (a + bi)(c + di) = (ac - bd) + (ad + cb)i  se hace distributiva
complejoADT multiplicaComp(complejoADT comp1, complejoADT comp2) {
  assert(comp1 != NULL && comp2 != NULL);
  complejoADT ans = malloc(sizeof(*ans));
  ans->real = (comp1->real * comp2->real) - (comp1->imag * comp2->imag);
  ans->imag = (comp1->real * comp2->imag) + (comp2->real * comp1->imag);
  return ans;
}

// (a + bi)(c + di) = (ac + bd)/(c*c + d*d) + ((cb - ad)/(c*c + d*d))i
// se multiplica arriba y abajo por el conjugado
complejoADT divideComp(complejoADT comp1, complejoADT comp2) {
  assert(comp1 != NULL && comp2 != NULL &&
         (comp2->real != 0 ||
          comp2->imag != 0)); // no se puede dividir por algo nulo
  complejoADT ans = malloc(sizeof(*ans));
  ans->real = ((comp1->real * comp2->real) + (comp1->imag * comp2->imag)) /
              ((comp2->real * comp2->real) + (comp2->imag * comp2->imag));
  ans->imag = ((comp2->real * comp1->imag) - (comp1->real * comp2->imag)) /
              ((comp2->real * comp2->real) + (comp2->imag * comp2->imag));
  return ans;
}

void liberaComp(complejoADT comp) { free(comp); }
