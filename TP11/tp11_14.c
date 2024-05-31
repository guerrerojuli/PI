#include <stdlib.h>
#include "tp11_14.h"

typedef struct node {
  elemType elem;
  struct node *nextAsc;
  struct node *nextIn;
} tNode;

 typedef tNode *tList;

struct listCDT {
  tList firstIn;
  tNode *currentIn;
  tList firstAsc;
  tNode *currentAsc;
  compareFunc cmp; 
};

static void addRec(tList listAsc, elemType elem, compareFunc cmp);
static void actualizeIn(tList listIn, tNode *node);

listADT newList(int (*compare) (elemType e1, elemType e2)) {
  listADT list = calloc(1, sizeof(*list));
  list->cmp = compare;
  return list;
}

void add(listADT list, elemType elem) {
  if (list->firstIn == NULL) {
    tNode *newElem = malloc(sizeof(*newElem));
    newElem->nextIn = newElem->nextAsc = NULL;
    list->firstIn = list->firstAsc = newElem;
    return;
  }
  addRec(list->firstAsc, elem, list->cmp);
}


/* Elimina un elemento. */
//void remove(listADT list, elemType elem);

void toBegin(listADT list) {
  list->currentIn = list->firstIn; 
}

int hasNext(listADT list) {
  return (list->currentIn != NULL && list->currentIn->nextIn != NULL);
}

elemType next(listADT list) {
  if (list->currentIn == NULL || list->currentIn->nextIn == NULL)
    exit(1);
  list->currentIn = list->currentIn->nextIn;
  return list->currentIn->elem;
}

void toBeginAsc(listADT list) {
  list->currentAsc = list->firstAsc;
}

int hasNextAsc(listADT list) {
  return (list->currentAsc != NULL && list->currentAsc->nextIn != NULL);
}

elemType nextAsc(listADT list) {
  if (list->currentAsc == NULL || list->currentAsc->nextIn == NULL)
    exit(1);
  list->currentAsc = list->currentAsc->nextIn;
  return list->currentAsc->elem;
}

void freeList(listADT list) {
  tNode *next;
  for (tNode *current = list->currentAsc; current != NULL; current = next) {
    next = current->nextIn;
    free(current);
  }
  free(list);
}

static void addRec(tList listAsc, elemType elem, compareFunc cmp) {
  tNode *next = listAsc->nextAsc;
  int comp;
  if (next == NULL || (comp = cmp(next->elem, elem)) > 0) {
    tNode *newNode = malloc(sizeof(*newNode));
    newNode->elem = elem;
    newNode->nextAsc = next;
    newNode->nextIn = NULL;
    actualizeIn(listAsc, newNode); 
  }
  if (comp < 0)
    addRec(listAsc->nextAsc, elem, cmp);
}

static void actualizeIn(tList listIn, tNode *node) {
  if(listIn->nextIn == NULL) {
    listIn->nextIn = node;
    return;
  }
  actualizeIn(listIn->nextIn, node);
}
