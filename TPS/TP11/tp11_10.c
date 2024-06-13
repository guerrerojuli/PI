#include "tp11_10.h"
#include <assert.h>
#include <stdlib.h>

#define CHUNK 10;

typedef struct item {
  elemType elem;
  size_t count;
  struct item *tail;
} tItem;

typedef tItem *tItems;

struct bagCDT {
  tItems items;
  size_t size;
  compare cmp;
};

static void freeItems(tItems items);
static tItems deleteElemRec(tItems items, elemType elem, size_t *count, compare cmp);
static unsigned int countRec(const tItems items, elemType elem, compare cmp);
unsigned int sizeRec(const tItems bag);
elemType mostPopularRec(const tItems items, size_t *count);

void freeBag(bagADT bag) {
  freeItems(bag->items);
  free(bag);
}

bagADT newBag(compare cmp) {
  bagADT bag = malloc(sizeof(*bag));
  bag->items = NULL;
  bag->size = 0;
  bag->cmp = cmp;
  return bag;
}

unsigned int add(bagADT bag, elemType elem) {
  tItem *newItem = malloc(sizeof(*newItem));
  newItem->elem = elem;
  newItem->count = count(bag, elem) + 1;
  newItem->tail = bag->items;
  bag->items = newItem;
  bag->size++;
  return newItem->count;
}

unsigned int deleteElem(bagADT bag, elemType elem) {
  size_t count = 0;
  bag->items = deleteElemRec(bag->items, elem, &count, bag->cmp);
  bag->size -= (count != 0);
  return count;
}

unsigned int count(const bagADT bag, elemType elem) {
  return countRec(bag->items, elem, bag->cmp);
}

unsigned int size(const bagADT bag) { return sizeRec(bag->items); }

elemType mostPopular(bagADT bag) {
  assert(bag->items != NULL);
  size_t count = 0;
  return mostPopularRec(bag->items, &count);
}

static void freeItems(tItems items) {
  if (items == NULL)
    return;
  freeItems(items->tail);
  free(items);
}

static tItems deleteElemRec(tItems items, elemType elem, size_t *count, compare cmp) {
  if (items == NULL)
    return NULL;
  if (cmp(items->elem, elem) == 0) {
    *count = items->count - 1;
    tItem *next = items->tail;
    free(items);
    return next;
  }
  items->tail = deleteElemRec(items->tail, elem, count, cmp);
  return items;
}

unsigned int countRec(const tItems items, elemType elem, compare cmp) {
  if (items == NULL)
    return 0;
  if (cmp(items->elem, elem) == 0)
    return items->count;
  return countRec(items->tail, elem, cmp);
}

unsigned int sizeRec(const tItems items) {
  if (items == NULL)
    return 0;
  return (items->count == 1) + sizeRec(items->tail);
}

elemType mostPopularRec(const tItems items, size_t *count) {
  if (items->tail == NULL) {
    *count = items->count;
    return items->elem;
  }
  elemType most = mostPopularRec(items->tail, count);
  if (items->count > *count) {
    *count = items->count;
    return items->elem;
  }
  return most;
}
