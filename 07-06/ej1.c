#include "ej1.h"
#include <stdio.h>
#include <string.h>

#define N_BOOKS 76
#define BLOCK 20;

typedef struct verse {
  size_t len;
  char *text;
} tVerse;

typedef struct {
  size_t sizeAlloc;
  tVerse **verseVec;
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
      book->verseVec[i] = 0;
    book->sizeAlloc = verseNbr;
  }
  if (book->verseVec[verseNbr - 1] == NULL) {
    tVerse *ver = calloc(1, sizeof(tVerse));
    book->verseVec[verseNbr - 1] = ver;
    size_t size;
    for (size = 0; verse[ver->len]; ver->len++) {
      if (size == ver->len) {
        size += BLOCK;
        ver->text = realloc(ver->text, size);
      }
      ver->text[ver->len] = verse[ver->len];
    }
    if (size == ver->len) {
      size += BLOCK;
      ver->text = realloc(ver->text, size);
    }
    ver->text[ver->len] = 0;
    return 1;
  }
  return 0;
}

char *getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr) {
  if (bookNbr > N_BOOKS || bible->books[bookNbr - 1].sizeAlloc < verseNbr ||
      bible->books[bookNbr - 1].verseVec[verseNbr - 1] == NULL)
    return NULL;
  char *toReturn =
      malloc(bible->books[bookNbr - 1].verseVec[verseNbr - 1]->len + 1);
  strcpy(toReturn, bible->books[bookNbr - 1].verseVec[verseNbr - 1]->text);
  return toReturn;
}

void freeBible(bibleADT bible) {
  for (int i = 0; i < N_BOOKS; i++) {
    for (int j = 0; j < bible->books[i].sizeAlloc; j++)
      if (bible->books[i].verseVec[j] != NULL) {
        free(bible->books[i].verseVec[j]->text);
        free(bible->books[i].verseVec[j]);
      }
    free(bible->books[i].verseVec);
  }
  free(bible);
}
