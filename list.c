#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

tList newList(void) { return NULL; }

int isEmpty(const tList l) { return l == NULL; }

int size(const tList l) {
  if (l == NULL)
    return 0;
  return 1 + size(l->tail);
}

int belongs(const tList l, int elem) {
  if (isEmpty(l) || elem < l->head)
    return 0;
  if (elem == l->head)
    return 1;
  return belongs(l->tail, elem);
}

tList add(tList l, int elem) {
  if (l == NULL || elem < l->head) {
    tList newNode = malloc(sizeof(tNode));
    newNode->head = elem;
    newNode->tail = l;
    return newNode;
  }
  if (elem == l->head)
    return l;
  l->tail = add(l->tail, elem);
  return l;
}

tList removeElem(tList l, int elem) {
  if (l == NULL || elem < l->head)
    return l;
  if (l->head == elem) {
    tList aux = l->tail;
    free(l);
    return aux;
  }
  l->tail = removeElem(l->tail, elem);
  return l;
}

void freeList(tList l) {
  if (l == NULL)
    return;
  freeList(l->tail);
  free(l);
}

void freeListIt(tList l) {
  while (l != NULL) {
    tList aux = l;
    l = l->tail;
    free(aux);
  }
}

int *toArray(const tList l) {
  if (isEmpty(l))
    return NULL;
  tList aux = l;
  int dim = size(l);
  int *array = malloc(dim * sizeof(*array));
  for (int i = 0; i < dim; i++) {
    array[i] = aux->head;
    aux = aux->tail;
  }
  return array;
}

int head(const tList l) {
  assert(!isEmpty(l));
  return l->head;
}

tList tail(const tList l) {
  if (isEmpty(l)) {
    sprintf(stderr, "Error al invocar tail");
    exit(1);
  }
  return l->tail;
}

static int getElementAtIndexRec(const tList l, int idx) {
  if (!idx)
    return l->head;
  return getElementAtIndex(l->tail, idx - 1);
}

int getElementAtIndex(const tList l, int idx) {
  assert(idx >= 0 && idx < size(l));
  return getElementAtIndex(l, idx);
}

