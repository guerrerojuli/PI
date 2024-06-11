#define BLOCK 100

typedef int (*compareFunc) (landmarkType landmark1, landmarkType landmark2);

struct landmarkCDT {
  size_t allocSize;
  size_t cantElem;
  char *existVec;
  landmarkType *landmarkVec;
  compareFunc cmp;
};

landmarkADT newLandmark(compareFunc cmp) {
  landmarkADT landmark = calloc(1, sizeof(struct landmarkCDT));
  landmark->cmp = cmp;
  return landmark;
}

void addLandmark(landmarkADT landmark, size_t meters, landmarkType site) {
  size_t index = meters / BLOCK;
  if (index >= landmark->allocSize) {
    landmark->landmarkVec = realloc(landmark->landmarkVec, (index + 1) * sizeof(*landmark->landmarkVec));
    landmark->existVec = realloc(landmark->existVec, (index + 1) * sizeof(*landmark->existVec));
    for (int i = landmark->allocSize; i < index + 1; i++)
      landmark->existVec[i] = 0;
    landmark->allocSize = index + 1;
  }
  if (!landmark->existVec[index])
    landmark->cantElem += (landmark->existVec[index] = 1);
  landmark->landmarkVec[index] = site;
}

landmarkType *landmarks(const landmarkADT landmark) {
  if (!landmark->cantElem)
    return NULL;
  landmarkType *toReturn = malloc(landmark->cantElem * sizeof(*toReturn));
  for (size_t i = 0, j = 0; i < landmark->allocSize; i++)
    if(landmark->existVec[i])
      toReturn[j++] = landmark->landmarkVec[i];
  return toReturn;
}
