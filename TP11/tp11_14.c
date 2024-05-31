#include "tp11_14.h"
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 20;

typedef struct node {
  elemType elem;
  struct node *nextAsc;
} tNode;

typedef tNode *tList;

struct listCDT {
  tList listAsc;
  tNode *currentAsc;
  tNode **vecIn;
  int currentInIdx;
  size_t size;
  size_t allocSize;
  compareFunc cmp;
};

static tNode *addAsc(tList listAsc, elemType elem, compareFunc cmp,
                     tNode **addedNode);
static void addIn(listADT list, tNode *node);

listADT newList(int (*compare)(elemType e1, elemType e2)) {
  listADT list = calloc(1, sizeof(*list));
  list->currentInIdx = -1;
  list->cmp = compare;
  return list;
}

void add(listADT list, elemType elem) {
  tNode *addedNode;
  list->listAsc = addAsc(list->listAsc, elem, list->cmp, &addedNode);
  if (addedNode != NULL)
    addIn(list, addedNode);
}

/* Elimina un elemento. */
// void remove(listADT list, elemType elem);

void toBegin(listADT list) { list->currentInIdx = 0; }

int hasNext(listADT list) {
  return (list->currentInIdx != -1 && list->currentInIdx + 1 < list->size);
}

elemType next(listADT list) {
  if (list->currentInIdx == -1 || list->currentInIdx >= list->size)
    abort();
  return list->vecIn[list->currentInIdx++]->elem;
}

void toBeginAsc(listADT list) { list->currentAsc = list->listAsc; }

int hasNextAsc(listADT list) {
  return (list->currentAsc != NULL && list->currentAsc->nextAsc != NULL);
}

elemType nextAsc(listADT list) {
  if (list->currentAsc == NULL)
    abort();
  elemType toReturn = list->currentAsc->elem;
  list->currentAsc = list->currentAsc->nextAsc;
  return toReturn;
}

void freeList(listADT list) {
  for (int i = 0; i < list->size; i++)
    free(list->vecIn[i]);
  free(list->vecIn);
  free(list);
}

static tNode *addAsc(tList listAsc, elemType elem, compareFunc cmp,
                     tNode **addedNode) {
  int comp;
  *addedNode = NULL;
  if (listAsc == NULL || (comp = cmp(listAsc->elem, elem)) > 0) {
    tNode *newNode = malloc(sizeof(*newNode));
    *addedNode = newNode;
    newNode->elem = elem;
    newNode->nextAsc = listAsc;
    return newNode;
  }
  if (comp < 0)
    listAsc->nextAsc = addAsc(listAsc->nextAsc, elem, cmp, addedNode);
  return listAsc;
}

static void addIn(listADT list, tNode *node) {
  if (list->size == list->allocSize) {
    list->allocSize += CHUNK;
    list->vecIn = realloc(list->vecIn, list->allocSize * sizeof(*list->vecIn));
  }
  list->vecIn[list->size++] = node;
}
