#include "ej1.h"
#include <stdio.h>
#include <string.h>

#define N_BOOKS 76
#define BLOCK 20

typedef char *tVerse;

typedef struct {
  size_t sizeAlloc;
  tVerse *verseVec;
} tBook;

typedef tBook booksVec[N_BOOKS];

struct bibleCDT {
  booksVec books;
};

bibleADT newBible() { return calloc(1, sizeof(struct bibleCDT)); }

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char *verse) {
  tBook *book = &bible->books[bookNbr - 1];
  if (book->sizeAlloc < verseNbr) {
    book->verseVec = realloc(book->verseVec, verseNbr * sizeof(book->verseVec));
    for (int i = book->sizeAlloc; i < verseNbr; i++)
      book->verseVec[i] = NULL;
    book->sizeAlloc = verseNbr;
  }
  if (book->verseVec[verseNbr - 1] == NULL) {
    tVerse ver = NULL;
    size_t size;
    for (size = 0; verse[size]; size++) {
      if (size % BLOCK == 0)
        ver = realloc(ver, size + BLOCK);
      ver[size] = verse[size];
    }
    if (size % BLOCK == 0)
      ver = realloc(ver, size + 1);
    ver[size] = verse[size];
    book->verseVec[verseNbr - 1] = ver;
    return 1;
  }
  return 0;
}

char *getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr) {
  if (bookNbr > N_BOOKS || bible->books[bookNbr - 1].sizeAlloc < verseNbr ||
      bible->books[bookNbr - 1].verseVec[verseNbr - 1] == NULL)
    return NULL;
  tVerse verse = bible->books[bookNbr - 1].verseVec[verseNbr - 1];
  tVerse toReturn = NULL;
  size_t size;
  for (size = 0; verse[size]; size++) {
    if (size % BLOCK == 0)
      toReturn = realloc(toReturn, size + BLOCK);
    toReturn[size] = verse[size];
  }
  if (size % BLOCK == 0)
    toReturn = realloc(toReturn, size + BLOCK);
  toReturn[size] = verse[size];
  return toReturn;
}

void freeBible(bibleADT bible) {
  for (int i = 0; i < N_BOOKS; i++) {
    for (int j = 0; j < bible->books[i].sizeAlloc; j++)
      if (bible->books[i].verseVec[j] != NULL)
        free(bible->books[i].verseVec[j]);
    free(bible->books[i].verseVec);
  }
  free(bible);
}
