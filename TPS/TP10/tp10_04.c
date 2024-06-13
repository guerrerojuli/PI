#include "../utillist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

TList addAll(TList lista1, TList lista2) {
  // Si lista2 está vacía no hay nada para agregar
  if (lista2 == NULL)
    return lista1;
  // Si lista1 está vacía, entonces siempre tengo que agregar cosas
  if (lista1 == NULL || lista1->elem > lista2->elem) {
    TNode *newNode = malloc(sizeof(TNode));
    newNode->elem = lista2->elem;
    newNode->tail = addAll(lista1, lista2->tail);
    return newNode;
  }
  if (lista1->elem < lista2->elem)
    lista1->tail = addAll(lista1->tail, lista2);
  else
    lista1->tail = addAll(lista1->tail, lista2->tail);
  return lista1;
}

#define ELEMS 200

int main(void) {

  int pares[ELEMS], impares[ELEMS];

  for (int i = 1; i <= ELEMS; i++) {
    pares[i - 1] = i * 2;
    impares[i - 1] = i * 2 - 1;
  }

  TList lPar = fromArray(pares, ELEMS);
  TList lImpar = fromArray(impares, ELEMS);

  lPar = addAll(lPar, lImpar);

  int all[ELEMS * 2];
  for (int i = 1, j = 0; i <= ELEMS; i++) {
    all[j++] = i * 2 - 1;
    all[j++] = i * 2;
  }
  assert(checkElems(lPar, all, ELEMS * 2));
  freeList(lPar);

  lPar = NULL;
  lPar = addAll(lPar, lImpar);
  assert(checkElems(lPar, impares, ELEMS));

  lPar = addAll(lPar, lImpar);
  assert(checkElems(lPar, impares, ELEMS));
  freeList(lPar);

  lPar = fromArray(pares, ELEMS);
  lImpar = addAll(lImpar, lPar);
  assert(checkElems(lImpar, all, ELEMS * 2));
  freeList(lPar);
  freeList(lImpar);

  int w[] = {1, 2, 3, 4, 5, 6, 7, 8};
  TList l1 = fromArray(w, 3);
  TList l2 = fromArray(w + 3, 5);
  l1 = addAll(l1, l2);
  assert(checkElems(l1, w, 8));
  freeList(l1);
  freeList(l2);

  l1 = fromArray(w, 8);
  l2 = fromArray(w, 8);
  l1 = addAll(l1, l2);
  assert(checkElems(l1, w, 8));
  freeList(l2);
  freeList(l1);

  printf("OK!\n");
  return 0;
}