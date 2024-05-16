#include "../utillist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

TList listUnion(const TList list1, const TList list2) {
  if (list1 == NULL && list2 == NULL)
    return NULL;
  TNode *node = malloc(sizeof(*node));
  if (list2 != NULL && (list1 == NULL || list1->elem > list2->elem)) {
    node->elem = list2->elem;
    node->tail = listUnion(list1, list2->tail);
    return node;
  }
  if (list1 != NULL && (list2 == NULL || list1->elem < list2->elem)) {
    node->elem = list1->elem;
    node->tail = listUnion(list1->tail, list2);
    return node;
  }
  node->elem = list1->elem;
  node->tail = listUnion(list1->tail, list2->tail);
  return node;
}

int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  TList l1 = fromArray(v, 6);
  TList l2 = fromArray(w, 9);
  TList l3 = listUnion(l1, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l1);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, NULL);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(NULL, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);
  freeList(l1);
  freeList(l2);

  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listUnion(l1, l2);
  freeList(l1);
  freeList(l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  printf("OK!\n");
  return 0;
}
