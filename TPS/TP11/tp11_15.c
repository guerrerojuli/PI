#include "tp11_15.h"
#include <stdlib.h>

// top -> next -> next -> next -> bottom
typedef struct node {
  elemType elem;
  struct node *next;
} tNode;

typedef tNode *tList;

typedef struct moveToFrontCDT {
  size_t size;
  tList top;
  tNode *current;
  compare cmp;
} moveToFrontCDT;

static void freeList(tList list);
static tList addElemToList(tList list, elemType elem, compare cmp, int *addedFlag);
static tList popElemFromList(tList list, elemType elem, compare cmp, tNode **pop);

moveToFrontADT newMoveToFront(compare cmp) {
  moveToFrontADT moveToFront = calloc(1, sizeof(moveToFrontCDT));
  moveToFront->cmp = cmp;
  return moveToFront;
}

void freeMoveToFront(moveToFrontADT moveToFront) {
  freeList(moveToFront->top);
  free(moveToFront);
}

unsigned int add(moveToFrontADT moveToFront, elemType elem) {
  int addedFlag = 0;
  moveToFront->top = addElemToList(moveToFront->top, elem, moveToFront->cmp, &addedFlag);
  moveToFront->size += addedFlag;
  return addedFlag;
}

unsigned int size(moveToFrontADT moveToFront) {
  return moveToFront->size;
}

void toBegin(moveToFrontADT moveToFront) {
  moveToFront->current = moveToFront->top;
}

int hasNext(moveToFrontADT moveToFront) {
  return (moveToFront->current != NULL);
}

elemType next(moveToFrontADT moveToFront) {
  if (!hasNext(moveToFront))
    abort();
  elemType toReturn = moveToFront->current->elem;
  moveToFront->current = moveToFront->current->next;
  return toReturn;
}

elemType *get(moveToFrontADT moveToFront, elemType elem) {
  tNode *popElem = NULL; 
  moveToFront->top = popElemFromList(moveToFront->top, elem, moveToFront->cmp, &popElem);
  if (popElem == NULL)
    return NULL;
  popElem->next = moveToFront->top;
  moveToFront->top = popElem;
  elemType *toReturn = malloc(sizeof(*toReturn));
  *toReturn = popElem->elem;
  return toReturn;
}

static void freeList(tList list) {
  if (list == NULL)
    return;
  freeList(list->next);
  free(list);
}

static tList addElemToList(tList list, elemType elem, compare cmp, int *addedFlag) {
  *addedFlag = 0;
  if (list == NULL) {
    tNode *newNode = calloc(1, sizeof(*newNode));
    newNode->elem = elem;
    *addedFlag = 1;
    return newNode;
  }
  if (cmp(list->elem, elem) != 0)
    list->next = addElemToList(list->next, elem, cmp, addedFlag);
  return list;
}

static tList popElemFromList(tList list, elemType elem, compare cmp, tNode **pop) {
  if (list == NULL)
    return list;
  if (cmp(list->elem, elem) == 0) {
    *pop = list;
    return list->next;
  }
  list->next = popElemFromList(list->next, elem, cmp, pop);
  return list;
}
