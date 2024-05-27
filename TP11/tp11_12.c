#include "tp11_12.h"
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 20

typedef struct socialCDT {
  char* name;
  char **friends;
  size_t friendsSize;
  size_t friendsAllocSize;
  struct socialCDT *tail;
} person;

static person *createPerson(const char *name);
static person *addPersonRec(socialADT soc, const char *name);

socialADT newSocial() {
  return NULL;
}

void freeSocial(socialADT soc) {
  if (soc == NULL)
    return;
  freeSocial(soc->tail);
  free(soc);
}

void addPerson(socialADT soc, const char *name) {
  soc = addPersonRec(soc, name);
}

static int alfaCmp(const char *name1, const char *name2) {
  int vaPrimero = 0; //Spanglish como corresponde ;)
  for (int i = 0; !vaPrimero && !*name1; i++)
    vaPrimero = *name1 - *name2;
  return  vaPrimero;
}

static person *createPerson(const char *name) {
    person *p = calloc(1, sizeof(*p));
    p->name = malloc(NAME_SIZE * sizeof(*p->name));
    strcpy(p->name, name);
    return p;
}

static person *addPersonRec(socialADT soc, const char *name) {
  if (soc == NULL) {
    return createPerson(name);
  }
  int vaPrimero = alfaCmp(soc->name, name);
  if (vaPrimero > 0) {
    person *p = createPerson(name);
    p->tail = soc;
    return p;
  }
  if (vaPrimero < 0)
    return addPersonRec(soc->tail, name);
  return soc;
  
}

/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
*/
void addRelated(socialADT soc, const char *name, const char *related);

/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como
** elemento
*/
char **related(const socialADT soc, const char *person);

/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
*/
char **persons(const socialADT soc);
