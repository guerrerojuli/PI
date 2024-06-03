#include "tp11_16.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define IS_BETWEEN(n, from, to) ((from) <= (n) && (n) <= (to))


typedef struct node {
  char *phrase;
  size_t phraseLen;
  size_t key;
  struct node *next;
} tPhrase;

typedef tPhrase *tPhraseList;

struct phrasesCDT {
  size_t keyFrom;
  size_t keyTo;
  size_t size;
  tPhraseList phraseList;
};


static void freePhraseList(tPhraseList phraseList);
static tPhraseList insertPhrase(tPhraseList phraseList, size_t key, const char *phrase, size_t *size);
static char *getPhrase(tPhraseList phraseList, size_t key);


phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo) {
  if (keyFrom > keyTo)
    return NULL;
  phrasesADT phrases = malloc(sizeof(*phrases));
  phrases->keyFrom = keyFrom;
  phrases->keyTo = keyTo;
  phrases->size = 0;
  phrases->phraseList = NULL;
  return phrases;
}

void freePhrases(phrasesADT ph) {
  freePhraseList(ph->phraseList);
  free(ph);
}

int put(phrasesADT ph, size_t key, const char *phrase) {
  if (!IS_BETWEEN(key, ph->keyFrom, ph->keyTo))
    return 0;
  ph->phraseList = insertPhrase(ph->phraseList, key, phrase, &ph->size);
  return 1;
}

char *get(const phrasesADT ph, size_t key) {
  char *phrase;
  if (!IS_BETWEEN(key, ph->keyFrom, ph->keyTo) || (phrase = getPhrase(ph->phraseList, key)) == NULL)
    return NULL;
  return phrase;
}

size_t size(const phrasesADT ph) {
  return ph->size;
}

char *concatAll(const phrasesADT ph) {
  char *concat = calloc(1, sizeof(char));
  size_t concatLen = 0;
  for (tPhrase *current = ph->phraseList; current != NULL; current = current->next) {
    concat = realloc(concat, (concatLen + current->phraseLen + 1) * sizeof(*concat));
    strcat(concat + concatLen, current->phrase);
    concatLen += current->phraseLen;
  }
  return concat;
}

char *concat(const phrasesADT ph, size_t from, size_t to) {
  if (!IS_BETWEEN(from, ph->keyFrom, ph->keyTo) || !IS_BETWEEN(to, ph->keyFrom, ph->keyTo))
    return NULL;
  char *concat = calloc(1, sizeof(char));
  size_t concatLen = 0;
  for (tPhrase *current = ph->phraseList; current != NULL && current->key <= to; current = current->next)
    if (from <= current->key) {
      concat = realloc(concat, (concatLen + current->phraseLen + 1) * sizeof(*concat));
      strcat(concat + concatLen, current->phrase);
      concatLen += current->phraseLen;
    }
  return concat;
}

static void freePhraseList(tPhraseList phraseList) {
  if (phraseList == NULL)
    return;
  freePhraseList(phraseList->next);
  free(phraseList->phrase);
  free(phraseList);
}

static tPhraseList insertPhrase(tPhraseList phraseList, size_t key, const char *phrase, size_t *size) {
  if (phraseList == NULL || phraseList->key > key) {
    tPhrase *phraseNode = malloc(sizeof(*phraseNode));
    phraseNode->key = key;
    phraseNode->phraseLen = strlen(phrase);
    phraseNode->phrase = malloc((phraseNode->phraseLen + 1) * sizeof(*phraseNode->phrase));
    strcpy(phraseNode->phrase, phrase);
    phraseNode->next = phraseList;
    *size += 1;
    return phraseNode;
  }
  if (phraseList->key == key) {
    phraseList->phraseLen = strlen(phrase);
    phraseList->phrase = realloc(phraseList->phrase, (phraseList->phraseLen + 1) * sizeof(*phraseList->phrase));
    strcpy(phraseList->phrase, phrase);
    return phraseList;
  }
  phraseList->next = insertPhrase(phraseList->next, key, phrase, size);
  return phraseList;
}

static char *getPhrase(tPhraseList phraseList, size_t key) {
  if (phraseList == NULL || phraseList->key > key)
    return NULL;
  if (phraseList->key == key) {
    char *phrase = malloc((phraseList->phraseLen + 1) * sizeof(*phrase));
    return strcpy(phrase, phraseList->phrase);
  }
  return getPhrase(phraseList->next, key);
}
