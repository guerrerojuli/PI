#include "tp11_13.h"

#define CHUNK 10;

struct rankingCDT {
  elemType *elems;
  size_t size;
  size_t allocSize;
  compare cmp;
};

rankingADT newRanking(elemType elems[], size_t dim, compare cmp) {
  rankingADT ranking = malloc(sizeof(*ranking));
  ranking->elems = malloc(dim * sizeof(*ranking->elems));
  for (int i = 0; i < dim; i++)
    ranking->elems[i] = elems[i];
  ranking->size = ranking->allocSize = dim;
  ranking->cmp = cmp;
  return ranking;
}

void addRanking(rankingADT ranking, elemType elem) {
  if (contains(ranking, elem))
    return;
  if (ranking->size == ranking->allocSize) {
    ranking->allocSize += CHUNK;
    ranking->elems =
        realloc(ranking->elems, ranking->allocSize * sizeof(*ranking->elems));
  }
  ranking->elems[ranking->size++] = elem;
}

size_t size(const rankingADT ranking) { return ranking->size; }

int getByRanking(rankingADT ranking, size_t n, elemType *elem) {
  if (n - 1 >= ranking->size)
    return 0;
  *elem = ranking->elems[n - 1];
  if (n != 1) {
    ranking->elems[n - 1] = ranking->elems[n - 2];
    ranking->elems[n - 2] = *elem;
  }
  return 1;
}

elemType *getTopRanking(const rankingADT ranking, size_t *top) {
  if (ranking->size < *top)
    *top = ranking->size;
  elemType *topRanking = (*top) ? malloc(*top * sizeof(*topRanking)) : NULL;
  for (int i = 0; i < *top; i++)
    topRanking[i] = ranking->elems[i];
  return topRanking;
}

int contains(rankingADT ranking, elemType elem) {
  int n = position(ranking, elem);
  if (!n)
    return 0;
  if (n == 1)
    return 1; // Si es el primero, no hago nada
  ranking->elems[n - 1] = ranking->elems[n - 2];
  ranking->elems[n - 2] = elem;
  return 1;
}

void downByRanking(rankingADT ranking, size_t n) {
  if (n >= ranking->size)
    return;
  elemType elem = ranking->elems[n - 1];
  ranking->elems[n - 1] = ranking->elems[n];
  ranking->elems[n] = elem;
}

void freeRanking(rankingADT r) {
  free(r->elems);
  free(r);
}

int position(const rankingADT r, elemType elem) {
  for (int i = 0; i < r->size; i++)
    if (r->cmp(r->elems[i], elem) == 0)
      return i + 1;
  return 0;
}
