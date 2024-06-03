#include "tp11_16.h"
#include <stdlib.h>
#include <string.h>


#define IS_BETWEEN(n, from, to) ((from) < (n) && (n) < (to))


typedef struct node {
  char *phrase;
  size_t key;
  struct node *next;
} tPhrase;

typedef tPhrase *tPhraseList;

struct phrasesCDT {
  size_t keyFrom;
  size_t keyTo;
  tPhraseList phraseList;
};


static void freePhraseList(tPhraseList phraseList);
static tPhraseList insertPhrase(tPhraseList phraseList, size_t key, const char *phrase);
static char *getPhrase(tPhraseList phraseList, size_t key);


phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo) {
  if (keyFrom > keyTo)
    return NULL;
  phrasesADT phrases = malloc(sizeof(*phrases));
  phrases->keyFrom = keyFrom;
  phrases->keyTo = keyTo;
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
  ph->phraseList = insertPhrase(ph->phraseList, key, phrase);
  return 1;
}

char *get(const phrasesADT ph, size_t key) {
  char *phrase;
  if (!IS_BETWEEN(key, ph->keyFrom, ph->keyTo) || (phrase = getPhrase(ph->phraseList, key)) == NULL)
    return NULL;
  return phrase;
}
/*
 * Cantidad de frases almacenadas
 */
size_t size(const phrasesADT ph);

/*
 * Retorna un string con todas las frases concatenadas
 * Si no hay frases retorna un string vacío
 */
char *concatAll(const phrasesADT ph);

/*
 * Retorna un string con todas las frases concatenadas cuyas claves estén entre
 * from y to inclusive. Si from o to son inválidas (están fuera del rango)
 * retorna NULL
 * Si no hay frases en ese rango, retorna un string vacío
 */
char *concat(const phrasesADT ph, size_t from, size_t to);

static void freePhraseList(tPhraseList phraseList) {
  if (phraseList == NULL)
    return;
  freePhraseList(phraseList->next);
  free(phraseList->phrase);
  free(phraseList);
}

static tPhraseList insertPhrase(tPhraseList phraseList, size_t key, const char *phrase) {
  if (phraseList == NULL || phraseList->key > key) {
    tPhrase *phraseNode = malloc(sizeof(*phraseNode));
    phraseNode->key = key;
    phraseNode->phrase = malloc((strlen(phrase) + 1) * sizeof(*phraseNode->phrase));
    strcpy(phraseNode->phrase, phrase);
    phraseNode->next = phraseList;
    return phraseNode;
  }
  if (phraseList->key == key) {
    phraseList->phrase = realloc(phraseList->phrase, (strlen(phrase) + 1) * sizeof(*phraseList->phrase));
    strcpy(phraseList->phrase, phrase);
    return phraseList;
  }
  phraseList->next = insertPhrase(phraseList->next, key, phrase);
  return phraseList;
}

static char *getPhrase(tPhraseList phraseList, size_t key) {
  if (phraseList == NULL || phraseList->key < key)
    return NULL;
  if (phraseList->key == key) {
    char *phrase = malloc((strlen(phraseList->phrase) + 1) * sizeof(*phrase));
    return strcpy(phrase, phraseList->phrase);
  }
  return getPhrase(phraseList->next, key);
}
