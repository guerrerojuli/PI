#include "tp11_11.h"
#include <stdlib.h>

struct vectorCDT {
  elemType **vec;
  size_t cantElem;
  size_t allocSize;
  int (*cmp)(elemType source, elemType target);
};

vectorADT newVector(int (*compare)(elemType source, elemType target)) {
  vectorADT newVec = malloc(sizeof(*newVec));
  newVec->vec = NULL;
  newVec->cantElem = newVec->allocSize = 0;
  newVec->cmp = compare;
  return newVec;
}

void freeVector(vectorADT v) {
  for (int i = 0; i < v->allocSize; i++)
    if (v->vec[i] != NULL)
      free(v->vec[i]);
  free(v->vec);
  free(v);
}

size_t put(vectorADT v, elemType *elems, size_t dim, size_t index) {
  size_t oldSize = v->allocSize;
  if (v->allocSize < index + dim) {
    v->allocSize = index + dim;
    v->vec = realloc(v->vec, v->allocSize * sizeof(*v->vec));
  }
  size_t start = (oldSize < index) ? oldSize : index; // para arrancar apartir de donde necesito
  size_t indexFromStart = index - start;
  size_t countCopied = 0;
  for (int i = start, j = 0; i < v->allocSize && countCopied < dim; i++, j++) {
    // significa que no arrancó la parte de copiar pero estoy en una parte nueva
    if (i >= oldSize && j < indexFromStart)
      v->vec[i] = NULL;
    else if (i >= oldSize || v->vec[i] == NULL){
        v->vec[i] = malloc(sizeof(elemType));
        *v->vec[i] = elems[countCopied++];
    }
  }
  v->cantElem += countCopied;
  return countCopied;
}

int getIdx(vectorADT v, elemType elem) {
  for(int i = 0; i < v->allocSize; i++) 
    if(v->vec[i] != NULL && v->cmp(*v->vec[i], elem) == 0)
      return i;
  return -1;
}

void deleteElement(vectorADT v, size_t index) {
  if (index >= v->allocSize || v->vec[index] == NULL)
    return;
  free(v->vec[index]);
  v->vec[index] = NULL;
  v->cantElem--;
}

int elementCount(vectorADT v) {
  return v->cantElem;
}
