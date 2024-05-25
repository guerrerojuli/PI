#include "utillist.h"
#include <ctype.h>
#include <stdlib.h>

unsigned int wordLetterCount(TList list, char *word) {
  if (list == NULL || word == NULL || !*word || list->elem != *word)
    return 0;
  return 1 + wordLetterCount(list->tail, word + 1);
}

void count(char *word, int *pares, int *impares) {
  if (!*word) {
    *pares = *impares = 0;
    return;
  }
  count(word + 1, pares, impares);
  if (isdigit(*word)) {
    if ((*word - '0') % 2)
      (*impares)++;
    else
      (*pares)++;
  }
}

unsigned int contarGrupos(char *word, char c) {
  if (word == NULL || !*word)
    return 0;
  return (*word == c && *(word + 1) != c) + contarGrupos(word + 1, c);
}

unsigned int contarGruposList(TList word, char c) {
  if (word == NULL)
    return 0;
  if (word->tail == NULL)
    return word->elem == c;
  return (word->elem == c && word->tail->elem != c) + contarGruposList(word->tail, c);
}

