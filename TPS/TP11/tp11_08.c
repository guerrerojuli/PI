#include "tp11_08.h"
#include <stdlib.h>

#define CHUNK 20

typedef char **tSet;

struct setCDT {
  tSet set;
  size_t size;
  size_t allocSize; // Allocated Size
  cmpFunc cmp;
};

static setADT unionSetHelper(setADT larger, setADT shorter);

setADT newSet(cmpFunc cmp) {
  setADT set = malloc(sizeof(*set));
  set->set = NULL;
  set->size = 0;
  set->allocSize = 0;
  set->cmp = cmp;
  return set;
}

int addElement(setADT set, elemType elem) {
  if (setContains(set, elem))
    return 0;
  if (set->size == set->allocSize) {
    set->allocSize += CHUNK;
    set->set = realloc(set->set, set->allocSize * sizeof(*set->set));
  }
  set->set[set->size++] = elem;
  return 1;
}

int deleteElement(setADT set, elemType elem) {
  for (int i = 0; i < set->size; i++)
    if (set->set[i] == elem) {
      set->set[i] = set->set[--set->size];
      return 1;
    }
  return 0;
}

setADT unionSet(setADT set1, setADT set2) {
  return (set1->size > set2->size) ? unionSetHelper(set1, set2)
                                   : unionSetHelper(set2, set1);
}

setADT intersectionSet(setADT set1, setADT set2) {
  setADT resSet = newSet(set1->cmp);
  for (int i = 0; i < set1->size; i++)
    if (setContains(set2, set1->set[i])) {
      if (resSet->size == resSet->allocSize) {
        resSet->allocSize += CHUNK;
        resSet->set =
            realloc(resSet->set, resSet->allocSize * sizeof(*resSet->set));
      }
      resSet->set[resSet->size++] = set1->set[i];
    }
  return resSet;
}

setADT diffSet(setADT set1, setADT set2) {
  setADT resSet = newSet(set1->cmp);
  for (int i = 0; i < set1->size; i++)
    if (!setContains(set2, set1->set[i])) {
      if (resSet->size == resSet->allocSize) {
        resSet->allocSize += CHUNK;
        resSet->set =
            realloc(resSet->set, resSet->allocSize * sizeof(*resSet->set));
      }
      resSet->set[resSet->size++] = set1->set[i];
    }
  return resSet;
}

int setContains(setADT set, elemType elem) {
  for (int i = 0; i < set->size; i++)
    if (set->set[i] == elem)
      return 1;
  return 0;
}

int isEmptySet(setADT set) { return !set->size; }

int sizeSet(setADT set) { return set->size; }

void freeSet(setADT set) {
  free(set->set);
  free(set);
}

static setADT unionSetHelper(setADT longSet, setADT shortSet) {
  setADT resSet = newSet(longSet->cmp);
  resSet->size = resSet->allocSize = longSet->size;
  resSet->set = malloc(resSet->allocSize * sizeof(*resSet->set));
  for (int i = 0; i < longSet->size; i++)
    resSet->set[i] = longSet->set[i];
  for (int i = 0; i < shortSet->size; i++)
    addElement(resSet, shortSet->set[i]);
  return resSet;
}
