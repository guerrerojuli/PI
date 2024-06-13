#include "tp11_06-07.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  elemType head;
  struct node *tail;
} tNode;

typedef tNode *tList;

struct listCDT {
  tList first;
  size_t elemCount;
  int (*cmp)(elemType, elemType);
};

listADT newList(int (*cmp)(elemType, elemType)) {
  listADT l = malloc(sizeof(*l));
  l->first = NULL;
  l->elemCount = 0;
  l->cmp = cmp;
  return l;
}

int size(const listADT l) { return l->elemCount; }

int isEmpty(const listADT l) { return l->elemCount == 0; }

static tList addRec(tList list, elemType elem, int (*cmp)(elemType, elemType),
                    int *flag) {
  int c;
  if (list == NULL || (c = cmp(elem, list->head)) < 0) {
    tList newNode = malloc(sizeof(tNode));
    newNode->head = elem;
    newNode->tail = list;
    *flag = 1;
    return newNode;
  }
  if (c == 0) {
    return list;
  }
  list->tail = addRec(list->tail, elem, cmp, flag);
  return list;
}

int add(listADT l, elemType elem) {
  int added = 0;
  l->first = addRec(l->first, elem, l->cmp, &added);
  l->elemCount += added;
  return added;
}

static void freeListRec(tList list) {
  if (list == NULL) {
    return;
  }
  freeListRec(list->tail);
  free(list);
}

void freeList(listADT l) {
  freeListRec(l->first);
  free(l);
}

elemType getElementAtIndex(const listADT l, int idx) {
  assert(l->elemCount > idx);
  tList listAux = l->first;
  for (int i = 0; i < idx; i++)
    listAux = listAux->tail;
  return listAux->head;
}

void map(listADT l, elemType (*func)(elemType)) {
  tList listAux = l->first;
  for (int i = 0; i < l->elemCount; i++) {
    listAux->head = func(listAux->head);
    listAux = listAux->tail;
  }
  return;
}
