#include "tp11_12.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define NAME_SIZE 20

typedef struct relatedNode {
  struct relatedNode *tail;
  char name[NAME_SIZE + 1];
} tRelated;

typedef tRelated* tRelatedList; 

typedef struct personNode {
  struct personNode *tail;
  tRelatedList related;
  size_t relatedSize;
  char name[NAME_SIZE + 1];
} tPerson;

typedef tPerson *tPersonList;

struct socialCDT {
  tPersonList persons;
  size_t personsSize;
}; 

static void freeRelated(tRelatedList related);
static void freePersons(tPersonList persons);
static tPerson *searchPerson(tPersonList persons, const char *name);
static tPerson*insertNewPerson(const char *name, tPersonList persons, size_t *personsSize);
static tRelated *insertNewRelated(const char *name, tRelatedList related, size_t *relatedSize);
static tPersonList addPersonRec(tPersonList persons, const char *name, size_t *personsSize);
static tRelatedList addRelatedRec(tRelatedList related, const char *name, size_t *relatedSize);
static void fillRelatedVec(tRelatedList relatedList, char** relatedVec, size_t relatedSize);
static void fillPersonsVec(tPersonList personsList, char** personsVec, size_t personsSize);

socialADT newSocial() {
 socialADT soc = calloc(1, sizeof(*soc)); 
 return soc;
}

void freeSocial(socialADT soc) {
  freePersons(soc->persons);
  free(soc);
}

void addPerson(socialADT soc, const char *name) {
   soc->persons = addPersonRec(soc->persons, name, &soc->personsSize); 
}

void addRelated(socialADT soc, const char *name, const char *related) {
  tPerson *person = searchPerson(soc->persons, name);
  if (person == NULL) return;
  person->related = addRelatedRec(person->related, related, &person->relatedSize);
}

char **related(const socialADT soc, const char *person) {
  tPerson *p = searchPerson(soc->persons, person);
  if (p == NULL) 
    return calloc(1, sizeof(char *));
  char **relatedVec = malloc((p->relatedSize + 1) * sizeof(*relatedVec));
  fillRelatedVec(p->related, relatedVec, p->relatedSize);
  return relatedVec;
}

char **persons(const socialADT soc) {
  if (soc->persons == NULL) 
    return calloc(1, sizeof(void *));
  char **personsVec = malloc((soc->personsSize + 1) * sizeof(*personsVec));
  fillPersonsVec(soc->persons, personsVec, soc->personsSize);
  return personsVec;
}

static void freeRelated(tRelatedList related) {
  if (related == NULL)
    return;
  freeRelated(related->tail);
  free(related);
}

static void freePersons(tPersonList persons) {
  if (persons == NULL)
    return;
  freePersons(persons->tail);
  freeRelated(persons->related);
  free(persons);
}

static tPerson *searchPerson(tPersonList persons, const char *name) {
  if (persons == NULL)
    return NULL;
  int cmp = strcmp(persons->name, name);
  if (cmp > 0)
    return NULL;
  if (cmp < 0)
    return searchPerson(persons->tail, name);
  return persons;
}

static tPerson*insertNewPerson(const char *name, tPersonList persons, size_t *personsSize) {
    tPerson *newPerson = calloc(1, sizeof(*newPerson));
    strncpy(newPerson->name, name, NAME_SIZE);
    newPerson->tail = persons;
    *personsSize += 1;
    return newPerson;
} 

static tRelated *insertNewRelated(const char *name, tRelatedList related, size_t *relatedSize) {
    tRelated *newRelated = calloc(1, sizeof(*newRelated));
    newRelated->tail = related;
    strncpy(newRelated->name, name, NAME_SIZE);
    *relatedSize += 1;
    return newRelated;
} 

static tPersonList addPersonRec(tPersonList persons, const char *name, size_t *personsSize) {
  // Logica repetida, usar funcion
  if (persons == NULL) 
    return insertNewPerson(name, persons, personsSize);
  int cmp = strcmp(persons->name, name);
  if (cmp > 0)
    return insertNewPerson(name, persons, personsSize);
  if (cmp < 0)
    persons->tail = addPersonRec(persons->tail, name, personsSize);
  return persons;
}

static tRelatedList addRelatedRec(tRelatedList related, const char *name, size_t *relatedSize) {
  if (related == NULL)
    return insertNewRelated(name, related, relatedSize);
  int cmp = strcmp(related->name, name);
  if (cmp > 0) 
    return insertNewRelated(name, related, relatedSize);
  related->tail = addRelatedRec(related->tail, name, relatedSize);
  return related;
}

static void fillRelatedVec(tRelatedList relatedList, char** relatedVec, size_t relatedSize) {
  if (relatedSize == 0) {
    *relatedVec = NULL;
    return;
  }
  *relatedVec = malloc((NAME_SIZE + 1) * sizeof(**relatedVec));
  strcpy(*relatedVec, relatedList->name);
  fillRelatedVec(relatedList->tail, relatedVec + 1, relatedSize - 1);
}

static void fillPersonsVec(tPersonList personsList, char** personsVec, size_t personsSize) {
  if (personsSize == 0) {
    *personsVec = NULL;
    return;
  }
  *personsVec = malloc((NAME_SIZE + 1) * sizeof(**personsVec));
  strcpy(*personsVec, personsList->name);
  fillPersonsVec(personsList->tail, personsVec + 1, personsSize - 1);
}
